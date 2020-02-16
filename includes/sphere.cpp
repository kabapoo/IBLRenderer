#include "sphere.h"

Sphere::Sphere(float _radius, int _sectors, int _stacks)
{
    radius = _radius;
    sectors = _sectors;
    stacks = _stacks;

    float x, y, z;      // coords
    float nx, ny, nz;   // normals
    float s, t;         // tex coords
    float lengthInv = 1.0f / radius;    // for normalizing
    float sectorAngle, stackAngle;
    float sectorStep = M_PI * 2 / sectors;
    float stackStep = M_PI / stacks;

    // index
    int k1, k2;

    // clear memory of prev arrays
    std::vector<float>().swap(vertices);
    std::vector<float>().swap(normals);
    std::vector<float>().swap(texCoords);
    std::vector<int>().swap(indices);

    for (int i = 0; i <= stacks; ++i) {
        stackAngle = M_PI_2 - i * stackStep;        // pi/2 to -pi/2
        y = radius * sinf(stackAngle);
        k1 = i * (sectors + 1);
        k2 = k1 + sectors + 1;

        for (int j = 0; j <= sectors; ++j, ++k1, ++k2) {
            sectorAngle = j * sectorStep;       // 0 to 2pi
            x = radius * cosf(stackAngle) * cosf(sectorAngle);
            z = radius * cosf(stackAngle) * sinf(sectorAngle);  // clockwise where up is y axis
            
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);

            s = (float)j / sectors;
            t = (float)i / stacks;      // range [0, 1]
            texCoords.push_back(s);
            texCoords.push_back(t);

            // index
            if (i != 0) {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            if (i != (stacks-1)) {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }

    buildVerticesBatch();
}

void Sphere::buildVerticesBatch()
{
    std::vector<float>().swap(verticesBatch);
    std::size_t i, j;
    std::size_t count = vertices.size();
    for(i = 0, j = 0; i < count; i += 3, j += 2)
    {
        verticesBatch.push_back(vertices[i]);
        verticesBatch.push_back(vertices[i+1]);
        verticesBatch.push_back(vertices[i+2]);

        verticesBatch.push_back(normals[i]);
        verticesBatch.push_back(normals[i+1]);
        verticesBatch.push_back(normals[i+2]);

        verticesBatch.push_back(texCoords[j]);
        verticesBatch.push_back(texCoords[j+1]);
    }
    std::cout << verticesBatch.size() << std::endl;
}