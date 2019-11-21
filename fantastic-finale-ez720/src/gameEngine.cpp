//
//  gameEngine.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/19/19.
//

#include "gameEngine.hpp"
#include <iostream>

void GameEngine::Run() {
    Board board;
    board.SetInitialBoard();
    board.PrintBoard();
    
    Player p = Player('O');

    
    vector<int> moves = board.GetValidMoves(p);
    
    for (int move : moves) {
        board.MakeMove(move, p);
        board.PrintBoard();
        board.SetInitialBoard();
    }
}
