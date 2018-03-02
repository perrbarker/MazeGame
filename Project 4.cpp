// project 4.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include "maze.h"
#include <fstream>
#include <sstream>

using namespace std;


char playerMove;
bool playerWins = false;
int x, y = 0;		// x and y coordinates
char temp;
int r = 0;
int c = 0;
ifstream inFS;
string userInput = "a";
int userInt = 0;




int main()
{
	cout << "Upload Maze file?" << endl;
	cout << "Press Y for Yes, N for No." << endl;
	cin >> userInput;
	if (userInput == "Y"){
		cout << "Which file? 1 2 or 3?" << endl;
		cin >> userInt;
		if (userInt == 1){
			inFS.open("importmaze1.txt");
			if (!inFS.is_open()){
			cout << "Can't find file.";
			system ("Pause");
			return 1;
		}
			for (r = 0; r < NUM_ROWS; ++r){
				for (c = 0; c < NUM_COLS; ++c){
					inFS >> temp;
					if (temp == '_'){
						temp = ' ';
					}
					initialArray[r][c] = temp;
				}
			}
			inFS.close();
		}
	}

	InitializeStructArray(initialArray, gameBoard);			//Initializes array of structs(gameBoard) with initialArray
			
	while (playerWins == false){
		PrintGameBoard(gameBoard);
		cout << endl;
		ScanGameBoard(gameBoard, x, y);
		cout << endl;
		UpdateGameBoard(gameBoard, x, y);
		system("cls");
		if (initialArray[0][14] == '!'){

			playerWins = true;
		}
	}
	


	return 0;
}

