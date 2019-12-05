//
//  board.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/19/19.
//

#include "board.hpp"
#include <iostream>

Board::Board() {}

Board::Board(int board_length) {
    kBoardLength = board_length + 2;
    kBoardSize = kBoardLength * kBoardLength;
    directions = {kBoardLength, -kBoardLength, -1, 1, kBoardLength + 1, kBoardLength - 1, -kBoardLength + 1, -kBoardLength - 1};
}

const vector<char>& Board::GetBoard() const {
    return board_state;
}

void Board::SetInitialBoard() {
    board_state.clear();
    
    for (int i = 0; i < kBoardSize; i++) {
        board_state.push_back(kBound);
    }
    
    //setting boundaries
    for (int i = kBoardLength + 1; i < kBoardSize - kBoardLength; i++) {
        if ((1 <= (i % kBoardLength)) && ((i % kBoardLength) <= kBoardLength - 2))
            board_state[i] = kEmpty;
    }
    
    int top_left = kBoardSize / 2 - kBoardLength / 2 - 1;
    int top_right = top_left + 1;
    int bottom_left = top_left + kBoardLength;
    int bottom_right = bottom_left + 1;
    
    board_state[top_left] = kWhite;
    board_state[top_right] = kBlack;
    board_state[bottom_left] = kBlack;
    board_state[bottom_right] = kWhite;
}

void Board::PrintBoard(std::ostream& out) {
    for (int i = 0; i < kBoardSize; i++) {
        if (i % kBoardLength == 0)
            out << std::endl;
        
        out << " " << board_state[i];
    }
    
    out << std::endl;
}

int Board::GetFlankIndex(int start_index, Player player, int direction) {
    int next_tile = start_index + direction;
    
    //if next tile has player's mark or is out of bounds
    if (board_state[next_tile] == player.GetMark() || board_state[next_tile] == kBound)
        return -1;
    
    //while tiles in the direction are opponent tiles
    while (board_state[next_tile] == player.GetOpponentMark()) {
        next_tile += direction;
    }
    
    //check if the ending tile has player's mark
    return (board_state[next_tile] == player.GetMark()) ? next_tile : -1;
}

void Board::FlipTiles(int start_index, Player player, int direction) {
    int flank_index = GetFlankIndex(start_index, player, direction);
    
    if (flank_index == -1)
        return;
    
    int next_tile = start_index + direction;
    
    //flip all tiles in direction until flanked
    while (next_tile != flank_index) {
        board_state[next_tile] = player.GetMark();
        next_tile += direction;
    }
}

bool Board::IsValidMove(int start_index, Player player) {
    if (board_state[start_index] != kEmpty)
        return false;
    
    bool has_flank;
    
    //check if there is a valid move in any direction
    for (int direction : Board::directions) {
        if (GetFlankIndex(start_index, player, direction) != -1)
            return true;
    }
    
    return false;
}

void Board::MakeMove(int start_index, Player player) {
    board_state[start_index] = player.GetMark();
    
    for (int direction : Board::directions) {
        FlipTiles(start_index, player, direction);
    }
}

vector<int> Board::GetValidMoves(Player player) {
    vector<int> valid_moves;
    
    for (int i = kBoardLength + 1; i < kBoardSize - kBoardLength; i++) {
        if (IsValidMove(i, player))
            valid_moves.push_back(i);
    }
    
    return valid_moves;
}

int Board::Score(Player player) {
    int player_count = std::count(board_state.begin(), board_state.end(), player.GetMark());
    int opponent_count = std::count(board_state.begin(), board_state.end(), player.GetOpponentMark());
    
    return player_count - opponent_count;
}

Player Board::NextPlayer(Player player) {
    if (!GetValidMoves(player.GetOpponent()).empty()) {
        return player.GetOpponent();
    }
    
    else if(!GetValidMoves(player.GetOpponent()).empty()) {
        return player;
    }
    
    return Player('?');
}
