//
//  moves-util.cpp
//  fantastic-finale-ez720-tests
//
//  Created by Elena Zheng on 12/8/19.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "board.hpp"

TEST_CASE("Get flank index") {
    Board board = Board(8);
    board.SetInitialBoard();
    
    Player black = Player('X');
    Player white = Player('O');
    
    int white_flank;
    int black_flank;
    
    SECTION("Horizontal cases") {
        SECTION("No flank") {
            black_flank = board.GetFlankIndex(20, black, 1);
            white_flank = board.GetFlankIndex(20, white, 1);
            
            REQUIRE(black_flank == -1);
            REQUIRE(white_flank == -1);
        }
        
        SECTION("Simple flank") {
            black_flank = board.GetFlankIndex(43, black, 1);
            white_flank = board.GetFlankIndex(53, white, 1);
            
            REQUIRE(black_flank == 45);
            REQUIRE(white_flank == 55);
        }
        
        SECTION("Flank with multiple tiles") {
            board.MakeMove(46, black);
            board.MakeMove(47, black);
            white_flank = board.GetFlankIndex(48, white, -1);
            
            REQUIRE(white_flank == 44);
        }
        
        SECTION("Boundary edge case") {
            board.MakeMove(46, black);
            board.MakeMove(47, black);
            board.MakeMove(48, black);
            white_flank = board.GetFlankIndex(51, white, -1);
            
            REQUIRE(white_flank == -1);
        }
    }
    
    SECTION("Vertical cases") {
        SECTION("No flank") {
            black_flank = board.GetFlankIndex(20, black, 10);
            white_flank = board.GetFlankIndex(20, white, 10);
            
            REQUIRE(black_flank == -1);
            REQUIRE(white_flank == -1);
        }
        
        SECTION("Simple flank") {
            black_flank = board.GetFlankIndex(34, black, 10);
            white_flank = board.GetFlankIndex(64, white, -10);
            
            REQUIRE(black_flank == 54);
            REQUIRE(white_flank == 44);
        }
        
        SECTION("Flank with multiple tiles") {
            board.MakeMove(25, black);
            board.MakeMove(35, black);
            white_flank = board.GetFlankIndex(15, white, 10);
            
            REQUIRE(white_flank == 55);
        }
        
        SECTION("Boundary edge case") {
            board.MakeMove(15, black);
            board.MakeMove(25, black);
            board.MakeMove(35, black);
            board.MakeMove(55, black);
            white_flank = board.GetFlankIndex(65, white, -10);
            
            REQUIRE(white_flank == -1);
        }
    }
    
    SECTION("Diagonal cases") {
        SECTION("No flank") {
            black_flank = board.GetFlankIndex(20, black, 11);
            white_flank = board.GetFlankIndex(20, white, 11);
            
            REQUIRE(black_flank == -1);
            REQUIRE(white_flank == -1);
        }
        
        SECTION("Simple flank") {
            board.MakeMove(43, black);
            white_flank = board.GetFlankIndex(33, white, 11);

            REQUIRE(white_flank == 55);
        }
        
        SECTION("Flank with multiple tiles") {
            board.MakeMove(33, black);
            board.MakeMove(43, black);
            white_flank = board.GetFlankIndex(22, white, 11);
            
            REQUIRE(white_flank == 55);
        }
        
        SECTION("Boundary edge case") {
            board.MakeMove(11, white);
            board.MakeMove(22, white);
            board.MakeMove(33, white);
            board.MakeMove(43, white);
            black_flank = board.GetFlankIndex(66, black, -11);
            
            REQUIRE(black_flank == -1);
        }
    }
}

TEST_CASE("Flip tiles") {
    std::stringstream ss;
    
    Board board = Board(8);
    board.SetInitialBoard();
    
    Player black = Player('X');
    Player white = Player('O');
    
    SECTION("Horizontal cases") {
        SECTION("No tiles flipped") {
            board.FlipTiles(56, black, 1);
            
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
        
        SECTION("One tile flipped") {
            board.FlipTiles(43, black, 1);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . X X . . . -\n"
            " - . . . X O . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }
        
        SECTION("Multiple tiles flipped") {
            board.MakeMove(56, white);
            board.FlipTiles(57, black, -1);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . O X . . . -\n"
            " - . . . X X X . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }
    }
    
    SECTION("Vertical cases") {
        SECTION("No tiles flipped") {
            board.FlipTiles(56, black, 10);
            
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
        
        SECTION("One tile flipped") {
            board.FlipTiles(34, black, 10);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . X X . . . -\n"
            " - . . . X O . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }
        
        SECTION("Multiple tiles flipped") {
            board.MakeMove(34, white);
            board.FlipTiles(24, black, 10);
            
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
    
    SECTION("Diagonal cases") {
        SECTION("No tiles flipped") {
            board.FlipTiles(56, black, 11);
            
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
        
        SECTION("One tile flipped") {
            board.MakeMove(43, black);
            board.FlipTiles(33, white, 11);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . X O X . . . -\n"
            " - . . . X O . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }
        
        SECTION("Multiple tiles flipped") {
            board.MakeMove(33, black);
            board.FlipTiles(66, black, -11);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . X . . . . . -\n"
            " - . . . X X . . . -\n"
            " - . . . X X . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }
    }
}
