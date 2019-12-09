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
    vector<char> board_state;
    
    char kEmpty = '.';
    char kBlack = 'X';
    char kWhite = 'O';
    char kBound = '-';
    
public:
    /*
     Default constructor for board
     */
    Board();
    
    /*
     Constructor for board
     Creates a board_length * board_length vector to represent a board
     */
    Board(int board_length);
    
    /*
     Vector to represent a board
     */
    const vector<char>& GetBoard() const;
    
    /*
     Sets the current board to the starting board for Othello
     Each player has two pieces that are diagonal to each other in the center of the board
     */
    void SetInitialBoard();
    
    /*
     Pretty printing for the board
     Black is "X", White is "O", Empty is "."
     */
    void PrintBoard(std::ostream& out);
    
    /*
     Returns an index of a tile where the player flanks all opponent tiles in the direction
     If the player can't flank the opponent in the direction, return -1
     */
    int GetFlankIndex(int start_index, Player player, int direction);
    
    /*
     From the start_index, changes all opponent tiles to player tiles in given direction
     */
    void FlipTiles(int start_index, Player player, int direction);
    
    /*
     Check if player can flank the opponent from any direction starting at start_index
     */
    bool IsValidMove(int start_index, Player player);
    
    /*
     From start_index, flip tiles on board in all valid directions
     */
    void MakeMove(int start_index, Player player);
    
    /*
     Returns a vector of valid indices the player can move
     */
    vector<int> GetValidMoves(Player player);
    
    /*
     Returns # of player pieces - # of opponent pieces
     */
    int Score(Player player);
    
    /*
     If the player's opponent can move, return the opponent
     If the player's opponent can't move, but player can, return player
     Else, return "null" player
     */
    Player NextPlayer(Player player);
};

#endif /* board_hpp */
