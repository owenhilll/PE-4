#include "TicTacToe.h"
#include <iostream>

int main(){
  TicTacToe Game;
  Game.DisplayBoard();
  Player* test = Game.get_currentPlayer();
  Position location1;
  location1.row = 0;
  location1.col = 0;
  Position location2;
  location2.row = 0;
  location2.col = 2;
  Game.PlaceMarker(location1,*test,test);
  Game.PlaceMarker(location2,*test,test);
  return 0;
}