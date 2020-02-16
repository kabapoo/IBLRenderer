#ifndef _MATERIAL_PHONG_H_
#define _MATERIAL_PHONG_H_

#include "material.h"

class MaterialPhong : public Material
{
private:
    float mGlossiness;
    float mSpecularPower;

public:
    MaterialPhong(glm::vec3 color, float specPower, float glossiness) : Material(color)
    {
        mGlossiness = glossiness;
        mSpecularPower = specPower;
    }

    void setGlossiness(float glossiness);
    void setSpecularPower(float specPower);
    float getGlossiness() const { return mGlossiness; }
    float getSpecularPower() const { return mSpecularPower; }
};

#endif