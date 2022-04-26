#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Grid;
class Organism;
class Ant;
class Doodlebug;

const int gridSize = 20;
const int startAntCount = 100;
const int startDoodlebugCount = 5;
const int antBreedTime = 3;
const int doodlebugBreedTime = 8;
const int doodlebugStarveTime = 3;
const int upMove = 1;
const int downMove = 2;
const int leftMove = 3;
const int rightMove = 4;
const char antChar = 'O';
const char doodlebugChar = 'X';
const int antType = 1;
const int doodlebugType = 2;

int getRandomNumber(int start, int end);

class Grid{
    friend class Organism;
    friend class Ant;
    friend class Doodlebug;

public:
    Grid();
    void initializeGrid();
    void displayGrid();
    void moveOneTimeStep();

private:
    Organism* grid[gridSize][gridSize];
    int count;
};

class Organism{
public:
    Organism(): xCoordinate(0), yCoordinate(0), stepsUntilBreed(0), gridptr(nullptr), count(0){};
    Organism(int x, int y, Grid* gridptr);
    virtual void move();
    virtual void breed() = 0;
    virtual int getType() = 0;
    virtual bool shouldStarve() {return false;}
    void pickRandomMove(vector<int> possibleMoves, int& xCoord, int& yCoord) const;
    void updateCoordinateFromMove(int &x, int &y, int move) const;
    bool isValidCoordinate(int x, int y) const;
    vector<int> findSurroundingEmptyCells(int x, int y) const;

protected:
    int xCoordinate;
    int yCoordinate;
    int stepsUntilBreed;
    int count;
    Grid* gridptr;
};

class Ant: public Organism{
public:
    Ant(): Organism(){};
    Ant(int x, int y, Grid* gridptr);
    int getType(){return antType;}
    void breed();
    bool shouldStarve() {return false;}
};

class Doodlebug: public Organism{
public:
    Doodlebug(): Organism(){}
    Doodlebug(int x, int y, Grid* gridptr);
    void move();
    void breed();
    bool shouldStarve(){return stepsUntilBreed == 0;}
    int getType(){return doodlebugType;}
    vector<int> findSurroundingAnts(int x, int y) const;

private:
    int stepsUntilStarve;
};

Grid::Grid(){
    count = 0;
    // Create an empty grid with null pointers
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            grid[i][j] = nullptr;
        }
    }
}

void Grid::initializeGrid(){
    // Initialize doodlebugs randomly
    for (int i = 0; i < startDoodlebugCount; i++)
    {
        int x = rand() % gridSize + 1;
        int y = rand() % gridSize + 1;
        if (grid[x][y] == nullptr)
        {
            grid[x][y] = new Doodlebug(x, y, this);
        }
    }

    // Initialize ants randomly
    for (int i = 0; i < startAntCount; i++)
    {
        int x = rand() % gridSize + 1;
        int y = rand() % gridSize + 1;
        if (grid[x][y] == nullptr)
        {
            grid[x][y] = new Ant(x, y, this);
        }
    }
}

void Grid::displayGrid(){
    for (int x = 0; x < gridSize; x++)
    {
        for (int y = 0; y < gridSize; y++)
        {
            if (grid[x][y] == nullptr)
            {
                cout<<'-';
            }
            else if (grid[x][y]->getType() == antType )
            {
                cout<<antChar;
            }
            else
            {
                cout<<doodlebugChar;
            }
            cout<<"  ";
        }
        cout<<endl;
    }
}

void Grid::moveOneTimeStep(){
    count++;
    // Move Doodlebugs first
    for (int x = 0; x < gridSize; x++){
        for (int y = 0; y < gridSize; y++){
            if (grid[x][y] != nullptr && grid[x][y]->getType() == doodlebugType){
                grid[x][y]->move();
            }
        }
    }

    // Move ants
    for (int x = 0; x < gridSize; x++){
        for (int y = 0; y < gridSize; y++){
            if (grid[x][y] != nullptr && grid[x][y]->getType() == antType){
                grid[x][y]->move();
            }
        }
    }

    // Breed organisms that are allowed to breed
    for (int x = 0; x < gridSize; x++){
        for (int y = 0; y < gridSize; y++){
            if (grid[x][y] != nullptr){
                grid[x][y]->breed();
            }
        }
    }

    // Starve organisms set to starve
    for (int x = 0; x < gridSize; x++){
        for (int y = 0; y < gridSize; y++){
            if (grid[x][y] != nullptr && grid[x][y]->shouldStarve()){
                grid[x][y] = nullptr;
            }
        }
    }
}

Organism::Organism(int x, int y, Grid* gridptr){
    this->gridptr = gridptr;
    this->xCoordinate = x;
    this->yCoordinate = y;
    this->stepsUntilBreed = 0;
    this->count = gridptr->count;
}

void Organism::pickRandomMove(vector<int> possibleMoves, int& xCoord, int& yCoord) const{
    int randomNum = getRandomNumber(0, possibleMoves.size() - 1);
    int move = possibleMoves[randomNum];
    int newX = xCoordinate;
    int newY = yCoordinate;
    updateCoordinateFromMove(newX, newY, move);
}

