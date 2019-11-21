//
//  player.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/20/19.
//

#include "player.hpp"
#include "board.hpp"

Player::Player(char player_mark) {
    mark = player_mark;
    opponent = (player_mark == 'X') ? 'O' : 'X';
}

char Player::GetMark() {
    return mark;
}

char Player::GetOpponent() {
    return opponent;
}
