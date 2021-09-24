#include "TicTacToe.h"
#include <iostream>

const std::string empty_emoji="\U00002B1C";               // white square emoji
const std::string x_emoji="\U0000274C";                   // red X emoji
const std::string o_emoji="\U00002B55";                   // red O emoji

/**
 * Sets the name and symbol strings for Player1 and Player2
 * Sets the turn_count of each player to 0
 * Links the players with a doubly linked list
 * @param none
 * @return none
*/
void TicTacToe::initPlayers(){
  player1.symbol = x_emoji;
  player2.symbol = o_emoji;
  player1.turn_count = 0;
  player2.turn_count = 0;
  player1.name = "Player1";
  player2.name = "Player2";
  player1.next = &player2;
  player1.prev = nullptr;
  player2.next = nullptr;
  player2.prev = &player1;
  currentPlayer = &player1;
}

// initializes tic tac toe baord with blank spaces in each section
// initializes Players with their respective symbols of tictactoe
TicTacToe::TicTacToe(){
  initPlayers();
  for(int i = 0; i < 3;i++){
    for(int j= 0; j < 3; j++){
      Board[i][j] = empty_emoji;
    }
  }
}
// displays the 3x3 array Board[3[3]
void TicTacToe::DisplayBoard(){
  for(int i=0;i<3;i++){
    std::cout<<std::endl;
    for(int j=0;j<3;j++){
      std::cout<<Board[i][j];
    }
  }
  std::cout<<"\n\n";
}

Player* TicTacToe::get_currentPlayer(){
  return currentPlayer;
}

bool TicTacToe::PlaceMarker(Position turn, Player current, Player *&nextPlayer){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(i==turn.row&&j==turn.col){             // finds the position the player wants to move to
        if(Board[i][j]==empty_emoji){                         // checks to see if the move is available
          Board[i][j] = current.symbol;                       // sets the players symbol in the turns position
          current.turn_count++;                               // increases the turn count of the player
          DisplayBoard(); 
          std::cout<< current.name << " placed " << current.symbol << " at [" << turn.row << "][" << turn.col << "]." << std::endl;

          if(current.next!=nullptr){                          // conditional statement to set the currentPlayer
            currentPlayer = current.next;                     // pointer to the current player's opponent
            nextPlayer = current.next;
          } else {
            currentPlayer = current.prev; 
            nextPlayer = current.prev;
          }                                
          return true;
        }
      }
    }
  }
  std::cout<<"Invalid move, try again." << std::endl;
  return false;
}