#pragma once

#include <glad/glad.h>
#include "stb_image.h"
#include <iostream>
class Texture
{
private:
    unsigned int id;
    unsigned int type;

public:
    Texture(const char* fname, int _type);
    unsigned int GetID() const { return id; }
};