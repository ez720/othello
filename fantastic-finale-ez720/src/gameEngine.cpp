//
//  gameEngine.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/19/19.
//

#include "gameEngine.hpp"
#include <iostream>

void GameEngine::Run(int board_length) {
    Board board = Board(board_length);
    board.SetInitialBoard();
    board.PrintBoard(std::cout);
    
    Player black = Player('X');
    Player white = Player('O');
    Player player = black;
    MinimaxStrategy minimax_black = MinimaxStrategy();
    minimax_black.minimax_player = black;
    
    MinimaxStrategy minimax_white = MinimaxStrategy();
    minimax_white.minimax_player = white;
    
    while (!player.DoesNotExist()) {
        int move = minimax_white.GetMove(player, board);
        board.MakeMove(move, player);
        board.PrintBoard(std::cout);
        player = board.NextPlayer(player);
    }
}