vector<int> Organism::findSurroundingEmptyCells(int x, int y) const {
    vector<int> emptyCells;
    int newXCoord, newYCoord;

    // up == 1 and right == 4
    for (int move = upMove; move <= rightMove; move++)
    {
        newXCoord = x;
        newYCoord = y;
        updateCoordinateFromMove(newXCoord, newYCoord, move);
        if (isValidCoordinate(newXCoord, newYCoord) && gridptr->grid[newXCoord][newYCoord] == nullptr)
        {
            emptyCells.push_back(move);
        }
    }

    return emptyCells;
}

// Validate that a coordinate isn't outside of the bounds of the grid
bool Organism::isValidCoordinate(int x, int y) const {
    if (x < 0 || x >= gridSize || y < 0 || y >= gridSize){
        return false;
    }
    return true;
}

void Organism::move(){
    if (count == gridptr->count) return;
    count++;
    stepsUntilBreed--;
    int newX = xCoordinate, newY = yCoordinate;
    int randomNum = getRandomNumber(upMove, rightMove);
    updateCoordinateFromMove(newX, newY, randomNum);
    if (isValidCoordinate(newX, newY)){
        if (gridptr->grid[newX][newY] == nullptr){
            gridptr->grid[xCoordinate][yCoordinate] = nullptr;
            gridptr->grid[newX][newY] = this;
            xCoordinate = newX;
            yCoordinate = newY;
        }
    }
}

// Given a move (up/down/left/right), update the appropriate coordinate
void Organism::updateCoordinateFromMove(int& x, int& y, int move) const {
    switch (move)
    {
        case upMove:
            y++;
            break;
        case downMove:
            y--;
            break;
        case leftMove:
            x--;
            break;
        case rightMove:
            x++;
            break;
        default:
            break;
    }
}

Doodlebug::Doodlebug(int x, int y, Grid* gridptr): Organism(x, y, gridptr){
    stepsUntilBreed = doodlebugBreedTime;
    stepsUntilStarve = doodlebugStarveTime;
}

void Doodlebug::breed(){
    vector<int> validMoves = findSurroundingEmptyCells(xCoordinate, yCoordinate);
    if (validMoves.size() != 0){
        int newX = xCoordinate, newY = yCoordinate;
        pickRandomMove(validMoves, newX, newY);
        gridptr->grid[newX][newY] = new Doodlebug(newX, newY, gridptr);
        stepsUntilBreed = doodlebugBreedTime;
    }
}

void Doodlebug::move(){
    // Check if we already moved this Doodlebug
    if (count == gridptr->count) return;
    vector<int> ants = findSurroundingAnts(xCoordinate, yCoordinate);
    if (ants.size() == 0){
        Organism::move();
        stepsUntilStarve--;
        return;
    }
    count++;
    stepsUntilStarve = doodlebugStarveTime;
    int newX = xCoordinate, newY = yCoordinate;
    pickRandomMove(ants, newX, newY);
    gridptr->grid[newX][newY] = this;
    gridptr->grid[xCoordinate][yCoordinate] = nullptr;
    xCoordinate = newX;
    yCoordinate = newY;
}

vector<int> Doodlebug::findSurroundingAnts(int x, int y) const{
    vector<int> antLocations;
    int newX, newY;
    for (int move = upMove; move <= rightMove; move++){
        newX = x;
        newY = y;
        updateCoordinateFromMove(newX, newY, move);
        if (!isValidCoordinate(newX, newY))
        {
            return antLocations;
        }

        if (gridptr->grid[newX][newY] != nullptr && gridptr->grid[newX][newY]->getType() == antType)
            antLocations.push_back(move);
    }
    return antLocations;

}

Ant::Ant(int x, int y, Grid* gridptr): Organism(x, y, gridptr){
    stepsUntilBreed = antBreedTime;
}

void Ant::breed(){
    vector<int> validMoves = findSurroundingEmptyCells(xCoordinate, yCoordinate);
    if (validMoves.size() != 0){
        int newX = xCoordinate, newY = yCoordinate;
        pickRandomMove(validMoves, newX, newY);
        gridptr->grid[newX][newY] = new Ant(newX, newY, gridptr);
        stepsUntilBreed = antBreedTime;
    }
}

int getRandomNumber(int start, int end){
    return rand() % (end - start + 1) + start;
}

int main(){
    srand(time(NULL));

    Grid grid;
    grid.initializeGrid();

    cout<<"Starting the Ant vs Doodlebug Game!"<<endl;
    grid.displayGrid();
    cout<<"Press enter to simulate one time step. Enter anything else to end the game."<<endl;

    while (cin.get() == '\n')
    {
        grid.moveOneTimeStep();
        grid.displayGrid();
        cout<<"Press enter to simulate one time step. Enter anything else to end the game."<<endl;
    }

    cout<<"Ending the game. Thanks for playing!"<<endl;

    return 0;
}
