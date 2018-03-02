// functions.cpp
#include <iostream>
#include <string>
#include <conio.h>
#include "Classes.h"
using namespace std;


const int NUM_ROWS = 15;
const int NUM_COLS = 15;

int i, j = 0;
int playerHP = 30;
string playerWeapon;
bool exitMaze = false;

	struct scenario{
		char GridIcon;
		string ScenarioName;			
	};

	


	void InitializeStructArray(char initial[][NUM_COLS], scenario array[][NUM_COLS]){		// Initializes board for new game
		for (i = 0; i < NUM_ROWS; ++i){
			for (j = 0; j < NUM_COLS; ++j){
				array[i][j].GridIcon = initial[i][j];
			}
		}
		array[7][0].ScenarioName = "Crackhead";						// insert call for scenario assignment function using randomizer
		array[i][j].ScenarioName = "Ghost Robot";
		array[i][j].ScenarioName = "Drywall Golem";
		array[i][j].ScenarioName = "Enchanted Switchblade";
		array[i][j].ScenarioName = "Potion"; 
		array[0][0].ScenarioName = "Key"; 
		
		return;
	}
	
	scenario PrintGameBoard(scenario array[][NUM_COLS]){			// Prints the gameboard
		cout << "------A-maze-ing-Adventure!-----" << endl;
		cout << "--------------------------------" << endl;
		for (i = 0; i < NUM_ROWS; ++i){
			if (i == 14){
				cout << " ";
			}
			else {
				cout << "|";
			}
			for (j = 0; j < NUM_COLS; ++j){
				cout << array[i][j].GridIcon << array[i][j].GridIcon;
			}
			if (i == 0){
				cout << " ";
			}
			else {
				cout << "|";
			}
			cout << endl;
		}
		cout << "--------------------------------" << endl;

		return array[0][0];
	}

	void ScanGameBoard(scenario array[][NUM_COLS], int& row, int& col){				// scans for player position; integrate scenario structs later (i.e. treasures, enemy battles, etc.)
		for (i = 0; i < NUM_ROWS; ++i){
			for (j = 0; j < NUM_COLS; ++j){
				if ((array[i][j].GridIcon != '#') && (array[i][j].GridIcon != '_') && (array[i][j].GridIcon != '$')){ //This is for random placement of baddies and items in the maze (Perry)
					if (array[i][j].GridIcon == '!'){
						row = i;
						col = j;
						cout << "Player Position: (" << row << ", " << col << ") ";
						cout << array[i][j].ScenarioName << endl;
						cout << "Player HP: " << playerHP << endl;
						cout << "Player's Weapon: " << playerWeapon << endl;
					}
					
					if (array[0][0].GridIcon == '!'){
						array[1][14].GridIcon = ' ';
					}
					if (array[0][14].GridIcon == '!'){  //Ends Game  
						exitMaze = true;              //FIXME: Doesnt exit program     
					
					}
					if (array[i][j].ScenarioName == "Potion"){
						playerHP += 5;
					}
					if (array[i][j].GridIcon == '$'){
						cout << "Congrats! You reached the treasure!";
					}
					if (array[i][j].ScenarioName == "Crackhead"){				//test for HP reduction
						/*EnemyData enemy1;
						enemy1.SetName("Crackhead"); //FIXME: This tests the damage with the Classes but doesnt work properly
						enemy1.SetLvl(1);
						playerHP = playerHP - enemy1.GetDmg();				//insert swtich statement for function calls of boss battles, treasure, etc.
						break; */
					}
					if (array[i][j].ScenarioName == "Enchanted Switchblade"){	// test for playerWeapon variable update
						playerWeapon = "Switchblade";
						array[i][j].ScenarioName = " ";
					}
					
				}			
			}
		}
		return;
	}



	void UpdateGameBoard(scenario array[][NUM_COLS], int& row, int& col){			// checks movements
		char move;
		bool endOfTurn = false;

		if (exitMaze == true){
			cout << "You have found the treasure. Play Again?" << endl;
		}
		while (exitMaze == false){
			cout << "Where would you like to move? Enter w, a, s, or d: " << endl;
			while (!_kbhit()){}
			move = _getch();
			if (move == 'w' && ((array[row - 1][col].GridIcon == ' ') || (array[row - 1][col].GridIcon == '$'))){		// Moves up
				array[row][col].GridIcon = ' ';
				array[row - 1][col].GridIcon = '!';
				if (move == 'w' && array[row - 1][col].GridIcon == '$'){
					array[row - 1][col].GridIcon = ' ';
				}
				endOfTurn = true;
				break;
			}

			if (move == 's' && array[row + 1][col].GridIcon == ' '){		// Moves down	
				array[row][col].GridIcon = ' ';
				array[row + 1][col].GridIcon = '!';
				endOfTurn = true;
				break;
			}
			if (move == 'a' && array[row][col - 1].GridIcon == ' ' && (col - 1) >= 0){		// Moves left	
				array[row][col].GridIcon = ' ';
				array[row][col - 1].GridIcon = '!';
				endOfTurn = true;
				break;
			}
			if (move == 'd' && array[row][col + 1].GridIcon == ' ' && (col + 1) <= 14){		// Moves right
				array[row][col].GridIcon = ' ';
				array[row][col + 1].GridIcon = '!';
				endOfTurn = true;
				break;
			}
			else {
				cout << "Invalid move. Try Again." << endl;
				endOfTurn = false;
				continue;
			}
		}
		return;
	}








