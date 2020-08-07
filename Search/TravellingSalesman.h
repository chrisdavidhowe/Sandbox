//
// Created by Chris Howe on 8/6/20.
//

#pragma once

#include <initializer_list>
#include <vector>

class City
{
public:
    City(std::initializer_list<int> d);
    bool visited { false };
    std::vector<int> distances;
    int cityReference { 0 };
};

class TravellingSalesman
{
public:
    TravellingSalesman(int startingCity);
    int calculateShortestPath(std::vector<City> cities, int startingPointReference);

private:
    int startingCity_ {0};
};