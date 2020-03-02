#ifndef POINT_H
#define POINT_H
#include <math.h>
template <typename T>
class Point
{
private:
    T x;
    T y;
public:
    Point();
    Point(T x,T y)
    {
        this->x = x;
        this->y = y;
    }

    T getY(){return this->y;}
    T getX(){return this->x;}

    double calcDist(const Point<T> &a)
    {
        return sqrt( (this->x - a.x) * (this->x - a.x) + (this->y - a.y) * (this->y - a.y) );
    }
};

#endif // POINT_H
