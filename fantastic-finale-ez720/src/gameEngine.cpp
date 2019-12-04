//
//  gameEngine.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/19/19.
//

#include "gameEngine.hpp"
#include <iostream>

void GameEngine::SetupNewGame() {
    Board board = Board(8);
    board.SetInitialBoard();
    //board.PrintBoard();
}

void GameEngine::Run(int board_length) {
    Board board = Board(board_length);
    board.SetInitialBoard();
    board.PrintBoard(std::cout);
    
    Player p = Player('X');
    vector<int> moves = board.GetValidMoves(p);
    
    while (moves.size() != 0) {
        board.MakeMove(moves[0], p);
        board.PrintBoard(std::cout);
        p = p.GetOpponent();
        moves = board.GetValidMoves(p);
    }
}
