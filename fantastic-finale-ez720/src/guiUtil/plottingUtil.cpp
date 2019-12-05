//
//  plottingUtil.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 12/4/19.
//

#include "plottingUtil.hpp"

std::pair<int, int> PlottingUtil::IndexToCenter(int index) {
    int x = (index % 10) * 100 + 50;
    int y = (index / 10) * 100 + 50;
    
    return std::make_pair(x, y);
}

int PlottingUtil::CenterToIndex(std::pair<int, int> center) {
    int x = center.first;
    int y = center.second;
    
    return ((y / 100) * 10 + x / 100);
}

int PlottingUtil::ClickToIndex(int mouse_x, int mouse_y) {
    int x = (mouse_x / 100) * 100 + 50;
    int y = (mouse_y / 100) * 100 + 50;
    
    return CenterToIndex(std::make_pair(x, y));
}


