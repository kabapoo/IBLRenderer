#ifndef _MATERIAL_COOKTORRANCE_H_
#define _MATERIAL_COOKTORRANCE_H_

#include "material.h"

class MaterialCookTorrance : public Material
{
private:
    float mRoughness;
    glm::vec3 mFresnel;
public:
    MaterialCookTorrance(glm::vec3 color, float roughness, glm::vec3 fresnel) : Material(color)
    {
        mRoughness = roughness;
        mFresnel = fresnel;
    }

    void setRoughness(float roughness);
    void setFresnel(glm::vec3 fresnel);

    float getRoughness() const { return mRoughness; }
    glm::vec3 getFresnel() const { return mFresnel; }
};

#endif