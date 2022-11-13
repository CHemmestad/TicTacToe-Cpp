/*

 */


#include <iostream>

using namespace std ;

void playerPosition ( char com , int playerTurn ,
int pos1 , int pos2 , int pos3 ,
int pos4 , int pos5 , int pos6 , 
int pos7 , int pos8 , int pos9 ) ;

void positioning ( int x , int &down , int &right ) ;

void computer ( int &pos1 , int &pos2 , int &pos3 , 
int &pos4 , int &pos5 , int &pos6 , 
int &pos7 , int &pos8 , int &pos9 ,
int &playerTurn , int &depth , int &score ) ;

int main(int argc, char **argv)
{
	PlayAgain :
	
	int pos1 = 0 ; int pos2 = 0 ; int pos3 = 0 ;
	int pos4 = 0 ; int pos5 = 0 ; int pos6 = 0 ; 
	int pos7 = 0 ; int pos8 = 0 ; int pos9 = 0 ;
	int playerTurn = 0 ;
	char com = '\0' ;
	int depth = 0 ;
	int score = 0 ;
	
	char enter ;
	
	while ( com != 'P' && com != 'p' && com != 'C' && com != 'c' ) {
		system ( "clear" ) ;
		cout << "Do you want to play with another player or a computer?" << endl ;
		cout << "Enter 'P' for another player or 'C' for a computer : " ;
		cin >> com ;
	}
	
	playerPosition ( com , playerTurn , pos1 , pos2 , pos3 , pos4 , pos5 , pos6 , pos7 , pos8 , pos9 ) ;
	
	cout << "Do you want to play again?  Y/N : " ;
	cin >> enter ;
	
	if ( enter == 'Y' || enter == 'y' ) {
		goto PlayAgain ;
	} else if ( enter == 'N' || enter == 'n' ) {
		return 0 ;
	} else {
		cout << "Invalid input! Try again. Y/N : " ;
		cin >> enter ;
	}
}

