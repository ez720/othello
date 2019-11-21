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
    char opponent;

public:
    Player(char player_mark);
    char GetMark();
    char GetOpponent();
};

#endif /* player_hpp */
