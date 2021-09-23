// TicTacToe Class Header File
// Zach Akin-Amland
// Owen Hill
// CSCI 3010 Programming Exercise 4
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <string>

struct Player{
    std::string symbol;
};


class TicTacToe{
    public:
        TicTacToe();            //constuctor, initializes board with empty squares
        void DisplayBoard();    // displays the board
    private:
        std::string Board[3][3];  // 3x3 array of strings
};
#endif