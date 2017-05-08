#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int map_width = 20;
const int map_height = 10;

// This is called a forward declaration
// It lets us tell the compiler that we will define a class Creature later
// This means we can use Creature before it is defined!
class Creature;

// An Object is something that has a position in the map
class Object {
public:
    // These are PURE VIRTUAL methods
    // They cannot be executed
    // They are only there so classes that inherit Object can implement their own versions

    Object() {
	this->posX = 0;
	this->posY = 0;
    }

    // The collide method tells what happens to a creature that collides with this object
    virtual void collide(Creature* c) = 0;

    // The image method tells what character is used to print this object
    virtual char image() = 0;

    // The hurt method is used when something tries to attack this object
    virtual void hurt(int damage) = 0;

    // The isAlive method is used to check if an object should be removed from the map
    virtual bool isAlive() = 0;

    // This method tells when a pair of objects are occupying the same position
    virtual bool isOverlapping(Object* other) {
	if (other->posX == this->posX && other->posY == this->posY) {
	    return true;
	} else {
	    return false;
	}
    }

    // This method tells when a pair of objects are touching horizontally or
    // vertically:
    //  x
    // xox
    //  x
    virtual bool isTouching(Object* other) {
	int distanceX = this->posX - other->posX;
	int distanceY = this->posY - other->posY;
	if (-1 <= distanceX && distanceX <= 1 && distanceY == 0) {
	    return true;
	} else if (-1 <= distanceY && distanceY <= 1 && distanceX == 0) {
	    return true;
	} else {
	    return false;
	}
    }

    virtual bool move(int x, int y) {
	this->posX += x;
	this->posY += y;

	if (this->posX < 0) {
	    this->posX = 0;
	}
	if (this->posY < 0) {
	    this->posY = 0;
	}
	if (this->posX >= map_width) {
	    this->posX = map_width - 1;
	}
	if (this->posY >= map_height) {
	    this->posY = map_height - 1;
	}
    }

    virtual int getX() { return posX; }
    virtual int getY() { return posY; }
    
protected:
    int posX, posY;

    // Since this class has pure virtual methods, no instances can be created!
    // To create instances, we must create a subclass that overrides said methods
};

// A Creature is a kind of object that has life points
class Creature : public Object {
public:
    Creature() : Object() {
    }

    // This method returns whether the creature is alive or not.
    // A creature is alive as long as it has more than 0 health!
    virtual bool isAlive() {
	return this->health > 0;
    }

    // This method makes the creature take damage
    virtual void hurt(int damage) {
	this->health -= damage;
    }

    // This method tells us whether a creature is a player or not
    virtual bool isPlayer() = 0;

    // Since the class Creature does not override either collide or image, it also cannot
    // be instantiated!
protected:
    int health;
};

// A Monster is a kind of creature that hurts the player when they touch
class Monster : public Creature {
public:
    Monster() : Creature() {
	this->health = 15;
    }

    virtual void collide(Creature* c) {
	if (this->isAlive() && c->isPlayer()) {
	    c->hurt(10);
	}
    }

    virtual char image() {
	return 'M';
    }

    virtual bool isPlayer() {
	return false;
    }
};

class Player : public Creature {
public:
    Player() : Creature() {
	this->health = 30;
    }

    virtual void collide(Creature* c) {
	// Players don't automatically hurt monsters when they collide with them!
    }

    virtual char image() {
	return 'P';
    }

    virtual bool isPlayer() {
	return true;
    }
};

// A Trap stays hidden until a creature steps on it
class Trap : public Object {
public:
    Trap() {
	this->discovered = false;
    }

    // Stepping on a trap hurts and reveals the trap!
    virtual void collide(Creature* c) {
	c->hurt(10);
	this->discovered = true;
    }

    // Traps are unaffected by damage!
    virtual void hurt(int damage) {
    }

    // Traps are never removed from the game
    virtual bool isAlive() {
	return true;
    }

    // A trap looks like empty space until it's stepped on!
    virtual char image() {
	if (this->discovered) {
	    return 'X';
	} else {
	    return ' ';
	}
    }
protected:
    bool discovered;
};

// This function clears the screen
void clearScreen()
{
    for (int i = 0; i < 100; i++) {
	std::cout << std::endl;
    }
}

