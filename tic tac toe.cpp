#include<iostream>
#include<string>
using namespace std;

char space[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int row;
int col;
char token = 'x' ;
bool tie=false;
string n1=" ";
string n2=" ";
int d ;

void structure() {

	cout << "\t\t\t__________________" << endl;
	cout << "\t\t\t|     |    |     |" << endl;
	cout << "\t\t\t|   " << space[0][0] << " | " << space[0][1] << "  | " << space[0][2] <<"   |" << endl;
	cout << "\t\t\t| ____|____|___  |" << endl;
	cout << "\t\t\t|     |    |     |" << endl;
	cout << "\t\t\t|  " << space[1][0] << "  | " << space[1][1] << "  | " << space[1][2] <<"   |" << endl;
	cout << "\t\t\t| ____|____|___  |" << endl;
	cout << "\t\t\t|     |    |     |" << endl;
	cout << "\t\t\t|  " << space[2][0] << "  | " << space[2][1] << "  | " << space[2][2] <<"   |" << endl;
	cout << "\t\t\t|     |    |     |" << endl;
	cout << "\t\t\t|________________|" << endl << endl;

	}

void choice() {
	
	if (token == 'x') {
		cout << n1 << " please enter your choice: ";
		cin >> d;
	}
	if (token == '0') {
		cout << n2 << " please enter your choice: ";
		cin >> d;
	}

	if (d == 1) 
	{
		row = 0;
		col = 0;
	}
	else if (d == 2)
	{
		row = 0;
		col = 1;
	}
	else if (d == 3)
	{
		row = 0;
		col = 2;
	}
	else if (d == 4)
	{
		row = 1;
		col = 0;
	}

	else if (d == 5)
	{
		row = 1;
		col = 1;
	}

	else if (d == 6)
	{
		row = 1;
		col = 2;
	}

	else if (d == 7)
	{
		row = 2;
		col = 0;
	}

	else if (d == 8)
	{
		row = 2;
		col = 1;
	}

	else if (d == 9)
	{
		row = 2;
		col = 2;
	}

	else
		cout << "Invalid!!!!!" << endl;

	if (token == '0' && space[row][col] != 'x' && space[row][col] != '0') 
	{
		space[row][col] = '0';
		token = 'x';

	}

	


	else if (token == 'x' && space[row][col] != 'x' && space[row][col] != '0')
	{
		cin.ignore(token == '0' && space[row][col] != 'x' && space[row][col] != '0');
		space[row][col] = 'x';
		token = '0';
	}
	else {
		cout << "There is no empty space! " << endl;
		
		choice();
	}
}
bool winner() 
{
	for (int i = 0; i < 3; i++) 
	{
		if (space[i][0] == space[i][1] && space[i][1] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
			return true;
		}	
	}
	if (space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][1] == space[1][1] && space[2][0]) {
		return true; 
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (space[i][j] != 'x' && space[i][j] != '0') {
					return false;
				}

			}
		}
	}
	tie = true;
	return false;

}
void welcome() {
	system("cls");
	system("color B");
	cout << "\t\t\t\tWelcome to tic tac toe\n\t\t\t\t\t\tbrought to you by UmEr FaRoOq! \n\n" << endl;
}
int main()
{
	welcome();
	cout << "Please enter the name of first palyer: ";
	getline(cin, n1);
	cout << endl << "Please enter the name of second palyer: ";
	getline(cin, n2);
	cout << "Player 1 is: " << n1 << endl << "Player 2 is: " << n2
		<< ". And " << n1 << " will play first." << endl;
	while (!winner()) {

		structure();
		choice();
		winner();
	}
	if (token == '0' && tie == false) {
		cout << n1 << " wins the game " << endl;
	}
	else if (token == 'x' && tie == false) {
		cout << n2 << " wins the game " << endl;
	}
	else
		cout << "It's a draw "<<endl;
	
}