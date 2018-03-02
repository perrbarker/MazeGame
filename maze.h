//functions header (functions.h)
#include <iostream>
#include <string>
using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


const int NUM_ROWS = 15;
const int NUM_COLS = 15;



	struct scenario{
		char GridIcon;
		string ScenarioName;
	};


	char initialArray[NUM_ROWS][NUM_COLS] = {
		{ ' ', '#', '#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '$' }, // row 0
		{ ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', ' ', '#', '_' }, // row 1
		{ '#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ' }, // row 2
		{ ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', '#', ' ' }, // row 3
		{ ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ' }, // row 4
		{ '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ' }, // row 5
		{ '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', ' ', '#', ' ', ' ', ' ' }, // row 6
		{ ' ', '#', ' ', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ' }, // row 7
		{ ' ', '#', '#', '#', ' ', '#', '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ' }, // row 8
		{ ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', ' ', '#' },  // row 9
		{ ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#' },  // row 10
		{ ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#', '#', '#', ' ', ' ' },  // row 11
		{ ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', '#' },  // row 12
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', ' ' },  // row 13
		{ '!', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }  // row 14		
	//	   0	1	 2	  3	   4	5	 6	  7	   8	9	10	 11   12   13   14  
	};
	scenario gameBoard[NUM_ROWS][NUM_COLS];


	void InitializeStructArray(char initial[][NUM_COLS], scenario array[][NUM_COLS]);
	scenario PrintGameBoard(scenario array[][NUM_COLS]);
	void ScanGameBoard(scenario array[][NUM_COLS], int& row, int& col);
	void UpdateGameBoard(scenario array[][NUM_COLS], int& row, int& col);

#endif