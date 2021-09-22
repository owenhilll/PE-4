
#include <iostream>

//initlaize 2d tic tac toe board
char TicTacToe[3][3];
//double nested for loop to create blank tic tac toe board
void CreateBoard(){
  for(int i = 0; i < 3;i++){
    for(int j= 0; j < 3; j++){
      TicTacToe[i][j] = ' ';
    }
  }
}


int main(){
  //initializes tic tac toe baord with blank spaces in each section
  CreateBoard();
  //testing to see if board initialized
  std::cout << "What" << std::endl;
  std::cout << "Again" << std::endl;
  return 0;
}