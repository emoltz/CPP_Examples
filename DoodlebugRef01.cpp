
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
class Organism;

//Global Constants
const int GRID_SIZE = 20;
const int INIT_ANTS = 100;
const int INIT_DOODLE = 5;
const int ANT_BREED_TIME = 3;
const int DOODLE_BREED_TIME = 8;
const int DOODLE_STARVE_TIME = 3;
const int DOODLE_NUM = 1;
const int ANT_NUM = 2;
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;

class Environment {
    friend class Organism;
    friend class Doodle;
    friend class Ant;

public:
    Environment();
    ~Environment();
    Organism* getOrganismAt(int x, int y);
    void setOrganismAt(int x, int y, Organism *org);
    void printGrid();
    void moveOneTimeStep();

private:
    Organism* grid[GRID_SIZE][GRID_SIZE];
};

class Organism {
    friend class Environment;

public:
    Organism();
    Organism(Environment *world, int x, int y);
    virtual void move() = 0;
    virtual int getType() = 0;
    virtual void breed() = 0;
    virtual bool starve() = 0;

protected:
    bool moved;
    int x, y;
    int breedCounter;
    Environment *world;
};

//Default constructor - Creates an empty 20 x 20 grid
Environment::Environment() {
    for (auto &row: grid) {
        for (auto &col: row)
            col = nullptr;
    }
}

//Destructor
Environment::~Environment() {
    for (auto &row: grid) {
        for (auto col: row)
            if (col != nullptr)
                delete (col);
    }
}

//getOrganismAt - Gets bug at (x,y) coord if x and y is valid
Organism* Environment::getOrganismAt(int x, int y) {
    if ((x >= 0) && (x < GRID_SIZE) && (y >= 0) && (y < GRID_SIZE))
        return grid[x][y];
}

//setOrganismAt - Sets bug as bug at coord (x,y)
void Environment::setOrganismAt(int x, int y, Organism *organism) {
    if ((x >= 0) && (x < GRID_SIZE) && (y >= 0) && (y < GRID_SIZE))
        grid[x][y] = organism;
}

//printGrid - Prints out grid of organisms
void Environment::printGrid() {
    cout << endl;
    for (auto &row : grid) {
        for (auto &col: row) {
            if (col == nullptr)
                cout << "-";
            else if (col->getType() == ANT_NUM)
                cout << "o";
            else
                cout << "X";
        }
        cout << endl;
    }
}

//moveOneTimeStep - move time forward one step for all organisms
void Environment::moveOneTimeStep() {
    //set all organisms moved flag to false
    for (auto &row: grid) {
        for (auto &col: row) {
            if (col != nullptr)
                col->moved = false;
        }
    }

    //Move all Doodle bugs
    for (auto &row: grid) {
        for (auto &col: row) {
            if ((col != nullptr) && (col->getType() == DOODLE_NUM) && (!col->moved)) {
                col->moved = true;
                col->move();
            }
        }
    }

    //Move all Ants
    for (auto &row: grid) {
        for (auto &col: row) {
            if ((col != nullptr) && (col->getType() == ANT_NUM) && (!col->moved)) {
                col->moved = true;
                col->move();
            }
        }
    }

    //Delete all Doodle Bugs that starved
    for (auto &row: grid) {
        for (auto &col: row) {
            if ((col != nullptr) && (col->getType() == DOODLE_NUM) && (col->starve())) {
                delete col;
                col = nullptr;
            }
        }
    }

    //Check if organisms can breed
    for (auto &row: grid) {
        for (auto &col: row) {
            if ((col != nullptr) && (col->moved))
                col->breed();
        }
    }
}

//Organism default constructor
Organism::Organism() {
    moved = false;
    breedCounter = 0;
    world = nullptr;
    x = 0;
    y = 0;
}

//Constructor
Organism::Organism(Environment *world, int x, int y) {
    moved = false;
    breedCounter = 0;
    this->world = world;
    this->x = x;
    this->y = y;
    world->setOrganismAt(x, y, this);
}

