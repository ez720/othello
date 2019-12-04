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
    opponent_mark = (player_mark == 'X') ? 'O' : 'X';
}

char Player::GetMark() {
    return mark;
}

Player Player::GetOpponent() {
    return Player(GetOpponentMark());
}

char Player::GetOpponentMark() {
    return opponent_mark;
}

bool Player::IsMax() {
    return (mark == 'X');
}

bool Player::DoesNotExist() {
    return (mark == '?');
}
