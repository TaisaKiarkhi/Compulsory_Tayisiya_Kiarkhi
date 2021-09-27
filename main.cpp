#include <iostream>
using namespace std;
char table[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
void numbers_in_the_table();
void players_X_and_O();
char turn_X_and_O ='X';
char the_winner();
int draw{};   //int for how many times players typed numbers. Int "draw" needs to count if the game is draw.


void Table() {         
  
	//creates an array and shows it on the screen
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++){
			cout << "|" << " "<< table[i][j]<<" "<<"|";
		}
		cout << endl;
	}
	
}

void numbers_in_the_table() {        //Allows us to type a number on the table, so each number has its own cell in the array. When we type a number the cell will be marked with character X or O
	int number;
	cin >> number;
	if (number == 1) {
		table[0][0]= turn_X_and_O;
	}
	else if (number == 2) {
		table[0][1]= turn_X_and_O;
	}
	else if (number == 3) {
		table[0][2]= turn_X_and_O;
	}
	else if (number == 4) {
		table[1][0]= turn_X_and_O;
	}
	else if (number == 5) {
		table[1][1]= turn_X_and_O;
	}
	else if (number == 6) {
		table[1][2]= turn_X_and_O;
	}
	else if (number == 7) {
		table[2][0]= turn_X_and_O;
	}
	else if (number == 8) {
		table[2][1]= turn_X_and_O;
	}
	else if (number == 9) {
		table[2][2]= turn_X_and_O;
	}
}


void players_X_and_O() {              //Allows users to switch the characters  O and X on a table. Player O starts and then Player X can put the character and so on
	if (turn_X_and_O == 'X') {
	 turn_X_and_O = 'O';
	}
	else if (turn_X_and_O == 'O'){
		turn_X_and_O = 'X';
	}

}
char the_winner() {          //counts who is the winner of the game. If each cell has character 'X' in a row or column, the program tells who is the winner. 
	   //X player                                                                   
	if (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2]=='X') {  
		/*for example here in the line 66 will look like  this  X X X
		                                                        4 5 6
		                                                        7 8 9*/
		return 'X';
		
		}
	if (table[1][0] == 'X' && table[1][1] == 'X' && table[1][2]=='X') {
		return 'X';        
		
		}
	if (table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == 'X') {
		return 'X';
	}

	if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X') {
		return 'X';
		
	}
	
	if (table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == 'X') {
		return 'X';
		
	}

// 'O' player
		if (table[0][0] == 'O' && table[0][1] == 'O' && table[0][2] == 'O') {
			return 'O';
			
        }
		if (table[1][0] == 'O' && table[1][1] == 'O' && table[1][2] == 'O') {
			return 'O'; 
			
		}
		if (table[2][0] == 'O' && table[2][1] == 'O' && table[2][2] == 'O') {
			return 'O';
		}
		if (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O') {
			return 'O';
			
		}

		if (table[0][2] == 'O' && table[1][1] == 'O' && table[2][2] == 'O') {
			return 'O';
		}
		return ' ';            //returns empty character if no one of the statement above are fulfilled
}
	

		int main() {
			Table();
			cout << "^_^ *** Welcome to Tic Tac Toe!*** ^_^"<<endl;
			cout << "Player 1 - X  " << " VS " << " Player 2 - O " << endl;
			cout << "Type a number to play!" << endl;
			
			
			while (cout << "Your turn! ") {  
				draw++;                          //while-loop allows us to repeat the input of characters until someone wins. It shows "Your turn" every time the input happenes
				players_X_and_O();
				numbers_in_the_table();
				Table();
				if (the_winner() == 'X') {        //I used if-statement to count who is the winner, if character "the winner" has 'X' in a whole row or column, the player X  won the game. Then i used 'break' to stop the game. In other conditions I used statement else if (the_winner()==' ' && draw==9 ). Int sraw is 9 because it is possible to type only 9 numbers in the table. 
					cout << "The player X won the game! (^_^) ";
					break;
				}
				else if (the_winner() == 'O') {
					cout << "The player O won the game! (^_^) ";
					break;
				}
				
				else if (the_winner()==' ' && draw==9 ) {  
					cout << "It is draw!";
					break;
				}
				
			}
			return 0;
		}