class Ant: public Organism {
    friend class Environment;

public:
    Ant();
    Ant(Environment *world, int x, int y);
    void move();
    int getType();
    void breed();
    bool starve();
};

//Ant default constructor
Ant::Ant(): Organism() {}

//Ant constructor
Ant::Ant(Environment *world, int x, int y): Organism(world, x, y) {}

//move - move ant randomly in a direction
void Ant::move() {
    int direction = rand() % 4;

    //Move up
    if (direction == UP) {
        if ((y > 0) && (world->getOrganismAt(x, y - 1) == nullptr)) {
            world->setOrganismAt(x, y - 1, this);
            world->setOrganismAt(x, y, nullptr);
            y--;
        }
    }
        //Move down
    else if (direction == DOWN) {
        if ((y < GRID_SIZE - 1) && (world->getOrganismAt(x, y + 1) == nullptr)) {
            world->setOrganismAt(x, y + 1, this);
            world->setOrganismAt(x, y, nullptr);
            y++;
        }
    }
        //Move left
    else if (direction == LEFT) {
        if ((x > 0) && (world->getOrganismAt(x - 1, y) == nullptr)) {
            world->setOrganismAt(x - 1, y, this);
            world->setOrganismAt(x, y, nullptr);
            x--;
        }
    }
        //Move right
    else if ((x < GRID_SIZE - 1) && (world->getOrganismAt(x + 1, y) == nullptr)) {
        world->setOrganismAt(x + 1, y, this);
        world->setOrganismAt(x, y, nullptr);
        x++;
    }
}

//getType - return type ID of an ant
int Ant::getType() {return ANT_NUM;}

//breed - attempt to breed ant if ant has survived 3 ticks
void Ant::breed() {
    breedCounter++;
    if (breedCounter == ANT_BREED_TIME) {
        breedCounter = 0;

        //Try to breed up, down, left, and right
        if ((y > 0) && (world->getOrganismAt(x, y - 1) == nullptr)) {
            new Ant(world, x, y - 1);
        }
        else if ((y < GRID_SIZE - 1) && (world->getOrganismAt(x, y + 1) == nullptr)) {
            new Ant(world, x, y + 1);
        }
        else if ((x > 0) && (world->getOrganismAt(x - 1, y) == nullptr)) {
            new Ant(world, x - 1, y);
        }
        else if ((x < GRID_SIZE - 1) && (world->getOrganismAt(x + 1, y) == nullptr)) {
            new Ant(world, x + 1, y);
        }
    }
}

//starve - Always returns false since ants can't starve
bool Ant::starve() {
    return false;
}

class Doodle : public Organism {
    friend class Environment;

public:
    Doodle();
    Doodle(Environment *world, int x, int y);
    void move();
    int getType();
    void breed();
    bool starve();

private:
    int starveTicks;
    bool eat();
};

//Default constructor
Doodle::Doodle() : Organism() {
    starveTicks = 0;
}

//Constructor
Doodle::Doodle(Environment *world, int x, int y) : Organism(world, x, y) {
    starveTicks = 0;
}

