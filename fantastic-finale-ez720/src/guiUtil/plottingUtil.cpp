//
//  plottingUtil.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 12/4/19.
//

#include <math.h>
#include "plottingUtil.hpp"

std::pair<int, int> PlottingUtil::IndexToCenter(int index, int board_length, int gui_length) {
    int scale = gui_length / board_length;
    int x = (index % board_length) * scale + scale / 2;
    int y = (index / board_length) * scale + scale / 2;
    
    return std::make_pair(x, y);
}

int PlottingUtil::CenterToIndex(std::pair<int, int> center, int board_length, int gui_length) {
    int scale = gui_length / board_length;
    int x = center.first;
    int y = center.second;
    
    return (y / scale) * board_length + (x / scale);
}

int PlottingUtil::ClickToIndex(int mouse_x, int mouse_y, int board_length, int gui_length) {
    int scale = gui_length / board_length;
    int x = (mouse_x / scale) * scale + scale / 2;
    int y = (mouse_y / scale) * scale + scale / 2;
    
    return CenterToIndex(std::make_pair(x, y), board_length, gui_length);
}


