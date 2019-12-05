//
//  circle.cpp
//  fantastic-finale-ez720
//
//  Created by Elena Zheng on 11/19/19.
//

#include "circle.hpp"

Circle::Circle(int mouse_x, int mouse_y, int c) {
    int x_center = (mouse_x / 100) * 100 + 50;
    int y_center = (mouse_y / 100) * 100 + 50;
    
    this->x = x_center;
    this->y = y_center;
    this->color = c;
}
