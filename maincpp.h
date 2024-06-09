#include "Dependencies/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "Light.h"
#include <iostream>

float skyboxVertices[] = {
    // positions          
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
};

//skybox faces
vector<std::string> faces
{
    "skybox/right.jpg",
    "skybox/left.jpg",
    "skybox/top.jpg",
    "skybox/bottom.jpg",
    "skybox/front.jpg",
    "skybox/back.jpg"
};

//groundPlane
const float groundPlaneVertices[] = {
    // positions  //texture coordinates
    -1, 0, -1, 0, 1,
    1, 0, -1, 1, 1,
    1, 0, 1, 1, 0,
    -1, 0, 1, 0, 0
};

const unsigned int groundPlaneIndices[] = {
    0, 1, 2,
    2, 3, 0
};

//lightCube 
float lightCubeVertices[] = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
};

// settings
const unsigned int SCR_WIDTH = 3840;
const unsigned int SCR_HEIGHT = 2400;

// camera
Camera camera(Transf::vec3(0.0f, 0.0f, 30.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

bool isDark = false;

// positions of the point lights
Transf::vec3 pointLightPositions[] = {
Transf::vec3 (-2.0f, 5.0f, 10.0f),
Transf::vec3(-1.0f, 15.0f, 60.0f),

Transf::vec3(-4.25f, 0.2f, -2.5f),
Transf::vec3(4.7f, 0.2f,  -0.5f),

Transf::vec3(-2.2f, 0.2f, 1.9f),
Transf::vec3(1.4f, 0.2f, 2.7f),

Transf::vec3(3.5f, 0.2f, -5.0f),
Transf::vec3(-1.1f, 0.2f, -6.0f),

Transf::vec3(-3.5f, 2.5f, -2.5f),
Transf::vec3(3.0f, 3.0f, -1.0f),

//street
Transf::vec3(-3.9f, 0.0f, 4.5f),
Transf::vec3(2.7f, 0.0f, 5.7f),

Transf::vec3(-5.3f, 0.0f, 12.0f),
Transf::vec3(1.3f, 0.0f, 13.0f),

Transf::vec3(-6.5f, 0.0f, 19.0f),
Transf::vec3(0.1f, 0.0f, 20.1f),

Transf::vec3(-7.8f, 0.0f, 26.4f),
Transf::vec3(-1.3f, 0.0f, 27.7f),
};