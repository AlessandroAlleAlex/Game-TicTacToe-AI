#include "Game.h"

Game::Game()
{
	_looping = true;
}

void Game::begin()
{
	while (_looping) //starts the main game loop
	{
		//reset game
		if (_gameOver) //if _gameOver is true
		{
			_player1 = 'X';
			_player2 = 'O';
			_playerT = 'X';
			_gameOver = false;
			for (int y = 0; y < 3; y++)
			{
				for (int x = 0; x < 3; x++)
				{
					data[y][x] = 0;
				}
			}
		}

		mainMenu();

		if (_menuSelection == 1)
		{
			//Player vs Player
			while (_looping) 
			{
				pvpMenu();
				if (_menuSelection == 1)
				{
					while (_looping)
					{
						updatePVP();
					}
				}
				else if (_menuSelection == -1)
				{
					//return
					_looping = false;
				}
				else 
				{
					//incorrect input: just loop this menu
				}

			}
			_looping = true;
		}
		else if (_menuSelection == 2)
		{
			while (_looping)
			{
				pvcMenu();

				if (_menuSelection == 1)
				{
					//Easy mode
					choosePlayerMenu();
					while (_looping)
					{
						updatePVCEasy();
					}
					if (!_gameOver)
					{
						_looping = true;
					}
				}
				else if (_menuSelection == 2)
				{
					//Medium mode
					choosePlayerMenu();
					while (_looping)
					{
						int decider = randomGenerator(0, 1);

						if (decider == 0)
						{
							updatePVCEasy();
						}
						if (decider == 1)
						{
							updatePVCHard();
						}
					}
					if (!_gameOver)
					{
						_looping = true;
					}
				}
				else if (_menuSelection == 3)
				{
					//Hard mode
					choosePlayerMenu();
					while (_looping)
					{
						updatePVCHard();
					}
					if (!_gameOver)
					{
						_looping = true;
					}
				}
				else if (_menuSelection == -1)
				{
					//Return
					_looping = false;
				}
				else 
				{
					//Incorrect input: just loop this menu 
				}		
				
			}
			_looping = true;
		}
		else if (_menuSelection == -1)
		{
			//exit game
			exit();
			_looping = false;
		}
		else
		{
			// Incorrect input: just loop this menu.
		}
	}
}

void Game::title()
{
	cout << "|==============================================================================|\n";
	cout << "|                   Tic Tac Toe Game with AI implementation                    |\n";
	cout << "|                   FINAL PROJECT FOR THE CLASS --> CIS 27                     |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                    by                                        |\n";
	cout << "|                               ALESSANDRO LIU                                 |\n";
	cout << "|                                2018 Spring                                   |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
}

void Game::mainMenu()
{
	title();

	cout << "|==============================================================================|\n";
	cout << "|                                MAIN MENU                                     |\n";
	cout << "|                                                                              |\n";
	cout << "| ENTER 1. PLAYER VS PLAYER                                                    |\n";
	cout << "| ENTER 2. PLAYER VS COMPUTER (AI)                                             |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "| ENTER -1. TO QUIT                                                            |\n";
	cout << "|                                                                              |\n";
	cout << "| Enter your choise: ";
	cin >> _menuSelection;
}

void Game::pvpMenu() //PLAYER VS PLAYER METHOD
{
	title();

	cout << "|==============================================================================|\n";
	cout << "|                            PLAYER VS PLAYER                                  |\n";
	cout << "|                                                                              |\n";
	cout << "| ENTER 1. TO PLAY THE GAME                                                    |\n";
	cout << "| ENTER -1. TO GO BACK                                                         |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "| Enter your choise: ";                          
	cin >> _menuSelection;
}

void Game::pvcMenu() //PLAYER VS COMPUTER METHOD
{
	title();

	cout << "|==============================================================================|\n";
	cout << "|                          PLAYER VS COMPUTER (AI)                             |\n";
	cout << "|                                                                              |\n";
	cout << "| ENTER 1. EASY MODE                                                           |\n";
	cout << "| ENTER 2. MEDIUM MODE                                                         |\n";
	cout << "| ENTER 3. DIFFICULT MODE                                                      |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "| ENTER -1. TO GO BACK                                                         |\n";
	cout << "|                                                                              |\n";
	cout << "| Enter your choise: "; 
	cin >> _menuSelection;
}

