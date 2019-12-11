//
//  minimaxStrategy.hpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 12/4/19.
//

#ifndef minimaxStrategy_hpp
#define minimaxStrategy_hpp

#include <stdio.h>
#include "player.hpp"
#include "board.hpp"

class MinimaxStrategy {
public:
    Player minimax_player;
    MinimaxStrategy() = default;
    int best_move;
    
    /*
     Gets best move returned by minimax search with depth of 3
     */
    int GetMove(Player player, Board board);
    
    int MinimaxSearch(Player player, Board board, int depth);
};

#endif /* minimaxStrategy_hpp */
