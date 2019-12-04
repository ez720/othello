//
//  player.hpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/20/19.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>

class Player {
private:
    char mark;
    char opponent_mark;

public:
    Player() = default;
    Player(char player_mark);
    char GetMark();
    Player GetOpponent();
    char GetOpponentMark();
    bool IsMax();
    bool DoesNotExist();
};

#endif /* player_hpp */
