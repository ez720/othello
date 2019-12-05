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
    static std::pair<int, int> IndexToCenter(int index);
    static int CenterToIndex(std::pair<int, int> center);
    static int ClickToIndex(int mouse_x, int mouse_y);
};

#endif /* plottingUtil_hpp */
