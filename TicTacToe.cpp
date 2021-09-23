
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

void DisplayBoard(){
    for(int i = 0; i < 3;i++){
      for(int j= 0; j < 3; j++){
        std::cout << TicTacToe[i][j];
      }
      std::cout << std::endl;
    }
}


int main(){
  //initializes tic tac toe baord with blank spaces in each section
  CreateBoard();
  //testing to see if board initialized
  std::cout << TicTacToe[0][0] << std::endl;
  //
  return 0;
}