void playerPosition ( char com , int playerTurn ,
int pos1 , int pos2 , int pos3 ,
int pos4 , int pos5 , int pos6 , 
int pos7 , int pos8 , int pos9 ) {
	
	int down = 0 ; 
	int right = 0 ;
	int playerSpot ;
	
	char charX = 'X' ;
	char charO = 'O' ;
	int ay = 20 ;
	int bx = 41 ;
	char gridChar = '#' ;
	char grid [ ay ] [ bx ] ;
	
	system ( "clear" ) ;
	
	cout << "\n\n" ;
	
	for ( int y = 0 ; y < ay ; y ++ ) {
		for ( int x = 0 ; x < bx ; x++ ) {
			if (( y == 6 || y == 13 ) || ( x == 13 || x == 27 )) {
				grid [ y ] [ x ] = gridChar ;
			}
			else
				grid [ y ] [ x ] = ' ' ;
		}
	}
	for ( int x = 0 ; x < 10 ; x++ ) {
		if (( pos1 == 1 && x == 0 ) || ( pos2 == 1 && x == 1 ) || ( pos3 == 1 && x == 2 ) ||
		 ( pos4 == 1 && x == 3 ) || ( pos5 == 1 && x == 4 ) || ( pos6 == 1 && x == 5 ) ||
		 ( pos7 == 1 && x == 6 ) || ( pos8 == 1 && x == 7 ) || ( pos9 == 1 && x == 8 )) {
			positioning ( x , down , right ) ;
			for ( int y = 0 ; y < 6+down ; y++ ) {
				for ( int x = 0 ; x < 13+right ; x++ ) {
					if (( y == 0+down || y == 5+down ) && ( x == 2+right || x == 10+right )) {
						grid [ y ] [ x ] = charX ;
					} else if (( y == 1+down || y == 4+down ) && ( x == 3+right || x == 9+right )) {
						grid [ y ] [ x ] = charX ;
					} else if (( y == 2+down || y == 3+down ) && ( x == 5+right || x == 7+right )) {
						grid [ y ] [ x ] = charX ;
					}
				}
			}
		}
		if (( pos1 == 2 && x == 0 ) || ( pos2 == 2 && x == 1 ) || ( pos3 == 2 && x == 2 ) ||
		 ( pos4 == 2 && x == 3 ) || ( pos5 == 2 && x == 4 ) || ( pos6 == 2 && x == 5 ) ||
		 ( pos7 == 2 && x == 6 ) || ( pos8 == 2 && x == 7 ) || ( pos9 == 2 && x == 8 )) {
			 positioning ( x , down , right ) ;
			 for ( int y = 0 ; y < 6+down ; y++ ) {
				for ( int x = 0 ; x < 13+right ; x++ ) {
					if (( y >= 2+down && y <= 3+down ) && ( x == 1+right || x == 11+right )) {
						grid [ y ] [ x ] = charO ;
					} else if (( y == 1+down || y == 4+down ) && ( x == 2+right || x == 10+right )) {
						grid [ y ] [ x ] = charO ;
					} else if (( y == 0+down || y == 5+down ) && ( x >= 4+right && x <= 8+right )) {
						grid [ y ] [ x ] = charO ;
					}
				}
			}
		}
	}
	
	for ( int y = 0 ; y < ay ; y ++ ) {
		cout << "\t\t    " ;
		for ( int x = 0 ; x < bx ; x++ ) {
			cout << grid [ y ] [ x ] ;
		}
		cout << endl ;
	}
	
	if (( pos1 == 1 && pos2 == 1 && pos3 == 1 ) ||
	( pos4 == 1 && pos5 == 1 && pos6 == 1 ) ||
	( pos7 == 1 && pos8 == 1 && pos9 == 1 ) ||
	( pos1 == 1 && pos4 == 1 && pos7 == 1 ) ||
	( pos2 == 1 && pos5 == 1 && pos8 == 1 ) ||
	( pos3 == 1 && pos6 == 1 && pos9 == 1 ) ||
	( pos1 == 1 && pos5 == 1 && pos9 == 1 ) ||
	( pos3 == 1 && pos5 == 1 && pos7 == 1 )) {
		cout << "X WINS!" << endl ;
		return ;
	}
	if (( pos1 == 2 && pos2 == 2 && pos3 == 2 ) ||
	( pos4 == 2 && pos5 == 2 && pos6 == 2 ) ||
	( pos7 == 2 && pos8 == 2 && pos9 == 2 ) ||
	( pos1 == 2 && pos4 == 2 && pos7 == 2 ) ||
	( pos2 == 2 && pos5 == 2 && pos8 == 2 ) ||
	( pos3 == 2 && pos6 == 2 && pos9 == 2 ) ||
	( pos1 == 2 && pos5 == 2 && pos9 == 2 ) ||
	( pos3 == 2 && pos5 == 2 && pos7 == 2 )) {
		cout << "O WINS!" << endl ;
		return ;
	}
	if ( pos1 != 0 && pos2 != 0 && pos3 != 0 &&
	pos4 != 0 && pos5 != 0 && pos6 != 0 &&
	pos7 != 0 && pos8 != 0 && pos9 != 0 ) {
		cout << "Cat" << endl ;
		return ;
	}
	
	
	PlayerSelect :

	cin >> playerSpot ;
	if ( !cin ) {
		system ( "clear" ) ;
		cout << "Invalid input. Program ended." << endl ;
		return ;
	}
	if ( playerSpot > 9 || playerSpot < 1 ) {
		cout << "Invalid input! Try again." << endl ;
		goto PlayerSelect ;
	}
	
	if ( playerTurn == 0 ) {
		playerTurn = 1 ;
	}
	
	if ( playerSpot == 1 ) {
		if ( pos1 == 0 ) {
			pos1 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	} else if ( playerSpot == 2 ) {
		if ( pos2 == 0 ) {
			pos2 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	} else if ( playerSpot == 3 ) {
		if ( pos3 == 0 ) {
			pos3 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	} else if ( playerSpot == 4 ) {
		if ( pos4 == 0 ) {
			pos4 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	} else if ( playerSpot == 5 ) {
		if ( pos5 == 0 ) {
			pos5 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	} else if ( playerSpot == 6 ) {
		if ( pos6 == 0 ) {
			pos6 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	} else if ( playerSpot == 7 ) {
		if ( pos7 == 0 ) {
			pos7 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	} else if ( playerSpot == 8 ) {
		if ( pos8 == 0 ) {
			pos8 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	} else if ( playerSpot == 9 ) {
		if ( pos9 == 0 ) {
			pos9 = playerTurn ;
		} else {
			cout << "Invalid input! Try again." << endl ;
			goto PlayerSelect ;
		}
	}
	
	if ( com == 'P' || com == 'p' ) {
		if ( playerTurn == 1 ) {
			playerTurn = 2 ;
		} else 
			playerTurn = 1 ;
	} else if ( com == 'C' || com == 'c' ) {
		//computer ( pos1 , pos2 , pos3 , pos4 , pos5 , pos6 , pos7 , pos8 , pos9 , playerTurn , depth , score ) ;
	}
	playerPosition ( com , playerTurn , pos1 , pos2 , pos3 , pos4 , pos5 , pos6 , pos7 , pos8 , pos9 ) ;
}

void positioning ( int x , int &down , int &right ) {
	if ( x == 0 ) {
		down = 0 ; right = 0 ;
	} else if ( x == 1 ) {
		down = 0 ; right = 14 ;
	} else if ( x == 2 ) {
		down = 0 ; right = 28 ;
	} else if ( x == 3 ) {
		down = 7 ; right = 0 ;
	} else if ( x == 4 ) {
		down = 7 ; right = 14 ;
	} else if ( x == 5 ) {
		down = 7 ; right = 28 ;
	} else if ( x == 6 ) {
		down = 14 ; right = 0 ;
	} else if ( x == 7 ) {
		down = 14 ; right = 14 ;
	} else if ( x == 8 ) {
		down = 14 ; right = 28 ;
	}
}

void computer ( int &pos1 , int &pos2 , int &pos3 , int &pos4 , int &pos5 , int &pos6 , int &pos7 , int &pos8 , int &pos9 , int &playerTurn , int &depth ,  int &score ) {
	
	int comGuess [ 3 ] [ 3 ] ;
	
	comGuess [ 0 ] [ 0 ] = pos1 ;
	comGuess [ 0 ] [ 1 ] = pos2 ;
	comGuess [ 0 ] [ 2 ] = pos3 ;
	comGuess [ 1 ] [ 0 ] = pos4 ;
	comGuess [ 1 ] [ 1 ] = pos5 ;
	comGuess [ 1 ] [ 2 ] = pos6 ;
	comGuess [ 2 ] [ 0 ] = pos7 ;
	comGuess [ 2 ] [ 1 ] = pos8 ;
	comGuess [ 2 ] [ 2 ] = pos9 ;
	
	for ( int x = 0 ; x < 3 ; x++ ) {
		for ( int y = 0 ; y < 3 ; y++ ) {
			if ( comGuess [ x ] [ y ] == 0 ) {
				comGuess [ x ] [ y ] = playerTurn ;
				if ( playerTurn == 1 ) {
					playerTurn = 2 ;
				} else {
					playerTurn = 1 ;
				}
				if (( pos1 == 1 && pos2 == 1 && pos3 == 1 ) ||
				( pos4 == 1 && pos5 == 1 && pos6 == 1 ) ||
				( pos7 == 1 && pos8 == 1 && pos9 == 1 ) ||
				( pos1 == 1 && pos4 == 1 && pos7 == 1 ) ||
				( pos2 == 1 && pos5 == 1 && pos8 == 1 ) ||
				( pos3 == 1 && pos6 == 1 && pos9 == 1 ) ||
				( pos1 == 1 && pos5 == 1 && pos9 == 1 ) ||
				( pos3 == 1 && pos5 == 1 && pos7 == 1 )) {
					cout << "X WINS!" << endl ;
					score = -10 ;
					return ;
				}
				if (( pos1 == 2 && pos2 == 2 && pos3 == 2 ) ||
				( pos4 == 2 && pos5 == 2 && pos6 == 2 ) ||
				( pos7 == 2 && pos8 == 2 && pos9 == 2 ) ||
				( pos1 == 2 && pos4 == 2 && pos7 == 2 ) ||
				( pos2 == 2 && pos5 == 2 && pos8 == 2 ) ||
				( pos3 == 2 && pos6 == 2 && pos9 == 2 ) ||
				( pos1 == 2 && pos5 == 2 && pos9 == 2 ) ||
				( pos3 == 2 && pos5 == 2 && pos7 == 2 )) {
					cout << "O WINS!" << endl ;
					score = 10 ;
					return ;
				}
				if ( pos1 != 0 && pos2 != 0 && pos3 != 0 &&
				pos4 != 0 && pos5 != 0 && pos6 != 0 &&
				pos7 != 0 && pos8 != 0 && pos9 != 0 ) {
					cout << "Cat" << endl ;
					score = 0 ;
					return ;
				}
				depth++ ;
			}
		}
	}
	
	pos1 = comGuess [ 0 ] [ 0 ] ;
	pos2 = comGuess [ 0 ] [ 1 ] ;
	pos3 = comGuess [ 0 ] [ 2 ] ;
	pos4 = comGuess [ 1 ] [ 0 ] ;
	pos5 = comGuess [ 1 ] [ 1 ] ;
	pos6 = comGuess [ 1 ] [ 2 ] ;
	pos7 = comGuess [ 2 ] [ 0 ] ;
	pos8 = comGuess [ 2 ] [ 1 ] ;
	pos9 = comGuess [ 2 ] [ 2 ] ;	
	
	computer ( pos1 , pos2 , pos3 , pos4 , pos5 , pos6 , pos7 , pos8 , pos9 , playerTurn , depth , score ) ;
}






