void Game::choosePlayerMenu()
{
	title();

	cout << "|==============================================================================|\n";
	cout << "|                            CHOOSE HOW TO PLAY                                |\n";
	cout << "|                                                                              |\n";
	cout << "| EENTER 1. TO GO FIRST                                                        |\n";
	cout << "| ENTER 2. TO GO SECOND                                                        |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "|                                                                              |\n";
	cout << "| ENTER -1. TO GO BACK                                                         |\n";
	cout << "|                                                                              |\n";
	cout << "| Enter your choise: ";
	cin >> _menuSelection;

	if (_menuSelection == 1)
	{
		_player1 = 'X';
		_player2 = 'O';
	}
	if (_menuSelection == 2)
	{
		_player1 = 'O';
		_player2 = 'X';
	}
	if (_menuSelection == -1)
	{
		_looping = false;
	}
}

void Game::endMenu(int &id)
{
	_gameOver = true;
	if (id == 3)
	{
		_playerT = 'D';
	}

	cout << endl;
	cout << "|==============================================================================|"<< endl;
	cout << "|                                   RESULT                                     |"<< endl;
	cout << "|==============================================================================|"<< endl;
	cout << endl;

	renderBoard();

	cout <<"|Enter -1. to go back";
	cin >> _menuSelection;

	_looping = false;

}

int Game::exit()
{
	return 0;
}

void Game::updatePVP()
{
	cout << endl;
	cout << "|==============================================================================|"<< endl;
	cout << "|                               Player vs Player                               |"<< endl;
	cout << "|==============================================================================|"<< endl;
	cout << endl;

	renderBoard();
	if (_error)
	{
		cout << "Incorrect user input!                          " << endl;
		_error = false;
	}

	cout << "Select your row: ";
	cin >> rowSelection;
	cout << "Select your column: ";
	cin >> colSelection;
	processInput();
}

void Game::updatePVCEasy()
{
	cout << endl;
	cout << "|==============================================================================|"<< endl;
	cout << "|                        Player vs Computer (EASY MODE)                        |"<< endl;
	cout << "|==============================================================================|"<< endl;
	cout << endl;

	renderBoard();
	if (_error)
	{
		cout << "Incorrect user input!                          " << endl;
		_error = false;
	}

	if (_playerT == _player1)
	{
		cout << "Select your row: ";
		cin >> rowSelection;
		cout << "Select your column: ";
		cin >> colSelection;

	}

	if (_playerT == _player2)
	{
		int i = 0;
		int yCor = randomGenerator(0, 2);
		int xCor = randomGenerator(1, 3);

		if (yCor == 0)
		{
			rowSelection = 'a';
		}
		if (yCor == 1)
		{
			rowSelection = 'b';
		}
		if (yCor == 2)
		{
			rowSelection = 'c';
		}

		colSelection = xCor;

		cout << "Select your row:    " << rowSelection << "                      ." << endl;
		cout << "Select your column: " << colSelection << "                      ." << endl;
	}

	processInput();
}

