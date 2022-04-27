//
//  era8366_hw13_v3.cpp
//  Tandon_Bridge_Program
//
//  Created by Eric Acerno on 4/15/22.
/*  CH15# 9: The goal for this Project is to create a simple two-dimensional predator-prey simulation.

In this simulation the prey are ants and the predators are doodlebugs:
    -These critters live in a world composed of a 20 × 20 grid of cells.
    -Only one critter may occupy a cell at a time.
    -The grid is enclosed, so a critter is not allowed to move off the edges of the world.
    -Time is simulated in time steps. Each critter performs some action every time step.

A) The ants behave according to the following model:
    -Move. Every time step, randomly try to move up, down, left, or right. If the neighboring cell in the selected direction is occupied or would move the ant off the grid, then the ant stays in the current cell.

    -Breed. If an ant survives for three time steps, then at the end of the time step (that is; after moving) the ant will breed. This is simulated by creat-ing a new ant in an adjacent (up, down, left, or right) cell that is empty. If there is no empty cell available, then no breeding occurs. Once an off-spring is produced, an ant cannot produce an offspring until three more time steps have elapsed.

B) The doodlebugs behave according to the following model:
    -Move. Every time step, if there is an adjacent ant (up, down, left, or right), then the doodlebug will move to that cell and eat the ant. Otherwise, the doodlebug moves according to the same rules as the ant. Note that a doodlebug cannot eat other doodlebugs.

    -Breed. If a doodlebug survives for eight time steps, then at the end of the time step it will spawn off a new doodlebug in the same manner as the ant.

    -Starve. If a doodlebug has not eaten an ant within the last three time steps, then at the end of the third time step it will starve and die. The doodlebug should then be removed from the grid of cells.

    -During one turn, all the doodlebugs should move before the ants do.
 -------------------------------------------------------------------------
 1) Write a program to implement this simulation and draw the world using ASCII characters of “o” for an ant and “X” for a doodlebug or "-" for an empty space.
 2) Create a class named Organism that encapsulates basic _data common to both ants and doodlebugs.
        2a) This class should have a virtual function named move that is defined in the derived classes of Ant and Doodlebug.
        2b) You may need additional _data structures to keep track of which critters have moved.

 3) Initialize the world with 5 doodlebugs and 100 ants. After each time step, prompt the user to press Enter to move to the _next time step. You should see a cyclical pattern between the population of predators and prey, although random perturbations may lead to the elimination of one or both species.

 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
const int GRID_SIZE = 20;
//int representing moves in all directions
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
//number of time steps to breed or starve (depending on organism type)
const int DOODLE_BREED_TIME = 8;
const int ANT_BREED_TIME = 3;
const int STARVE_TIME = 3;

//parent class to Ant and DoodleBug
class Organism{
private:
    int x_axis;
    int y_axis;
    int _id;
    int time_step;
    bool hasMoved;
    bool hasEaten;
public:
    Organism(int x, int y, int id){
        this->x_axis = x;
        this->y_axis = y;
        this->_id = id;
        this->time_step = 0;
        this->hasMoved = false;
        this->hasEaten = false;
    }
    virtual ~Organism() {}

    virtual void move(Organism* grid[GRID_SIZE][GRID_SIZE]) = 0;

    virtual char getType()const = 0;

    virtual void breed(Organism* grid[GRID_SIZE][GRID_SIZE], int&) = 0;

    virtual void starve(Organism* grid[GRID_SIZE][GRID_SIZE]){
        if (getTimeStep() == STARVE_TIME){
            if (getIfEaten() == false){
                delete grid[get_X_axis()][get_Y_axis()];
                grid[get_X_axis()][get_Y_axis()] = NULL;
            }
        }
    }

    // Getters
    int get_X_axis()const{
        return x_axis;
    }

    int get_Y_axis()const{
        return y_axis;
    }

    int getID()const{
        return _id;
    }

    int getTimeStep()const{
        return time_step;
    }

    bool getIfMoved()const{
        return hasMoved;
    }

    bool getIfEaten()const{
        return hasEaten;
    }

    // Setters

    void setX(int x){
        this-> x_axis = x;
    }

    void setY(int y){
        this-> y_axis = y;
    }

    void setID(int id){ this->_id = id; }

    void setTimeStep(int timeStep){
        this->time_step = timeStep;
    }

    void setIfMoved(bool condition){
        this->hasMoved = condition;
    }

    void setIfEaten(bool condition){
        this->hasEaten = condition;
    }
};

//child class DoodleBug of parent Organism
class DoodleBug: public Organism{
private:
    char d_type;
public:
    DoodleBug(int x, int y, int id): Organism(x, y, id), d_type('X') {}
    virtual ~DoodleBug(){}
    char getType()const{
        return d_type;
    }
    void move(Organism* grid[GRID_SIZE][GRID_SIZE]);
    void breed(Organism* grid[GRID_SIZE][GRID_SIZE], int& dbID);
    void starve(Organism* grid[GRID_SIZE][GRID_SIZE]);
};
/*
 Function for randomizing a direction where Up=1, Down=2, Left=3, Right=4
 */
