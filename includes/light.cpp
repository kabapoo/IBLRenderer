#include "light.h"

Light::Light(glm::vec3 pos, float intensity, glm::vec3 color, int type)
{
    mPosition = pos;
    mIntensity = intensity;
    mColor = color;
    mType = type;
}

Light::~Light()
{
}

void Light::setPosition(glm::vec3 pos)
{
    mPosition = pos;
}

void Light::setIntensity(float intensity)
{
    mIntensity = intensity;
}

void Light::setType(int type)
{
    mType = type;
}

void Light::setColor(glm::vec3 color)
{
    mColor = color;
}