void Game::updatePVCHard()
{
	cout << endl;
	cout << "|==============================================================================|"<< endl;
	cout << "|                        Player vs Computer (HARD MODE)                        |"<< endl;
	cout << "|==============================================================================|"<< endl;
	cout << endl;

	renderBoard();
	if (_error)
	{
		cout << "Incorrect user input!                          " << endl;
		_error = false;
	}

	if (_playerT == _player1)
	{
		cout << "Select your row: ";
		cin >> rowSelection;
		cout << "Select your column: ";
		cin >> colSelection;

	}

	if (_playerT == _player2)
	{
		
		int yCor = randomGenerator(0, 2);
		int xCor = randomGenerator(1, 3);

		if (yCor == 0)
		{
			rowSelection = 'a';
		}
		if (yCor == 1)
		{
			rowSelection = 'b';
		}
		if (yCor == 2)
		{
			rowSelection = 'c';
		}

		colSelection = xCor;

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// OVERRIDE TO BLOCK THE HUMAN PLAYER (PREVENT HUMAN FROM WINNING)
		//ROW 1
		if (data[1][1] == 0) //strategy 1
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[1][1] == 1 && (data[0][0] == 2 || data[2][2] == 2 || data[0][2] == 2 || data[2][0] == 2) && data[1][2] == 0) //strategy 2
		{
			rowSelection = 'b';
			colSelection = 3;
		}
				
		if (data[0][1] == 1 && data[0][2] == 1 && data[0][0] != 2)
		{
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 1 && data[0][2] == 1 && data[0][1] != 2)
		{
			rowSelection = 'a';
			colSelection = 2;
		}
		if (data[0][0] == 1 && data[0][1] == 1 && data[0][2] != 2)
		{
			rowSelection = 'a';
			colSelection = 3;
		}

		//ROW 2
		if (data[1][1] == 1 && data[1][2] == 1 && data[1][0] != 2)
		{
			rowSelection = 'b';
			colSelection = 1;
		}
		if (data[1][0] == 1 && data[1][2] == 1 && data[1][1] != 2)
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[1][0] == 1 && data[1][1] == 1 && data[1][2] != 2)
		{
			rowSelection = 'b';
			colSelection = 3;
		}

		//ROW 3
		if (data[2][1] == 1 && data[2][2] == 1 && data[2][0] != 2)
		{
			rowSelection = 'c';
			colSelection = 1;
		}
		if (data[2][0] == 1 && data[2][2] == 1 && data[2][1] != 2)
		{
			rowSelection = 'c';
			colSelection = 2;
		}
		if (data[2][0] == 1 && data[2][1] == 1 && data[2][2] != 2)
		{
			rowSelection = 'c';
			colSelection = 3;
		}
		//---------------------------------------------------------------------
		//column 1
		if (data[1][0] == 1 && data[2][0] == 1 && data[0][0] != 2)
		{
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 1 && data[2][0] == 1 && data[1][0] != 2)
		{
			rowSelection = 'b';
			colSelection = 1;
		}
		if (data[0][0] == 1 && data[1][0] == 1 && data[2][0] != 2)
		{
			rowSelection = 'c';
			colSelection = 1;
		}

		//column 2
		if (data[1][1] == 1 && data[2][1] == 1 && data[0][1] != 2)
		{
			rowSelection = 'a';
			colSelection = 2;
		}
		if (data[0][1] == 1 && data[2][1] == 1 && data[1][1] != 2)
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][1] == 1 && data[1][1] == 1 && data[2][1] != 2)
		{
			rowSelection = 'c';
			colSelection = 2;
		}

		//column 3
		if (data[1][2] == 1 && data[2][2] == 1 && data[0][2] != 2)
		{
			rowSelection = 'a';
			colSelection = 3;
		}
		if (data[0][2] == 1 && data[2][2] == 1 && data[1][2] != 2)
		{
			rowSelection = 'b';
			colSelection = 3;
		}
		if (data[0][2] == 1 && data[1][2] == 1 && data[2][2] != 2)
		{
			rowSelection = 'c';
			colSelection = 3;
		}
		//---------------------------------------------------------------------

		//Diagonal 1
		if (data[2][2] == 1 && data[1][1] == 1 && data[0][0] != 2)
		{
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 1 && data[2][2] == 1 && data[1][1] != 2)
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][0] == 1 && data[1][1] == 1 && data[2][2] != 2)
		{
			rowSelection = 'c';
			colSelection = 3;
		}

		//Diagonal 2
		if (data[2][0] == 1 && data[1][1] == 1 && data[0][2] != 2)
		{
			rowSelection = 'a';
			colSelection = 3;
		}
		if (data[2][0] == 1 && data[0][2] == 1 && data[1][1] != 2)
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][2] == 1 && data[1][1] == 1 && data[0][2] != 2)
		{
			rowSelection = 'c';
			colSelection = 1;
		}
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// NOW OVERRIDE TO WIN (JUST NEED TO MODIFY IF STATMENTS)
		//ROW 1
		if (data[0][1] == 2 && data[0][2] == 2 && data[0][0] != 1)
		{
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 2 && data[0][2] == 2 && data[0][1] != 1)
		{
			rowSelection = 'a';
			colSelection = 2;
		}
		if (data[0][0] == 2 && data[0][1] == 2 && data[0][2] != 1)
		{
			rowSelection = 'a';
			colSelection = 3;
		}

		//ROW 2
		if (data[1][1] == 2 && data[1][2] == 2 && data[1][0] != 1)
		{
			rowSelection = 'b';
			colSelection = 1;
		}
		if (data[1][0] == 2 && data[1][2] == 2 && data[1][1] != 1)
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[1][0] == 2 && data[1][1] == 2 && data[1][2] != 1)
		{
			rowSelection = 'b';
			colSelection = 3;
		}

		//ROW 3
		if (data[2][1] == 2 && data[2][2] == 2 && data[2][0] != 1)
		{
			rowSelection = 'c';
			colSelection = 1;
		}
		if (data[2][0] == 2 && data[2][2] == 2 && data[2][1] != 1)
		{
			rowSelection = 'c';
			colSelection = 2;
		}
		if (data[2][0] == 2 && data[2][1] == 2 && data[2][2] != 1)
		{
			rowSelection = 'c';
			colSelection = 3;
		}

		//---------------------------------------------------------------------
		//column 1
		if (data[1][0] == 2 && data[2][0] == 2 && data[0][0] != 1)
		{
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 2 && data[2][0] == 2 && data[1][0] != 1)
		{
			rowSelection = 'b';
			colSelection = 1;
		}
		if (data[0][0] == 2 && data[1][0] == 2 && data[2][0] != 1)
		{
			rowSelection = 'c';
			colSelection = 1;
		}

		//column 2
		if (data[1][1] == 2 && data[2][1] == 2 && data[0][1] != 1)
		{
			rowSelection = 'a';
			colSelection = 2;
		}
		if (data[0][1] == 2 && data[2][1] == 2 && data[1][1] != 1)
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][1] == 2 && data[1][1] == 2 && data[2][1] != 1)
		{
			rowSelection = 'c';
			colSelection = 2;
		}

		//column 3
		if (data[1][2] == 2 && data[2][2] == 2 && data[0][2] != 1)
		{
			rowSelection = 'a';
			colSelection = 3;
		}
		if (data[0][2] == 2 && data[2][2] == 2 && data[1][2] != 1)
		{
			rowSelection = 'b';
			colSelection = 3;
		}
		if (data[0][2] == 2 && data[1][2] == 2 && data[2][2] != 1)
		{
			rowSelection = 'c';
			colSelection = 3;
		}

		//---------------------------------------------------------------------
		//Diagonal 1
		if (data[2][2] == 2 && data[1][1] == 2 && data[0][0] != 1)
		{
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 2 && data[2][2] == 2 && data[1][1] != 1)
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][0] == 2 && data[1][1] == 2 && data[2][2] != 1)
		{
			rowSelection = 'c';
			colSelection = 3;
		}

		//Diagonal 2
		if (data[2][0] == 2 && data[1][1] == 2 && data[0][2] != 1)
		{
			rowSelection = 'a';
			colSelection = 3;
		}
		if (data[2][0] == 2 && data[0][2] == 2 && data[1][1] != 1)
		{
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][2] == 2 && data[1][1] == 2 && data[0][2] != 1)
		{
			rowSelection = 'c';
			colSelection = 1;
		}
		//END OVERRIDING
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		cout << "Select your row:    " << rowSelection << "                      ." << endl;
		cout << "Select your column: " << colSelection << "                      ." << endl;
	}

	processInput();
}


