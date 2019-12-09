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



TEST_CASE("Make move") {
    std::stringstream ss;
    Board board = Board(8);
    board.SetInitialBoard();
    Player black = Player('X');
    Player white = Player('O');
    
    SECTION("Horizontal") {
        SECTION("Simple move") {
            board.MakeMove(43, black);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . X X X . . . -\n"
            " - . . . X O . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }
        
        SECTION("Multiple tiles flipped") {
            board.MakeMove(43, black);
            board.MakeMove(42, white);
            board.MakeMove(46, white);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . O O O O O . . -\n"
            " - . . . X O . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }

    }
    
    SECTION("Vertical") {
        SECTION("Simple move") {
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
        
        SECTION("Multiple tiles flipped") {
            board.MakeMove(34, black);
            board.MakeMove(24, white);
            board.MakeMove(64, white);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . O . . . . -\n"
            " - . . . O . . . . -\n"
            " - . . . O X . . . -\n"
            " - . . . O O . . . -\n"
            " - . . . O . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }

    }
    
    SECTION("Diagonal") {
        SECTION("Simple move") {
            board.MakeMove(43, black);
            board.MakeMove(33, white);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . O . . . . . -\n"
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
            board.MakeMove(66, black);
            board.MakeMove(33, black);
            
            const char *expected_board =
            "\n"
            " - - - - - - - - - -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - . . X . . . . . -\n"
            " - . . . X X . . . -\n"
            " - . . . X X . . . -\n"
            " - . . . . . X . . -\n"
            " - . . . . . . . . -\n"
            " - . . . . . . . . -\n"
            " - - - - - - - - - -\n";
            
            board.PrintBoard(ss);
            REQUIRE(ss.str() == expected_board);
        }
    }
    
    SECTION("Flipping tiles in multiple directions") {
        board.MakeMove(34, black);
        board.MakeMove(45, white);
        board.MakeMove(56, black);
        
        const char *expected_board =
        "\n"
        " - - - - - - - - - -\n"
        " - . . . . . . . . -\n"
        " - . . . . . . . . -\n"
        " - . . . X . . . . -\n"
        " - . . . X X . . . -\n"
        " - . . . X X X . . -\n"
        " - . . . . . . . . -\n"
        " - . . . . . . . . -\n"
        " - . . . . . . . . -\n"
        " - - - - - - - - - -\n";
        
        board.PrintBoard(ss);
        REQUIRE(ss.str() == expected_board);
    }
}

TEST_CASE("Get valid moves") {
    Board board = Board(8);
    board.SetInitialBoard();
    Player black = Player('X');
    Player white = Player('O');
    
    SECTION("No valid moves") {
        board.MakeMove(34, black);
        board.MakeMove(45, white);
        board.MakeMove(56, black);
        
        REQUIRE(board.GetValidMoves(white).empty());
    }
    
    SECTION("Simple moves") {
        vector<int> black_moves = {34, 43, 56, 65};
        vector<int> white_moves = {35, 46, 53, 64};
        
        REQUIRE(board.GetValidMoves(black) == black_moves);
        REQUIRE(board.GetValidMoves(white) == white_moves);
        
    }
}

TEST_CASE("Scoring") {
    Board board = Board(8);
    board.SetInitialBoard();
    Player black = Player('X');
    Player white = Player('O');
    
    SECTION("Tie") {
        REQUIRE(board.Score(white) == 0);
        REQUIRE(board.Score(black) == 0);
    }
    
    SECTION("Black winning") {
        board.MakeMove(34, black);
        
        REQUIRE(board.Score(white) == -3);
        REQUIRE(board.Score(black) == 3);
    }
    
    SECTION("White winning") {
        board.MakeMove(53, white);
        
        REQUIRE(board.Score(black) == -3);
        REQUIRE(board.Score(white) == 3);
    }
}
