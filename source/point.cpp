#include "point.h"

Point::Point(int x, int y)
                        : x_(x),
                          y_(y)
                    {
                    }

Point::getX(){
    return x_;
}

Point::getY(){
    return y_;
}