void Game::processInput()
{
	//check if input coordinates are correct
	if (rowSelection != 'a' && rowSelection != 'A' && rowSelection != 'b' && rowSelection != 'B' && rowSelection != 'c' && rowSelection != 'C' )
	{
		_error = true;
	}
	else if (colSelection < 1 || colSelection > 3)
	{
		_error = true;
	}

	//if input is valid --> start processing input
	if (!_error) //if _error == false
	{
		int user = 0;
		int yCor = 0;
		int xCor = 0;

		if (_playerT == 'X')
		{
			user = 1; 
		}

		if (_playerT == 'O')
		{
			user = 2;
		}

		//Row
		if (rowSelection == 'a' || rowSelection == 'A')
		{
			yCor = 0;
		}

		if (rowSelection == 'b' || rowSelection == 'B')
		{
			yCor = 1;
		}

		if (rowSelection == 'c' || rowSelection == 'C')
		{
			yCor = 2;
		}

		//Column
		if (colSelection == 1)
		{
			xCor = 0;
		}

		if (colSelection == 2)
		{
			xCor = 1;
		}

		if (colSelection == 3)
		{
			xCor = 2;
		}

		if (data[yCor][xCor] > 0) //error if the field is already taken (0 == empty)
		{
			_error = true;
		}

		if (!_error)
		{
			data[yCor][xCor] = user; //which can either be 1 or 2
		}

		//check board data
		int id = checkData(); //check if there is 3 in a row, colun, ot diagonal.
		if (id == 1 || id == 2 || id == 3)
		{
			endMenu(id);
		}

		//switch players
		if (!_error && _playerT =='X' && _looping)
		{
			_playerT = 'O';
		}
		else if (!_error && _playerT =='O' && _looping)
		{
			_playerT = 'X';
		}
	}
}

