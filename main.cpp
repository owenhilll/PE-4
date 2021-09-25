/**
 * CSCI 3010 - Programming Exercise 4
 * Zach Akin-Amland
 * Owen Hill
 * 
 * This is the main driver file for the TicTacToe game
 * that creates an empty 3x3 board and then
 * alternates players taking turns until
 * 9 total turns have been taken
 * 
 * Commands to run the program:
 * $ make clean
 * $ make all
 * $ ./Board
 * 
*/
#include "TicTacToe.h"
#include <iostream>

int main(){
  TicTacToe Game;
  Game.playGame();
  return 0;
}