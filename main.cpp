#include <iostream>
#include <stack>
#include "queen.h"

//function to check if any queen is under attack
bool isSafe(int col, int filled, std::stack<Queen> solution) {
//while loop that keeps going until stack is empty
  while (!solution.empty()) {
        Queen currentQueen = solution.top(); 
        solution.pop(); //Removing the queen from stack

        // Check if currentQueen had the same coloumn
        if (currentQueen.getColoumn() == col) {
            return false;
        }
        //checking if negative diagonal is safe
        if (currentQueen.getNegDiagonal() == (filled - col)) {
            return false; 
        }
        //checking if positive diagonal is safe
        if (currentQueen.getPosDiagonal() == (filled + col)) {
            return false; // Positive diagonal conflict
        }
    }
    return true;  //if all tests are passed we return true which means that the placement won't cause conflict
}

//Function that finds a possible soloution to the n queens problem using a stack
std::stack<Queen> nQueensSoloution(int n) {
	std::stack<Queen> solution; //intialzing stack of type queen
	int filled = 0; //int that corrolates to how rows are filled
	int coloumn = 1;
	//while loop that end when filled is the same as the user defined number
	while(filled < n) {
	    Queen queen;
	    bool foundSafe = false;
	    //Second while loop that keeps going until coloumn is the same as n
	    while(coloumn <= n){
		if(isSafe(coloumn, filled, solution)) {
            queen.setColoumn(coloumn);
            queen.setNegDiagonal(filled - coloumn);
            queen.setPosDiagonal(filled + coloumn);
            solution.push(queen); //pushing queen obj onto to stack
            filled++;
			coloumn = 1; //reseting coloumn number for next obj
			foundSafe = true;
			break;
			
		}
		coloumn++;
		}
		//if statement that checks if no safe positions were found to start backtracking
		if(!foundSafe) {
            if(!solution.empty()){ //checking if stack is empty
            filled--;
            coloumn = solution.top().getColoumn() + 1; // getting coloumn number of last pushed object on the stack and adding one
            solution.pop(); //then removing it from stack to give it new coordinates
            }
		}
	}
	return solution;
}

int main()
{
    //getting input from user
	int n;
	std::cout << "Please enter number of queens: ";
	std::cin >> n;
	//validating input from user
	while(n < 3 || n > 8) {
		std::cout << "Invalid value. Please try again." << std::endl;
		std::cout << "Please enter number of queens: ";
		std::cin >> n;
	}
	
	//calling nQueensSoloution function
	std::stack<Queen> Qs = nQueensSoloution(n);
	//printing out the coordinates of all the queens
	for(int i = n; i > 0; i--){
	    std::cout << "Row: " << i << " Coloumn: " << Qs.top().getColoumn() << std::endl;
	    Qs.pop();
	}

	return 0;
}