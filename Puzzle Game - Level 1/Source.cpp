// enable console input and output (iostream = input and output stream)
#include <iostream>

// use standard namespace by default to remove the requirement of calling the class prior using an element of the std namespace
using namespace std;

// check if the game has been won
bool gameIsNotWon = true;

enum keyPos {
	left,
	right,
	center,
	default
};

enum rooms {
	entrance,
	pantry,
	kitchen
};

// victoryCondition[0] is for the pantry
// vicotryCondition[1] is for the kitchen
// check if 'currentCondition' == 'victoryCondition' when attemting to open the door
keyPos victoryCondition[2] = {keyPos::right, keyPos::left};

keyPos currentCondition[2] = {keyPos::left, keyPos::center};

int main(void) {

	/*
		room one is the entrance room

		room two is the pantry

		room three is the kitchen
	*/

	rooms room = rooms::entrance;

	// main game loop
	do {
		system("pause");
		system("cls");
		/*
			the following if statement checks the room the player is in
		*/

		// check if the player is in the entrance room
		if (room == rooms::entrance) {
			// room one screen output
			cout << "Room: Entrance" << endl;
			cout << "--------------" << endl;

			cout << "You're in the entrance hallway. The door that brought you in from the outside is gone." << endl;
			cout << "In front of you there is a door that leads deeper into the house. To your left is an entranceway into the pantry.To your right is an entranceway into the kitchen." << endl;
			cout << "Room actions:" << endl;
			cout << "1: Try to open the door" << endl;
			cout << "2 : Go through the left entryway" << endl;
			cout << "3 : Go through the right entryway" << endl;

			int choice = 0;
			cout << "Your selection: ";
			cin >> choice;

			switch (choice) {
			case 1:
				if (currentCondition[0] == victoryCondition[0] && currentCondition[1] == victoryCondition[1]) {
					cout << "The door is unlocked and you can continue on to the rest of the game" << endl;
					gameIsNotWon = false;
				}
				else {
					cout << "The door remains stubbornly locked!" << endl;
				}
				break;
			case 2:
				room = rooms::pantry;
				break;
			case 3:
				room = rooms::kitchen;
				break;
			default:
				cout << "Unrecognized input" << endl;
			}
		}

		// checks if the player is in the pantry
		else if (room == rooms::pantry) {
			cout << "Room: Pantry" << endl;
			cout << "------------" << endl;
			cout << "You're in the pantry that contains the usual foodstuffs. In front of you is a silver lock with 3 positions: left, center and right. Behind you is the doorway to the entranceway." << endl;
			cout << "Room actions:" << endl;


			cout << "The silver lock is currently set to the ";

			if (currentCondition[0] == keyPos::left) {
				cout << "left position";
			} else if (currentCondition[0] == keyPos::center) {
				cout << "center position";
			} else if (currentCondition[0] == keyPos::right) {
				cout << "right position";
			}
			cout << endl;



			cout << "1: Turn the silver lock to the left position" << endl;
			cout << "2: Turn the silver lock to the right position" << endl;
			cout << "3: Turn the silver lock to the center position" << endl;
			cout << "4: Don't change the position! Return to entranceway" << endl;

			int choice;
			cout << "Your selection: ";
			cin >> choice;

			switch (choice) {
			case 1:
				currentCondition[0] = keyPos::left;
				break;
			case 2:
				currentCondition[0] = keyPos::right;
				break;
			case 3:
				currentCondition[0] = keyPos::center;
				break;
			case 4:
				room = rooms::entrance;
				break;
			default:
				cout << endl << "Unrecognized Input" << endl;
			}

		}

		//checks if the player is in the kitchen
		else if (room == rooms::kitchen) {
			cout << "Room: Kitchen" << endl;
			cout << "-------------" << endl;
			cout << "You're in a kitchen with many modern appliances. In front of you is gold lock with 3 positions: left, center and right. Behind you is the doorway to the entranceway." << endl;
			cout << "Room actions:" << endl;
			cout << "The gold lock is currently set to the ";

			if (currentCondition[1] == keyPos::left) {
				cout << "left ";
			}
			else if (currentCondition[1] == keyPos::center) {
				cout << "center ";
			}
			else if (currentCondition[1] == keyPos::right) {
				cout << "right ";
			}
			cout << "position" << endl;

			cout << "1: Turn the gold lock to the left position" << endl;
			cout << "2: Turn the gold lock to the right position" << endl;
			cout << "3: Turn the gold lock to the center position" << endl;
			cout << "4: Don't change the position! Return to entranceway" << endl;

			int choice;

			cout << "Your selection: ";
			cin >> choice;

			switch (choice) {
			case 1:
				currentCondition[1] = keyPos::left;
				break;
			case 2:
				currentCondition[1] = keyPos::right;
				break;
			case 3:
				currentCondition[1] = keyPos::center;
				break;
			default:
				room = rooms::entrance;
				break;
			}
		}


	} while (gameIsNotWon);
	
	system("cls");
	system("clear");
	cout << "Congratulations, you have completed level 1!" << endl;
	
	// output something useful here perhaps?
	
	return 0;
}
