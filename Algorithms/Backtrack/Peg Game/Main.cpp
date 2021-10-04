/*
	Jeremiah Schugt
	CSCI 4270
	Peg Game solver
*/
#include <iostream>
#include <vector>
#include <string>
#include "Main.h"

bool pegGame(int* , int[][3],int,std::vector<int>&);
int main() 
{
	int  board[18][3]= { { 0, 1, 3 }, { 0,2,5 }, { 1,3,6 }, { 1,4,8 }, { 2,4,7 }, { 2,5,9 }, { 3,4,5 }, { 3,6,10 },
	{ 3,7,12 },	{ 4,7,11 },	{ 4,8,13 },	{ 5,8,12 },	{ 5,9,14 },	{ 6,7,8 },{ 7,8,9 },{ 10,11,12 },{ 11,12,13 },{ 12,13,14 } };
	int * peg;
	peg = new int[15];
	for (int i = 0; i < 15; i++) {
		peg[i] = 1;

	}
	int remaining = 14;
	std::vector<int> movelist;
	std::cout << "Welcome to the peg game\n";
	std::cout << "Please enter a value between 0 and 14 representing an open space: ";
	int pos;
	std::cin >> pos;
	peg[pos] = 0;
	pegGame(peg, board,remaining,movelist);
	std::cout << "Here are the moves \n";
	int temp;
	int temp2;
	while(movelist.size()!=0) {
		temp = movelist[movelist.size()-1];
		movelist.pop_back();
		temp2 = movelist[movelist.size()-1];
		movelist.pop_back();
		std::cout << "Jump from peg hole " <<temp2 << " to peg hole " << temp << std::endl;
	}
	system("pause");
	return 0;
}
/*
This function using back tracking determines a method to solve a peg game.
Pre: need a peg boad, board moves and move list
Post: none
Param: pegs array for pegs in the board and their positions
Param: board this must include all possible moves for the board
Param: movelist stores the moves that were made to be displayed for the user
Return: boolean for recursive values
*/
bool pegGame(int *pegs ,int board[][3],int remaining,std::vector<int>&movelist) {
	bool success;
	if (remaining == 1) { return true; }
	for (int i = 0; i < 18; i++) {		
		if (pegs[board[i][0]] == 0 && pegs[board[i][1]] == 1 && pegs[board[i][2]] == 1) {		
			pegs[board[i][0]] = 1;
			pegs[board[i][1]] = 0;
			pegs[board[i][2]] = 0;
			success = pegGame(pegs, board, remaining - 1, movelist);
			if (success) {
				movelist.push_back(board[i][2]);
				movelist.push_back(board[i][0]);		
				return true;
			}
			else {
				pegs[board[i][0]] = 0;
				pegs[board[i][1]] = 1;
				pegs[board[i][2]] = 1;
			}
		}
		/// the reverse move
		if (pegs[board[i][2]] == 0 && pegs[board[i][1]] == 1 && pegs[board[i][0]]==1) {
			pegs[board[i][2]] = 1;
			pegs[board[i][1]] = 0;
			pegs[board[i][0]] = 0;
			success = pegGame(pegs, board, remaining - 1, movelist);
			if (success) {
				movelist.push_back(board[i][0]);
				movelist.push_back(board[i][2]);
				return true;
			}
			else {
				pegs[board[i][2]] = 0;
				pegs[board[i][1]] = 1;
				pegs[board[i][0]] = 1;
			}
		}
	
	}
	return false;


}