void DoodleBug::move(Organism* grid[GRID_SIZE][GRID_SIZE]){
    int direction = rand() % 4 + 1;
    //DIRECTIONS FOR RANDOMIZED MOVE UP (1); limit to row 1 (X axis, index 0)
    if (direction == UP && get_X_axis() - 1 >= 0 && getIfMoved() == false){
        if (grid[get_X_axis() - 1][get_Y_axis()] == NULL){
            int newX = get_X_axis() - 1;
            int newY = get_Y_axis();
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];
            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new DoodleBug(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            return;
        }
    }
    //DIRECTIONS FOR RANDOMIZED MOVE DOWN (2); limit to row 20 (X axis, index 19)
    if (direction == DOWN && get_X_axis()+1 <= GRID_SIZE - 1 && getIfMoved() == false){
        if (grid[get_X_axis()+1][get_Y_axis()] == NULL){
            int newX = get_X_axis()+1;
            int newY = get_Y_axis();
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new DoodleBug(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            return;
        }
        else if (grid[get_X_axis() + 1][get_Y_axis()]->getType() == 'o'){
            int newX = get_X_axis() + 1;
            int newY = get_Y_axis();
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];

            delete grid[newX][newY];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new DoodleBug(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            grid[newX][newY]->setIfEaten(true);
            return;
        }
    }
    //DIRECTIONS FOR RANDOMIZED MOVE LEFT (3); limit to column 1 (Y axis, index 0)
    if (direction == LEFT && get_Y_axis()-1 >= 0 && getIfMoved() == false){
        if (grid[get_X_axis()][get_Y_axis()-1] == NULL){
            int newX = get_X_axis();
            int newY = get_Y_axis()-1;
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];

            delete grid[newX][newY];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new DoodleBug(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            return;
        }
        else if (grid[get_X_axis()][get_Y_axis()-1]->getType() == 'o'){
            int newX = get_X_axis();
            int newY = get_Y_axis()-1;
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];

            delete grid[newX][newY];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new DoodleBug(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            grid[newX][newY]->setIfEaten(true);
            return;
        }
    }
    //DIRECTIONS FOR RANDOMIZED MOVE RIGHT (4); limit to column 20 (Y axis, index 19)
    if (direction == RIGHT && get_Y_axis() + 1 <= GRID_SIZE - 1 && getIfMoved() == false){
        if (grid[get_X_axis()][get_Y_axis()+1] == NULL){
            int newX = get_X_axis();
            int newY = get_Y_axis()+1;
            int newID = getID();
            int newTimeStep = getTimeStep() + 1;
            delete grid[get_X_axis()][get_Y_axis()];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new DoodleBug(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            return;
        }
        else if (grid[get_X_axis()][get_Y_axis() + 1]->getType() == 'o'){
            int newX = get_X_axis();
            int newY = get_Y_axis()+1;
            int newID = getID();
            int newTimeStep = getTimeStep() + 1;
            delete grid[get_X_axis()][get_Y_axis()];

            delete grid[newX][newY];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new DoodleBug(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            grid[newX][newY]->setIfEaten(true);
            return;
        }
    }
    setTimeStep(getTimeStep()+1);
}
//Depending on direction, make sure it's valid direction
//swap x, y with that point by creating a new object and marking that object as one that moved
void DoodleBug::breed(Organism* grid[GRID_SIZE][GRID_SIZE], int& dbID){
    setTimeStep(0);
    if (grid[get_X_axis()-1][get_Y_axis()] == NULL){
        ++dbID;
        grid[get_X_axis()-1][get_Y_axis()] = new DoodleBug(get_X_axis()-1, get_Y_axis(), dbID);
    }
    else if (grid[get_X_axis()+1][get_Y_axis()] == NULL){
        ++dbID;
        grid[get_X_axis()+1][get_Y_axis()] = new DoodleBug(get_X_axis()+1, get_Y_axis(), dbID);
    }
    else if (grid[get_X_axis()][get_Y_axis()-1] == NULL){
        ++dbID;
        grid[get_X_axis()][get_Y_axis()-1] = new DoodleBug(get_X_axis(), get_Y_axis()-1, dbID);
    }

    else if (grid[get_X_axis()][get_Y_axis()+1] == NULL){
        ++dbID;
        grid[get_X_axis()][get_Y_axis()+1] = new DoodleBug(get_X_axis(), get_Y_axis()+1, dbID);
    }
}

//Implement after Ant child class
void DoodleBug::starve(Organism* grid[GRID_SIZE][GRID_SIZE]){
    if (getTimeStep() == STARVE_TIME){
        if (getIfEaten() == false){
            delete grid[get_X_axis()][get_Y_axis()];
            grid[get_X_axis()][get_Y_axis()] = NULL;
        }
    }
}

//child class Ant of parent Organism
class Ant: public Organism{
private:
    char a_type;
public:
    Ant(int x, int y, int id): Organism(x, y, id), a_type('o'){}
    virtual ~Ant(){}
    char getType()const{ return a_type; }
    void move(Organism* grid[GRID_SIZE][GRID_SIZE]);
    void breed(Organism* grid[GRID_SIZE][GRID_SIZE], int&);
};

void Ant::move(Organism* grid[GRID_SIZE][GRID_SIZE]){
    int direction = rand() % 4 + 1;
    if (direction == 1 && get_X_axis()-1 >= 0 && getIfMoved() == false){
        if (grid[get_X_axis()-1][get_Y_axis()] == NULL){
            int newX = get_X_axis()-1;
            int newY = get_Y_axis();
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new Ant(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            return;
        }
    }
    if (direction == 2 && get_X_axis()+1 <= GRID_SIZE - 1 && getIfMoved() == false){
        if (grid[get_X_axis()+1][get_Y_axis()] == NULL){
            int newX = get_X_axis()+1;
            int newY = get_Y_axis();
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new Ant(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            return;
        }
    }
    if (direction == LEFT && get_Y_axis()-1 >= 0 && getIfMoved() == false){
        if (grid[get_X_axis()][get_Y_axis()-1] == NULL){
            int newX = get_X_axis();
            int newY = get_Y_axis()-1;
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new Ant(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            return;
        }
    }
    if (direction == 4 && get_Y_axis()+1 <= GRID_SIZE - 1 && getIfMoved() == false){
        if (grid[get_X_axis()][get_Y_axis()+1] == NULL){
            int newX = get_X_axis();
            int newY = get_Y_axis()+1;
            int newID = getID();
            int newTimeStep = getTimeStep()+1;
            delete grid[get_X_axis()][get_Y_axis()];

            grid[get_X_axis()][get_Y_axis()] = NULL;
            grid[newX][newY] = new Ant(newX, newY, newID);
            grid[newX][newY]->setTimeStep(newTimeStep);
            grid[newX][newY]->setIfMoved(true);
            return;
        }
    }
    setTimeStep(getTimeStep()+1);
}

void Ant::breed(Organism* grid[GRID_SIZE][GRID_SIZE], int& antID){
    setTimeStep(0);
    if (grid[get_X_axis()-1][get_Y_axis()] == NULL){
        ++antID;
        grid[get_X_axis()-1][get_Y_axis()] = new Ant(get_X_axis()-1, get_Y_axis(), antID);
    }
    else if (grid[get_X_axis()+1][get_Y_axis()] == NULL){
        ++antID;
        grid[get_X_axis()+1][get_Y_axis()] = new Ant(get_X_axis()+1, get_Y_axis(), antID);
    }
    else if (grid[get_X_axis()][get_Y_axis()-1] == NULL){
        ++antID;
        grid[get_X_axis()][get_Y_axis()-1] = new Ant(get_X_axis(), get_Y_axis()-1, antID);
    }

    else if (grid[get_X_axis()][get_Y_axis()+1] == NULL){
        ++antID;
        grid[get_X_axis()][get_Y_axis()+1] = new Ant(get_X_axis(), get_Y_axis()+1, antID);
    }
}

void initialize_grid(Organism* grid[GRID_SIZE][GRID_SIZE]){
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            grid[i][j] = NULL;
        }
    }
}

void render(Organism* grid[GRID_SIZE][GRID_SIZE]){
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            if (grid[i][j] == NULL){
                std::cout << "-" << " ";
            }
            else if (grid[i][j]->getType() == 'X'){
                std::cout << "X" << " ";
            }
            else if (grid[i][j]->getType() == 'o'){
                std::cout << "o" << " ";
            }
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int countTheDoodles(Organism* grid[GRID_SIZE][GRID_SIZE]){
    int count = 0;
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            if (grid[i][j] != NULL){
                if (grid[i][j]->getType() == 'D'){
                    count++;
                }
            }
        }
    }
    return count;
}

int countAnts(Organism* grid[GRID_SIZE][GRID_SIZE]){
    int count = 0;
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            if (grid[i][j] != NULL){
                if (grid[i][j]->getType() == 'o'){
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    Organism* grid[GRID_SIZE][GRID_SIZE];
    initialize_grid(grid);
    std::srand(time(NULL));

    // Create 5 doodlebugs on the heap
    int dbCount = 0;
    int dbID = 0;
    while (dbCount < 5){
        // Get a random x and y coordinate for the grid
        int randomX = rand() % GRID_SIZE;
        int randomY = rand() % GRID_SIZE;
        if (grid[randomX][randomY] == NULL){
            grid[randomX][randomY] = new DoodleBug(randomX, randomY, dbID);
            dbCount++;
            dbID++;
        }
    }
    // Create 100 ants on the heap
    int antCount = 0;
    int antID = 100;
    while (antCount < 100){
        int randomX = rand() % GRID_SIZE;
        int randomY = rand() % GRID_SIZE;
        if (grid[randomX][randomY] == NULL){
            grid[randomX][randomY] = new Ant(randomX, randomY, antID);
            antCount++;
            antID++;
        }
    }
    std::cout << "Intial Grid" << std::endl;
    render(grid);
    bool flag = true;

    int step = 0;
    while (flag){
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.ignore();
        ++step;
        std::cout << "******Time Step: " << step << "******" << std::endl;
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                if (grid[i][j] != NULL){
                    if (grid[i][j]->getType() == 'D' && !grid[i][j]->getIfMoved()){
                        grid[i][j]->move(grid);
                    }
                }
            }
        }
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                if (grid[i][j] != NULL){
                    if (grid[i][j]->getType() == 'o' && !grid[i][j]->getIfMoved()){
                        grid[i][j]->move(grid);
                    }
                }
            }
        }
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                if (grid[i][j] != NULL){
                    if (grid[i][j]->getType() == 'D' || grid[i][j]->getType() == 'o'){
                        grid[i][j]->setIfMoved(false);
                    }
                }
            }
        }
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                if (grid[i][j] != NULL){
                    if (grid[i][j]->getType() == 'D'){
                        grid[i][j]->starve(grid);
                    }
                }
            }
        }
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                if (grid[i][j] != NULL){
                    if (grid[i][j]->getType() == 'D' && grid[i][j]->getTimeStep() == DOODLE_BREED_TIME){
                        grid[i][j]->breed(grid, dbID);
                    }
                }
            }
        }
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                if (grid[i][j] != NULL){
                    if (grid[i][j]->getType() == 'o' && grid[i][j]->getTimeStep() == 3){
                        grid[i][j]->breed(grid, antID);
                    }
                }
            }
        }
        render(grid);
        if (countAnts(grid) == 400 || countTheDoodles(grid) == 400){
            flag = false;
        }
    }
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            delete grid[i][j];
            grid[i][j] = NULL;
        }
    }

    return 0;
}
