#include <iostream>
#include <vector>

struct Action {
  std::string trigger; // What word will trigger the action
  std::string description;
  int type; // 1 moves the player around, 2 wins the game, 3 loses the game
  int argument; // What room to move to
};

struct Room {
  std::string description;
  std::vector<Action> actions;
};

void describeRoom(Room& r)
{
  std::cout << r.description << std::endl;
  for (int i = 0; i < r.actions.size(); i++) {
    std::cout << "You can " << r.actions[i].trigger << std::endl;
  }
}

void performAction(Action& action, int& playerLocation, bool& playerIsDead)
{
  std::cout << action.description << std::endl;
  if (action.type == 1) {
    // Move action
    playerLocation = action.argument;
  } else if (action.type == 2) {
    playerIsDead = true;
  }
}

int main()
{
  Room firstRoom;
  firstRoom.description = "You are in a plain, boring room. There is a door to the north.";

  Action firstRoom_goNorth;
  firstRoom_goNorth.description = "You go through the door";
  firstRoom_goNorth.trigger = "GO NORTH";
  firstRoom_goNorth.type = 1;
  firstRoom_goNorth.argument = 1;

  firstRoom.actions.push_back(firstRoom_goNorth);

  Room secondRoom;
  secondRoom.description = "You are in a room with a table. There is a door to the south.";

  Action secondRoom_goSouth;
  secondRoom_goSouth.description = "You go back through the door";
  secondRoom_goSouth.trigger = "GO SOUTH";
  secondRoom_goSouth.type = 1;
  secondRoom_goSouth.argument = 0;

  Action secondRoom_drinkPoison;
  secondRoom_drinkPoison.description = "You drink the poison. That was a bad idea.";
  secondRoom_drinkPoison.trigger = "DRINK POISON";
  secondRoom_drinkPoison.type = 2;

  secondRoom.actions.push_back(secondRoom_goSouth);
  secondRoom.actions.push_back(secondRoom_drinkPoison);

  std::vector<Room> world;
  world.push_back(firstRoom);
  world.push_back(secondRoom);

  int playerLocation = 0;
  bool playerIsDead = false;

  while (!playerIsDead) {
    describeRoom(world[playerLocation]);
    std::cout << "What do you do? ";

    std::vector<Action> possibleActions = world[playerLocation].actions;
    
    std::string action;
    // We need to read more than one word, we read the entire line!
    std::getline(std::cin, action);
    if (action == "EXIT GAME") {
      return 0;
    }

    bool actionWasValid = false;
    for (int i = 0; i < possibleActions.size(); i++) {
      if (action == possibleActions[i].trigger) {
	actionWasValid = true;
	// We pass the player location by reference so we can modify it
	// If your player has more information (like life points), you should pass that too
	// Even better: create a Player struct!
	// If some actions can modify the world, you should take that in mind!
	performAction(possibleActions[i], playerLocation, playerIsDead);
      }
    }

    if (!actionWasValid) {
      std::cout << "You can't do that!" << std::endl;
    }

    std::cout << std::endl;
  }

  std::cout << "You died!" << std::endl;
}