int Game::checkData()
{
	//----------------------------------------------------------------------------------------------------
	//Process Player X (Player 1) --> if won, render the winning X character with dots 
	//rows
	if (data[0][0] == 1 && data[0][1] == 1 && data[0][2] == 1)
	{
		data[0][0] = 3;
		data[0][1] = 3;
		data[0][2] = 3;
		return 1;
	}
	if (data[1][0] == 1 && data[1][1] == 1 && data[1][2] == 1)
	{
		data[1][0] = 3;
		data[1][1] = 3;
		data[1][2] = 3;
		return 1;
	}
	if (data[2][0] == 1 && data[2][1] == 1 && data[2][2] == 1)
	{
		data[2][0] = 3;
		data[2][1] = 3;
		data[2][2] = 3;
		return 1;
	}
	//columns
	if (data[0][0] == 1 && data[1][0] == 1 && data[2][0] == 1)
	{
		data[0][0] = 3;
		data[1][0] = 3;
		data[2][0] = 3;
		return 1;
	}
	if (data[0][1] == 1 && data[1][1] == 1 && data[2][1] == 1)
	{
		data[0][1] = 3;
		data[1][1] = 3;
		data[2][1] = 3;
		return 1;
	}
	if (data[0][2] == 1 && data[1][2] == 1 && data[2][2] == 1)
	{
		data[0][2] = 3;
		data[1][2] = 3;
		data[2][2] = 3;
		return 1;
	}
	//diagonals "\"
	if (data[0][0] == 1 && data[1][1] == 1 && data[2][2] == 1)
	{
		data[0][0] = 3;
		data[1][1] = 3;
		data[2][2] = 3;
		return 1;
	}
	//diagonals "/"
	if (data[0][2] == 1 && data[1][1] == 1 && data[2][0] == 1)
	{
		data[0][2] = 3;
		data[1][1] = 3;
		data[2][0] = 3;
		return 1;
	}

	//----------------------------------------------------------------------------------------------------
	//process palyer O
	//rows
	if (data[0][0] == 2 && data[0][1] == 2 && data[0][2] == 2)
	{
		data[0][0] = 4;
		data[0][1] = 4;
		data[0][2] = 4;
		return 2;
	}
	if (data[1][0] == 2 && data[1][1] == 2 && data[1][2] == 2)
	{
		data[1][0] = 4;
		data[1][1] = 4;
		data[1][2] = 4;
		return 2;
	}
	if (data[2][0] == 2 && data[2][1] == 2 && data[2][2] == 2)
	{
		data[2][0] = 4;
		data[2][1] = 4;
		data[2][2] = 4;
		return 2;
	}
	//columns
	if (data[0][0] == 2 && data[1][0] == 2 && data[2][0] == 2)
	{
		data[0][0] = 4;
		data[1][0] = 4;
		data[2][0] = 4;
		return 2;
	}
	if (data[0][1] == 2 && data[1][1] == 2 && data[2][1] == 2)
	{
		data[0][1] = 4;
		data[1][1] = 4;
		data[2][1] = 4;
		return 2;
	}
	if (data[0][2] == 2 && data[1][2] == 2 && data[2][2] == 2)
	{
		data[0][2] = 4;
		data[1][2] = 4;
		data[2][2] = 4;
		return 2;
	}
	//diagonals "\"
	if (data[0][0] == 2 && data[1][1] == 2 && data[2][2] == 2)
	{
		data[0][0] = 4;
		data[1][1] = 4;
		data[2][2] = 4;
		return 2;
	}
	//diagonals "/"
	if (data[0][2] == 2 && data[1][1] == 2 && data[2][0] == 2)
	{
		data[0][2] = 4;
		data[1][1] = 4;
		data[2][0] = 4;
		return 2;
	}

	//Run through board to see if any spaces are left
	// if there is one space left then fill it.
	int acc = 0;
	int com = 9;

	for (int Rows = 0; Rows < 3; Rows++)
	{
		for (int Columns = 0; Columns < 3; Columns++)
		{
			if (data[Rows][Columns] > 0)
			{
				acc++;
			}
		}
	}

	if (acc == com)
	{
		return 3;
	}
	
	return 0;
	
}

