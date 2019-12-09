//
//  minimaxStrategy.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 12/4/19.
//

#include "minimaxStrategy.hpp"

int MinimaxStrategy::GetMove(Player player, Board board) {
    MinimaxSearch(player, board, 3);
    return best_move;
}

int MinimaxStrategy::MinimaxSearch(Player player, Board board, int depth) {
    if (depth == 0)
        return board.Score(minimax_player);
    
    vector<int> moves = board.GetValidMoves(player);
    int best_score;
    Player next = board.NextPlayer(player);
    
    //player is max
    if (player.GetMark() == minimax_player.GetMark()) {
        best_score = INT_MIN;
        
        for (int move : moves) {
            Board tempBoard = board;
            tempBoard.MakeMove(move, player);
            int minimax_score = MinimaxSearch(next, tempBoard, depth - 1);
            
            if (best_score < minimax_score) {
                best_score = minimax_score;
            
                if (depth == 3) {
                    best_move = move;
                }
            }
        }
    }
    
    //player is min
    else {
        best_score = INT_MAX;
        
        for (int move : moves) {
            Board tempBoard = board;
            tempBoard.MakeMove(move, player);
            int minimax_score = MinimaxSearch(next, tempBoard, depth - 1);
            
            if (best_score > minimax_score) {
                best_score = minimax_score;
            }
        }
    }
    
    return best_score;
}
