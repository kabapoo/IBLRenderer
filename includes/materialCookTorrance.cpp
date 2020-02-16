#include "materialCookTorrance.h"

void MaterialCookTorrance::setRoughness(float roughness)
{
    mRoughness = roughness;
}

void MaterialCookTorrance::setFresnel(glm::vec3 fresnel)
{
    mFresnel = fresnel;
}