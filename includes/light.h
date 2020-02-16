#ifndef _LIGHT_H_
#define _LIGHT_H_

#define LIGHT_POINT 0
#define LIGHT_DIRECTIONAL 1
#define LIGHT_SPOT 2

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class Light
{
private:
    /* data */
    glm::vec3 mPosition;
    float mIntensity;
    glm::vec3 mColor;
    int mType;
public:
    Light(glm::vec3 pos, float intensity, glm::vec3 color, int type);
    ~Light();

    glm::vec3 getPosition() const { return mPosition; }
    float getIntensity() const { return mIntensity; }
    glm::vec3 getColor() const { return mColor; }
    int getType() const { return mType; }

    void setPosition(glm::vec3 pos);
    void setIntensity(float intensity);
    void setColor(glm::vec3 color);
    void setType(int type);
};

#endif