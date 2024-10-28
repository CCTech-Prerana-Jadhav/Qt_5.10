#pragma once
#include "Triangle.h"
#include<vector>
#include <map>

class Triangulation
{
public:
    Triangulation();
    ~Triangulation();

    std::vector<double> UniqueNumbers;
    std::vector<Triangle> Triangles;
};