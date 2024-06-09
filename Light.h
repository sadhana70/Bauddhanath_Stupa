#pragma once
#include "vec.h"
#include "Shader.h"

const int noOfLight = 16;

class Light
{
private:
	Transf::vec3 sunLightPos1;
	Transf::vec3 sunLightPos2;
	Transf::vec3 pointLightPositions[noOfLight];
public:
    Light();

	void setLights(Shader& lightingShader);
};

