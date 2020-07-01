#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point
{
public:
    Point(int x, int y);
    int getX();
    int getY();

private:
    friend class Node;
    friend class bstree;

    int x_; //x
    int y_; //y

};

#endif // POINT_H_INCLUDED