int Game::randomGenerator(int min, int max)
{
	//random generator
	//generates pseudo-random numbers
	static default_random_engine randomGenerator(time(NULL)); //from standard library

	//produces random integers in a range [a,b] where each possible value 
	//has an equal likelihood of being produced. This is the distribution 
	//function that appears on many trivial random processes (like the result of rolling a die).
	uniform_int_distribution<int> integer(min, max); //from standard library

	return integer(randomGenerator);
}

string Game::block(int y, int x, int z)
{
	//render multidimention arrays
	if (data[y][x] == 0) //y for rows and x for columns
	{
		return blocks[0][z];
	}
	else if (data[y][x] == 1)
	{
		return blocks[1][z];
	}
	else if (data[y][x] == 2)
	{
		return blocks[2][z];
	}
	else if (data[y][x] == 3)
	{
		return blocks[3][z];
	}
	else if (data[y][x] == 4)
	{
		return blocks[4][z];
	}
}

void Game::renderBoard()
{
	for (int row = 0; row < _numRows; row++) //_numRows is const of 3
	{
		if (row == 0)
		{
			cout << "                      1         2         3                           " << endl;
		}
		for (int sub = 0; sub < _numSubs; sub++) //_numSubs is const of 3
		{
			if (sub == 2 && row == 0)
			{
				cout << "               A  ";
			}
			else if (sub == 3 && row == 0)
			{
				cout << "|=========|       ";

			}
			else if (sub == 4 && row == 0)
			{
				cout << "|  PLAYER |       ";

			}
			else if (sub == 0 && row == 1)
			{
				if (_playerT == 'X')
				{
					cout << "|" << blocks[1][0] << "|       ";
				}
				if (_playerT == 'O')
				{
					cout << "|" << blocks[2][0] << "|       ";
				}
				if (_playerT == 'D')
				{
					cout << "|" << blocks[5][0] << "|       ";
				}
			}
			else if (sub == 1 && row == 1)
			{
				if (_playerT == 'X')
				{
					cout << "|" << blocks[1][1] << "|       ";
				}
				if (_playerT == 'O')
				{
					cout << "|" << blocks[2][1] << "|       ";
				}
				if (_playerT == 'D')
				{
					cout << "|" << blocks[5][1] << "|       ";
				}
			}
			else if (sub == 2 && row == 1)
			{
				if (_playerT == 'X')
				{
					cout << "|" << blocks[1][2] << "|    B  ";
				}
				if (_playerT == 'O')
				{
					cout << "|" << blocks[2][2] << "|    B  ";
				}
				if (_playerT == 'D')
				{
					cout << "|" << blocks[5][2] << "|       ";
				}
			}

			else if (sub == 3 && row == 1)
			{
				if (_playerT == 'X')
				{
					cout << "|" << blocks[1][3] << "|       ";
				}
				if (_playerT == 'O')
				{
					cout << "|" << blocks[2][3] << "|       ";
				}
				if (_playerT == 'D')
				{
					cout << "|" << blocks[5][3] << "|       ";
				}
			}

			else if (sub == 4 && row == 1)
			{
				if (_playerT == 'X')
				{
					cout << "|" << blocks[1][4] << "|       ";
				}
				if (_playerT == 'O')
				{
					cout << "|" << blocks[2][4] << "|       ";
				}
				if (_playerT == 'D')
				{
					cout << "|" << blocks[5][4] << "|       ";
				}
			}

			else if (sub == 0 && row == 2)
			{
				if (_gameOver && _playerT != 'D')
				{
					cout << "|   Wins  |       ";
				}
				else if (_gameOver && _playerT == 'D')
				{
					cout << "|   Draw  |       ";
				}
				else 
				{
					cout << "|   Turn  |       ";

				}
			}
			else if (sub == 1 && row == 2)
			{
				cout << "|=========|       ";
			}
			else if (sub == 2 && row == 2)
			{
				cout << "               C  ";
			}
			else 
			{
				cout << "                  ";
			}
			for (int col = 0; col < _numCols; col++)
			{
				cout << block(row, col, sub);
				if (col == 0 || col == 1)
				{
					cout << "|"; // it renders vertical lines of the big board
				}
			}
			cout << endl;
		}
		if (row == 0 || row == 1)
		{
			cout << "|=========|     =================================    ";  //it renders horizontal lines of the big ans small boards
			cout << endl;
		}
	}
	cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
}