// This function prints a list of objects to the screen
// You don't really need to understand this
void print(std::vector<Object*>& objects)
{
    for (int i = 0; i < map_width + 2; i++) {
	std::cout << '#';
    }
    std::cout << std::endl;
    
    for (int row = 0; row < map_height; row++) {
	std::vector<char> characters;
	// We fill this vector with spaces
	for (int col = 0; col < map_width; col++) {
	    characters.push_back(' ');
	}

	// We print all the objects that have the same Y coordinate as the current row
	for (int i = 0; i < objects.size(); i++) {
	    if (objects[i]->getY() == row) {
		characters[objects[i]->getX()] = objects[i]->image();
	    }
	}

	// Finally, we print the current row
	std::cout << '#';
	for (int col = 0; col < map_width; col++) {
	    std::cout << characters[col];
	}
	std::cout << '#';
	std::cout << std::endl;
    }

    for (int i = 0; i < map_width + 2; i++) {
	std::cout << '#';
    }
    std::cout << std::endl;
}

// This function picks a random X coordinate
int randomX() {
    return rand() % map_width;
}

// This function picks a random Y coordinate
int randomY() {
    return rand() % map_height;
}

// This function checks whether a string is a valid action
// Valid actions are attack, up, left, right, down, exit
bool isValidAction(std::string action) {
    if (action == "attack"
	|| action == "up"
	|| action == "down"
	|| action == "left"
	|| action == "right"
	|| action == "exit") {
	return true;
    } else {
	return false;
    }
}

int main()
{
    srand(time(NULL)); // This is used to set up the random number generator
    
    std::vector<Object*> objects;
    std::vector<Object*> deleted; // This vector stores the objects we erase from the map

    Player* player = new Player();
    objects.push_back(player);

    std::vector<Monster*> monsters;

    // We create three monsters in random positions
    for (int i = 0; i < 3; i++) {
	Monster *monster = new Monster();
	// We do this to make sure we don't create a monster on the same position as the player!
	while (monster->getX() == player->getX() && monster->getY() == player->getY()) {
	    monster->move(randomX(), randomY());
	}
	objects.push_back(monster);
	monsters.push_back(monster);
    }

    // We create a trap!
    Trap* trap = new Trap();
    while (trap->getX() == player->getX() && trap->getY() == player->getY()) {
	trap->move(randomX(), randomY());
    }
    objects.push_back(trap);
    
    bool monstersAreAlive = true;

    while (player->isAlive() && monstersAreAlive) {
	clearScreen();
	print(objects);

	std::string action;
	while (!isValidAction(action)) {
	    std::cin >> action;
	}

	if (action == "exit") {
	    break; // break exits the loop prematurely
	} else if (action == "up") {
	    player->move(0, -1);
	} else if (action == "down") {
	    player->move(0, 1);
	} else if (action == "left") {
	    player->move(-1, 0);
	} else if (action == "right") {
	    player->move(1, 0);
	} else if (action == "attack") {
	    // Attacking hurts all the adjacent monsters!
	    for (int i = 0; i < monsters.size(); i++) {
		if (player->isTouching(monsters[i])) {
		    monsters[i]->hurt(15);
		}
	    }
	}

	// We remove from the map the objects that aren't alive at the end of the turn!
	for (std::vector<Object*>::iterator i = objects.begin();
	     i != objects.end();
	     i++) {
	    Object* obj = *i;
	    if (!obj->isAlive()) {
		objects.erase(i);
		deleted.push_back(obj);
	    } else {
		if (obj != player && obj->isOverlapping(player)) {
		    obj->collide(player);
		}
		for (int m = 0; m < monsters.size(); m++) {
		    if (obj != monsters[m] && obj->isOverlapping(monsters[m])) {
			obj->collide(monsters[m]);
		    }
		}
	    }
	}

	monstersAreAlive = false;
	for (std::vector<Monster*>::iterator i = monsters.begin();
	     i != monsters.end();
	     i++) {
	    Monster* m = *i;
	    if (m->isAlive()) {
		monstersAreAlive = true;
	    }
	}
	
    }

    if (player->isAlive() && !monstersAreAlive) {
	std::cout << "You killed all the monsters! You win!" << std::endl;
    } else if (!player->isAlive()) {
	std::cout << "The monsters defeated you! You lose!" << std::endl;
    }
    std::cout << "Goodbye!" << std::endl;

    // At the end of the game, we make sure to delete everything
    for (int i = 0; i < deleted.size(); i++) {
	delete deleted[i];
    }
    for (int i = 0; i < objects.size(); i++) {
	delete objects[i];
    }
}

// Exercise suggestions
// Make the monsters move around randomly, one square at a time
// Add a new action 'wait' that allows the player to wait for one turn without moving
// Add a new type of enemy that moves two squares at a time
// Add a new type of trap that won't trigger more than once
// Give the player arrows so they can attack monsters at a distance (this is tricky!)
