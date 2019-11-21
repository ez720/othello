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
    const int kBoardLength = 8;
    const int kBoardSize = kBoardLength * kBoardLength;

    
    const char kEmpty = '.';
    const char kBlack = 'X';
    const char kWhite = 'O';
    
    vector<char> board_state;
    
public:
    //make private
        const vector<int> directions = {kBoardLength, -kBoardLength, -1, 1, kBoardLength + 1, kBoardLength - 1, -kBoardLength + 1, -kBoardLength - 1};
    void SetInitialBoard();
    void PrintBoard();
    int GetFlankIndex(int start_index, Player player, int direction);
    void FlipTiles(int start_index, Player player, int direction);
    bool IsValidMove(int start_index, Player player);
    void MakeMove(int start_index, Player player);
    vector<int> GetValidMoves(Player player);
    
    void SetBoard(int index, char mark);
};

#endif /* board_hpp */
