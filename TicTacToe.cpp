#include "TicTacToe.h"
#include <iostream>

const std::string empty_emoji="\U00002B1C";               // white square emoji
const std::string x_emoji="\U00002B1C";                   // red X emoji
const std::string o_emoji="\U00002B55";                   // red O emoji

//initializes tic tac toe baord with blank spaces in each section
TicTacToe::TicTacToe(){
  for(int i = 0; i < 3;i++){
    for(int j= 0; j < 3; j++){
      Board[i][j] = empty_emoji;
    }
  }
}

<<<<<<< HEAD
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
=======
// displays the 3x3 array Board[3[3]
void TicTacToe::DisplayBoard(){
  for(int i=0;i<3;i++){
    std::cout<<std::endl;
    for(int j=0;j<3;j++){
      std::cout<<Board[i][j];
    }
  }
  std::cout<<"\n\n";
>>>>>>> 9038f11a715c2e3c95ad72fdba7b52bdb41befda
}