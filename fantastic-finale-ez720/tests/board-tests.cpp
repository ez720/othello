//
//  board-tests.cpp
//  fantastic-finale-ez720-tests
//
//  Created by Elena Zheng on 11/22/19.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "board.hpp"

TEST_CASE("Inital board tests") {
    std::stringstream ss;
    
    SECTION("8x8 board (default)") {
        Board board = Board(8); 
        board.SetInitialBoard();
        
        const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . O X . . . -\n"
            " - . . . X O . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
        
        board.PrintBoard(ss);
        REQUIRE(ss.str() == expected_board);
    }
    
    SECTION("10x10 board") {
        Board board = Board(10);
        board.SetInitialBoard();
        
        const char *expected_board =
            "\n"
            " - - - - - - - - - - - -\n"
            " - . . . . . . . . . . -\n"
            " - . . . . . . . . . . -\n"
            " - . . . . . . . . . . -\n"
            " - . . . . . . . . . . -\n"
            " - . . . . O X . . . . -\n"
            " - . . . . X O . . . . -\n"
            " - . . . . . . . . . . -\n"
            " - . . . . . . . . . . -\n"
            " - . . . . . . . . . . -\n"
            " - . . . . . . . . . . -\n"
            " - - - - - - - - - - - -\n";
        
        board.PrintBoard(ss);
        REQUIRE(ss.str() == expected_board);
    }
}

TEST_CASE("Get flank index") {
    Board board = Board(8);
    board.SetInitialBoard();
    
    Player black = Player('X');
    Player white = Player('O');
    
    int white_flank;
    int black_flank;
    
    SECTION("Horizontal flank") {
        black_flank = board.GetFlankIndex(43, black, 1);
        white_flank = board.GetFlankIndex(53, white, 1);
        
        REQUIRE(black_flank == 45);
        REQUIRE(white_flank == 55);
    }
    
    SECTION("No horizontal flank") {
        black_flank = board.GetFlankIndex(40, black, 1);
        white_flank = board.GetFlankIndex(40, white, 1);
        
        REQUIRE(black_flank == -1);
        REQUIRE(white_flank == -1);
    }
    
    SECTION("Vertical flank") {
        black_flank = board.GetFlankIndex(34, black, 10);
        white_flank = board.GetFlankIndex(64, white, -10);
        
        REQUIRE(black_flank == 54);
        REQUIRE(white_flank == 44);
    }
    
    SECTION("No vertical flank") {
        black_flank = board.GetFlankIndex(40, black, 10);
        white_flank = board.GetFlankIndex(40, white, 10);
        
        REQUIRE(black_flank == -1);
        REQUIRE(white_flank == -1);
    }
    
    /*SECTION("Diagonal flank") {
        black_flank = board.GetFlankIndex(34, black, 10);
        white_flank = board.GetFlankIndex(64, white, -10);
        
        REQUIRE(black_flank == 54);
        REQUIRE(white_flank == 44);
    }
    
    SECTION("No diagonal flank") {
        black_flank = board.GetFlankIndex(40, black, 10);
        white_flank = board.GetFlankIndex(40, white, 10);
        
        REQUIRE(black_flank == -1);
        REQUIRE(white_flank == -1);
    }*/
}

TEST_CASE("Make move") {
    std::stringstream ss;
    Board board = Board(8);
    board.SetInitialBoard();
    Player black = Player('X');
    Player white = Player('O');
    
    SECTION("Vertical") {
        board.MakeMove(34, black);
        
        const char *expected_board =
        "\n"
        " - - - - - - - - - -\n"
        " - . . . . . . . . -\n"
        " - . . . . . . . . -\n"
        " - . . . X . . . . -\n"
        " - . . . X X . . . -\n"
        " - . . . X O . . . -\n"
        " - . . . . . . . . -\n"
        " - . . . . . . . . -\n"
        " - . . . . . . . . -\n"
        " - - - - - - - - - -\n";
        
        board.PrintBoard(ss);
        REQUIRE(ss.str() == expected_board);
    }
}
