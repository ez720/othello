//
//  plottingUtil.hpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 12/4/19.
//

#ifndef plottingUtil_hpp
#define plottingUtil_hpp

#include <stdio.h>
#include <utility>
#include <iostream>

class PlottingUtil {
public:
    /*
     Converts an index to center coordinates for a circle on the board
     */
    static std::pair<int, int> IndexToCenter(int index, int board_length, int gui_length);
    
    /*
     Converts a pair of coordinates representing a circle's center to a board index
     */
    static int CenterToIndex(std::pair<int, int> center, int board_length, int gui_length);
    
    /*
     Converts a mouse click to a board index
     */
    static int ClickToIndex(int mouse_x, int mouse_y, int board_length, int gui_length);
};

#endif /* plottingUtil_hpp */
