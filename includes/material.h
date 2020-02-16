#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#define MODEL_PHONG 0
#define MODEL_COOKTORRANCE 1

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Material
{
protected:
    glm::vec3 mColor;
    
public:
    Material(glm::vec3 color)
    {
        mColor = color;
    }

    void setColor(glm::vec3 color);
    glm::vec3 getColor() const { return mColor; }
};

#endif