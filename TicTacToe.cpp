// TicTacToe Class Implementation File
// Zach Akin-Amland
// Owen Hill
// CSCI 3010 Programming Exercise 4
#include "TicTacToe.h"
#include <iostream>

// const string for emojis
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

/**
 * constructor
 * initializes tic tac toe baord with blank spaces in each section
 * calls initPlayers() to initialize Player1 and Player2
 * @param none
 * @return none
*/
TicTacToe::TicTacToe(){
  initPlayers();
  for(int i = 0; i < 3;i++){
    for(int j= 0; j < 3; j++){
      Board[i][j] = empty_emoji;
    }
  }
}

/**
 * displays each value of the 3x3 array Board[3[3]
 * @param none
 * @return none
*/
void TicTacToe::DisplayBoard(){
  for(int i=0;i<3;i++){
    std::cout<<std::endl;
    for(int j=0;j<3;j++){
      std::cout<<Board[i][j];
    }
  }
  std::cout<<"\n\n";
}

/**
 * Gets user input to determine how the player would like to use their turn
 * @param none
 * @return Position, position struct object that has the row and column that the player chose to place their symbol on
*/
Position TicTacToe::getPlayerTurn(){
  //Asks for user input on row they wish to move to
    std::string row;
    int r;
    std::cout << "Enter desired row (0-2): " ;
    std::getline(std::cin,row);
    r=stoi(row);
    
  //Asks player for column they wish to move to
    std::string col;
    int c;
    std::cout << "Enter desired column (0-2): " ;
    std::getline(std::cin,col);
    c = stoi(col);
  //creates a new position based on the player input for row/col. Then returns position accordindly.
    Position newmove;
    newmove.row = r;
    newmove.col = c;
    return newmove;
}

/**
 * Finds the position and updates the Board to display the current player's turn choice
 * @param Position turn- the location that the player wants to play, Player &*current - pointer reference to the current player whose turn it is
 * @return bool, returns true if the turn can be taken, false is the move is invalid
*/
bool TicTacToe::PlaceMarker(Position turn, Player *&current){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(i==turn.row&&j==turn.col){             // finds the position the player wants to move to
        if(Board[i][j]==empty_emoji){                         // checks to see if the move is available
          Board[i][j] = current->symbol;                       // sets the players symbol in the turns position
          current->turn_count++;                               // increases the turn count of the player
          DisplayBoard(); 
          std::cout<< current->name << " placed " << current->symbol << " at [" << turn.row << "][" << turn.col << "]." << std::endl;

          if(current->next!=nullptr){                          // conditional statement to set the currentPlayer
            currentPlayer = current->next;                     // pointer to the current player's opponent
          } else {
            currentPlayer = current->prev; 
          }                                
          return true;
        }
      }
    }
  }
  std::cout<<"Invalid move, try again." << std::endl;
  return false;
}

/**
 * This function checks if the game ending conditions have been met
 * outputs "Game Over!" if the total turns that have been taken in the game is 9
 * @param none
 * @return bool, returns true if the sum of the two players turn_count is 9, returns false otherwise
*/
bool TicTacToe::gameOver(){
  if(player1.turn_count+player2.turn_count==9){
    std::cout << "Game Over!" << std::endl;
    return true;
  }
  return false;
}

/**
 * This function puts all the other functions together to run the TicTacToe game
 * @param none
 * @return none
*/
void TicTacToe::playGame(){
  DisplayBoard();
  while(!gameOver()){
    PlaceMarker(getPlayerTurn(),currentPlayer);
  }
}