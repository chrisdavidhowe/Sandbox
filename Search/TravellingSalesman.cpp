//
// Created by Chris Howe on 8/6/20.
//

#include "TravellingSalesman.h"


City::City(std::initializer_list<int> d)
{
    int i = 0;
    for (auto it = d.begin(); it != d.end(); ++it)
    {
        distances.push_back(*it);
        if (*it == 0)
        {
            cityReference = i;
        }
        i++;
    }
    printf("City %d Created\n", cityReference);
}

TravellingSalesman::TravellingSalesman(int sc)
{
    startingCity_ = sc;
}

int TravellingSalesman::calculateShortestPath(std::vector<City> cities, int startingPointReference)
{
    City* currentCity = &cities[startingPointReference];
    int min = 1000000;
    int minIndex = 0;

    if (currentCity->visited)
    {
        printf("Completed trip\n");
        return 1;
    }
    else
    {
        currentCity->visited = true;
    }

    for (int i = 0; i < cities.size(); ++i)
    {
        if (!cities[i].visited)
        {
            if (currentCity->distances[i] < min)
            {
                min = currentCity->distances[i];
                minIndex = i;
            }
        }
    }

    if (min == 1000000)
    {
        min = currentCity->distances[startingCity_];
        minIndex = startingCity_;
    }

    printf("Found shortest path from City %d to City %d at %d\n", currentCity->cityReference, minIndex, min);

    calculateShortestPath(cities, minIndex);
}