//
// Created by Chris Howe on 9/3/20.
//

#include "AbstractFactory.h"

shared_ptr<Color> ColorFactory::getColor(Colors color)
{
    switch (color)
    {
        case RED:
            auto out = shared_ptr<Red>();
            return out;
            break;
        case BLUE:
            break;
        case GREEN:
            break;
        default:
            return nullptr;
            break;
    }
}

shared_ptr<Shape> ShapeFactory::getShape(Shapes shape)
{
    switch (shape)
    {
        case SQUARE:
            break;
        case RECT:
            break;
        case CIRCLE:
            break;
        default:
            return nullptr;
            break;
    }
}