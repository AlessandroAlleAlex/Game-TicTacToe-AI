#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

class Game
{
public:

	Game();
	void begin(); //called by MainTicAi.cpp

private:
	//this will be true for running while loops
	bool _looping = false;

	//this will store an integer for menu selections
	int _menuSelection = 0; //stores user input

	//if your input is incorrect
	bool _error = false;

	//who's turn is it (X or O)?
	char _player1 = 'X';
	char _player2 = 'O';
	char _playerT = 'X'; //player turn: it will change between player 1 and 2.                    

	//game status
	bool _gameOver = false;

	//constant variables for multidimention arrays
	const static int _numRows = 3;
	const static int _numCols = 3;
	const static int _numSubs = 5;

	// Blocks for characters (multidimention array)
	string blocks[6][_numSubs] = {
									{ "         ", "         ", "         ", "         ", "         "}, // [0] render blank spaces          
									{ " ##   ## ", "  ## ##  ", "   ###   ", "  ## ##  ", " ##   ## "}, // [1] render X blocks
									{ "   ###   ", "  ## ##  ", " ##   ## ", "  ## ##  ", "   ###   "}, // [2] render O blocks
									{ ".##...##.", "..##.##..", "...###...", "..##.##..", ".##...##."}, // [3] render X blocks with dots (when won)
									{ "...###...", "..##.##..", ".##...##.", "..##.##..", "...###..."}, // [4] render O blocks with dots (when won)
									{ " #####   ", " ##  ##  ", " ##   ## ", " ##  ##  ", " #####   "}, // [5] render D blocks when draw happens
	};

    // Database
    char rowSelection = 0;
    int colSelection = 0;
    int data[_numRows][_numCols] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } }; //multidimention array to render the board

    //menu fuction
    void title();
    void mainMenu();
    void pvpMenu(); //player vs player
    void pvcMenu(); //player vs computer
    void choosePlayerMenu();
    void endMenu(int &id);
    int exit();

    //update functions
    void updatePVP();
    void updatePVCEasy();
    void updatePVCHard();
    void processInput();
    int checkData();
    int randomGenerator(int min, int max);

    // render functions
    string block(int y, int x, int z);
    void renderBoard();

};