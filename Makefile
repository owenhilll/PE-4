CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: Board

clean:
	rm Board

Board: TicTacToe.cpp
	$(CXX) $(CXXFLAGS) TicTacToe.cpp -o Board