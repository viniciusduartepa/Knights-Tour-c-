/*
 * C++ solution for knights tour problem
 */
#include <bits/stdc++.h>
using namespace std;

#define N 6 ///<BoardSize


/**
 * Implementation of Knight object
 * 
 * Generic Knight that has two private member variables,
 * xMove and yMove, which are arrays of integers 
 * that represent the possible movements of a knight on a chessboard
 * 
*/
class Knight { 
		private:
		int xMove[8]= {  2, 1, -1, -2, -2, -1,  1,  2 };///<Horizontal movements
		int yMove[8]= {  1, 2,  2,  1, -1, -2, -2, -1 };///<Vertical movements	
	public:
	//Return horizontal move from a given index
    int getXMove(int index){ 
		return xMove[index];
	}
	//Return vertical move from a given index
	int getYMove(int index){
		return yMove[index];
	}
};

/**
 * Implemetation of Board
 * 
 * Generic Board that has a private member variable cell,
 * which is a 2D array of integers // backtracking
 * that represents the cells of the game board
 * 
*/
class Board {
    private:
		int cell[N][N];	///< Cells of gameboard
	public:
	//set -1 to all cells
	Board() {
		for (int x = 0; x < N; x++)    
		for (int y = 0; y < N; y++)
		cell[x][y] = -1;
	}
	//return the value of a cell in a given (x,y) position
	int getCell(int x,int y){
		return cell[x][y];
	}
	//sets the value of a cell in a given (x,y) position
	void setCell(int x,int y,int value){
		cell[x][y]=value;
	}
};

/**
 * Implementation of Solver to knight tour problem
 * 
*/

class Solver{ 
	private:
	Board B; ///< Board object to represent chessboard
	Knight K; ///< Knight object to represent knight chess piece
	public:
	/**
	 * Checks whether the game board is full.
	 *
	 * @param move The number of moves made so far.
	 * @return True if the game board is full, false otherwise.
	*/
	bool isFull(int move){ 
		return(move==N*N);
	}

	/**
	 * Displays the current state of the game board.
	*/
	void displaySolution() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			// Output the value at cell (x,y)
			cout << setw(2) << B.getCell(x,y) << " ";
		cout << endl;
  	}
	}

	/**
	 * Checks whether a given cell on the game board is a valid move.
	 *
	 * @param x The x-coordinate of the cell.
	 * @param y The y-coordinate of the cell.
	 * @return True if the cell is a valid move, false otherwise.
	*/
	bool isValid(int x,int y) { 
   		return ( x >= 0 && x < N && y >= 0 && y < N && B.getCell(x,y)== -1);
	}


	/**
	 * Tries to make a move at the given cell, recursively exploring all possible
	 * subsequent moves to find a complete knight's tour.
	 *
	 * @param x The row index of the cell to try.
	 * @param y The column index of the cell to try.
	 * @param move The number of moves made so far.
	 * @return True if a complete knight's tour was found, false otherwise.
	*/
	bool tryMove(int x, int y, int move) { 
		int xNext, yNext;
		if (isFull(move)) 
			// The board is full, so we've found a complete knight's tour.    
			return true;
		for (int i = 0; i < 8; i++) {
			// Try each of the eight possible moves from the current cell.
			xNext = x + K.getXMove(i);
			yNext = y + K.getYMove(i);
			if (isValid(xNext, yNext)) {
				// If the next cell is a valid move, mark it as visited and recurse 
				//to try to complete the tour from there.
				B.setCell(xNext,yNext,move);
				if (tryMove(xNext, yNext,move+1) == true)
					return true;
				else
					// If the recursive call failed, reset the current cell and try
					// the next possible move.
					B.setCell(xNext,yNext,-1);
				}
			}
		// If all possible moves have been tried and none lead to a complete tour,
		// return false to backtrack to the previous cell.
		return false;
	}
	/**
	 * Attempts to find a complete knight's tour starting from the top-left corner of
	 * the board, and prints the solution if one is found.
	*/
	void knightTour(){
		// Start the tour from the (0,0)position of the board.
		B.setCell(0,0,0);
		if(tryMove(0,0,1) == 0){
			// If no complete tour was found, print an error message and return.
			cout << "Solution does not exist";
			return;
		}
		else 
		 // If a complete tour was found, display the solution.
		displaySolution();
		return;

	}	
};


/**
 * The main function of the program. Creates a new Solver object and calls its
 * `knightTour` method to attempt to find a complete knight's tour on the board.
 * 
 * @return 0 if the program runs successfully.
 */
int main() {

	// Create a new Solver object.
   	Solver S;

	// Attempt to find a knight's tour and display the solution if one is found.
   	S.knightTour();

	// Return 0 to indicate successful completion of the program.
	return 0;

}
