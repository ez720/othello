//
//  board.hpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/19/19.
//
#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "player.hpp"

using std::vector;
using std::string;

class Board {
private:
    int kBoardLength;
    int kBoardSize;
    vector<int> directions;

    const char kEmpty = '.';
    const char kBlack = 'X';
    const char kWhite = 'O';
    
    vector<char> board_state;
    
public:
    Board(int board_length);
    void SetInitialBoard();
    void PrintBoard();
    int GetFlankIndex(int start_index, Player player, int direction);
    void FlipTiles(int start_index, Player player, int direction);
    bool IsValidMove(int start_index, Player player);
    void MakeMove(int start_index, Player player);
    vector<int> GetValidMoves(Player player);
};

#endif /* board_hpp */