//eat - helper function - doodle bug tries eat an ant if possible
bool Doodle::eat() {
    if ((y > 0) && (world->getOrganismAt(x, y - 1) != nullptr) &&
        (world->getOrganismAt(x, y - 1)->getType() == ANT_NUM)) {
        delete (world->grid[x][y - 1]);
        world->setOrganismAt(x, y - 1, this);
        world->setOrganismAt(x, y, nullptr);
        starveTicks = 0;
        y--;
        return true;
    }
    else if ((y < GRID_SIZE - 1) && (world->getOrganismAt(x, y + 1) != nullptr) &&
             (world->getOrganismAt(x, y + 1)->getType() == ANT_NUM)) {
        delete (world->grid[x][y + 1]);
        world->setOrganismAt(x, y + 1, this);
        world->setOrganismAt(x, y, nullptr);
        starveTicks = 0;
        y++;
        return true;
    }
    else if ((x > 0) && (world->getOrganismAt(x - 1, y) != nullptr) &&
             (world->getOrganismAt(x - 1, y)->getType() == ANT_NUM)) {
        delete (world->grid[x - 1][y]);
        world->setOrganismAt(x - 1, y, this);
        world->setOrganismAt(x, y, nullptr);
        starveTicks = 0;
        x--;
        return true;
    }
    else if ((x < GRID_SIZE - 1) && (world->getOrganismAt(x + 1, y) != nullptr) &&
             (world->getOrganismAt(x + 1, y)->getType() == ANT_NUM)) {
        delete (world->grid[x + 1][y]);
        world->setOrganismAt(x + 1, y, this);
        world->setOrganismAt(x, y, nullptr);
        starveTicks = 0;
        x++;
        return true;
    }
    return false;
}

//move - move doodlebug up, down, left, or right
void Doodle::move() {
    if (!eat()) {

        int dir = rand() % 4;
        if (dir == UP) {
            if ((y > 0) && (world->getOrganismAt(x, y - 1) == nullptr)) {
                world->setOrganismAt(x, y - 1, this);
                world->setOrganismAt(x, y, nullptr);
                y--;
            }
        }
        else if (dir == DOWN) {
            if ((y < GRID_SIZE - 1) && (world->getOrganismAt(x, y + 1) == nullptr)) {
                world->setOrganismAt(x, y + 1, this);
                world->setOrganismAt(x, y, nullptr);
                y++;
            }
        }
        else if (dir == LEFT) {
            if ((x > 0) && (world->getOrganismAt(x - 1, y) == nullptr)) {
                world->setOrganismAt(x - 1, y, this);
                world->setOrganismAt(x, y, nullptr);
                x--;
            }
        }
        else if ((x < GRID_SIZE - 1) && (world->getOrganismAt(x + 1, y) == nullptr)) {
            world->setOrganismAt(x + 1, y, this);
            world->setOrganismAt(x, y, nullptr);
            x++;
        }
        starveTicks++;
    }
}

//getType - return type id of a Doodle bug
int Doodle::getType() {return DOODLE_NUM;}

//breed - attempt to breed doodle bug after 8 ticks
void Doodle::breed() {
    breedCounter++;
    if (breedCounter == DOODLE_BREED_TIME) {
        breedCounter = 0;
        //Try to breed up, down, left, right
        if ((y > 0) && (world->getOrganismAt(x, y - 1) == nullptr)) {
            new Doodle(world, x, y - 1);
        }
        else if ((y < GRID_SIZE - 1) && (world->getOrganismAt(x, y + 1) == nullptr)) {
            new Doodle(world, x, y + 1);
        }
        else if ((x > 0) && (world->getOrganismAt(x - 1, y) == nullptr)) {
            new Doodle(world, x - 1, y);
        }
        else if ((x < GRID_SIZE - 1) && (world->getOrganismAt(x + 1, y) == nullptr)) {
            new Doodle(world, x + 1, y);
        }
    }
}

//starve - return whether doodle bug has starved
bool Doodle::starve() {return (starveTicks > DOODLE_STARVE_TIME);}

int main() {
    //Generate seed and world
    srand(time(nullptr));
    Environment world;

    //Randomly create 100 ants
    int antCount = 0;
    while (antCount < INIT_ANTS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (world.getOrganismAt(x, y) == nullptr) {
            antCount++;
            new Ant(&world, x, y);
        }
    }

    //Randomly create 5 doodlebugs
    int doodleCount = 0;
    while (doodleCount < INIT_DOODLE) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (world.getOrganismAt(x, y) == nullptr) {
            doodleCount++;
            new Doodle(&world, x, y);
        }
    }

    string str;
    while (true) {
        world.printGrid();
        world.moveOneTimeStep();
        cout << endl << "Press Enter to move forward one step in time." << endl;
        getline(cin, str);
    }
    return 0;
}