//
//  minimaxStrategy.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 12/4/19.
//

#include "minimaxStrategy.hpp"

int MinimaxStrategy::GetMove(Player player, Board board) {
    MinimaxSearch(player, board, 2);
    return best_move;
}

int MinimaxStrategy::MinimaxSearch(Player player, Board board, int depth) {
    if (depth == 0)
        return board.Score(player);
    
    vector<int> moves = board.GetValidMoves(player);
    int best_score = -1;
    Player next = board.NextPlayer(player);
    
    if (player.IsMax()) {
        best_score = INT_MIN;
        
        for (int move : moves) {
            Board tempBoard = board;
            tempBoard.MakeMove(move, player);
            int minimax_score = MinimaxSearch(next, tempBoard, depth - 1);
            
            if (best_score < minimax_score) {
                best_score = minimax_score;
                
                if (minimax_player.IsMax()) {
                    best_move = move;
                }
            }
        }
    }
    
    else {
        best_score = INT_MAX;
        
        for (int move : moves) {
            Board tempBoard = board;
            tempBoard.MakeMove(move, player);
            int minimax_score = MinimaxSearch(next, tempBoard, depth - 1);
            
            if (best_score > minimax_score) {
                best_score = minimax_score;
                
                if (!minimax_player.IsMax()) {
                    best_move = move;
                }
            }
        }
    }
    
    return best_score;
}
