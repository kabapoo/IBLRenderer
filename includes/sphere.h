#pragma once

#include <vector>
#include <cmath>
#include <iostream>

class Sphere
{
private:
    float radius;
    int sectors;
    int stacks;

public:
    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> texCoords;
    std::vector<int> indices;
    std::vector<float> verticesBatch;

    Sphere(float _radius, int _sectors, int _stacks);
    void buildVerticesBatch();
};