//
// Created by Chris Howe on 9/3/20.
//

#pragma once

#include <string>
using namespace std;

class Color {};
class Shape {};
class Circle : Shape {};
class Square : Shape {};
class Rect : Shape {};
class Red : Color {};
class Blue : Color {};
class Green : Color {};

enum Colors
{
    RED,
    BLUE,
    GREEN
};

enum Shapes
{
    SQUARE,
    CIRCLE,
    RECT
};

class AbstractFactory
{
    virtual shared_ptr<Color> getColor(Colors color) = 0;
    virtual shared_ptr<Shape> getShape(Shapes shape) = 0;
};

class ColorFactory : public AbstractFactory
{
    shared_ptr<Color> getColor(Colors color) override;
    shared_ptr<Shape> getShape(Shapes shape) override;
};

class ShapeFactory : public AbstractFactory
{
    shared_ptr<Color> getColor(Colors color) override;
    shared_ptr<Shape> getShape(Shapes shape) override;
};