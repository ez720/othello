//
//  gameEngine.hpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/19/19.
//

#ifndef gameEngine_hpp
#define gameEngine_hpp

#include <stdio.h>
#include "board.hpp"

class GameEngine {
public:
    static void SetupNewGame();
    void Run(int board_length);
};

#endif /* gameEngine_hpp */
