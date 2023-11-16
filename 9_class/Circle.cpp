#include "Circle.h"

// constructor for properties
Circle::Circle(){
    radius = 1;
}

Circle::Circle(double newRadius) {
    radius = newRadius;
}

// define the methods
double Circle::getArea()
{
    return radius * radius * 3.14159;
}

// define the specific methods for private property
double Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(double newRadius)
{
    radius = (newRadius >= 0) ? newRadius : 0;
}