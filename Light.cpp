#include "Light.h"


    Light::Light()
    {
        sunLightPos1 = Transf::vec3(-2.0f, 5.0f, 10.0f);
        sunLightPos2 = Transf::vec3(-1.0f, 15.0f, 60.0f);
        pointLightPositions[0] = Transf::vec3(-4.25f, 0.2f, -2.5f);
        pointLightPositions[1] = Transf::vec3(4.7f, 0.2f, -0.5f);
        pointLightPositions[2] = Transf::vec3(-2.2f, 0.2f, 1.9f);
        pointLightPositions[3] = Transf::vec3(1.4f, 0.2f, 2.7f);
        pointLightPositions[4] = Transf::vec3(3.5f, 0.2f, -5.0f);
        pointLightPositions[5] = Transf::vec3(-1.1f, 0.2f, -6.0f);

        pointLightPositions[6] = Transf::vec3(-3.5f, 2.5f, -2.5f);
        pointLightPositions[7] = Transf::vec3(3.0f, 3.0f, -1.0f);

        //street
        pointLightPositions[8] = Transf::vec3(-3.9f, 0.0f, 4.5f);
        pointLightPositions[9] = Transf::vec3(2.7f, 0.0f, 5.7f);
        pointLightPositions[10] = Transf::vec3(-5.3f, 0.0f, 12.0f);
        pointLightPositions[11] = Transf::vec3(1.3f, 0.0f, 13.0f);
        pointLightPositions[12] = Transf::vec3(-6.5f, 0.0f, 19.0f);
        pointLightPositions[13] = Transf::vec3(0.1f, 0.0f, 20.1f);
        pointLightPositions[14] = Transf::vec3(-7.8f, 0.0f, 26.4f);
        pointLightPositions[15] = Transf::vec3(-1.3f, 0.0f, 27.7f);
    }

    void Light::setLights(Shader& lightingShader)
    {
        // sun light-1
        lightingShader.setVec3("sunLight1.position", sunLightPos1);
        lightingShader.setVec3("sunLight1.ambient", 0.5f, 0.5f, 0.5f);
        lightingShader.setVec3("sunLight1.diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("sunLight1.specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("sunLight1.constant", 1.0f);
        lightingShader.setFloat("sunLight1.linear", 0.002);
        lightingShader.setFloat("sunLight1.quadratic", 0.0013);

        // sun light-2
        lightingShader.setVec3("sunLight2.position", sunLightPos2);
        lightingShader.setVec3("sunLight2.ambient", 0.5f, 0.5f, 0.5f);
        lightingShader.setVec3("sunLight2.diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("sunLight2.specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("sunLight2.constant", 1.0f);
        lightingShader.setFloat("sunLight2.linear", 0.0002);
        lightingShader.setFloat("sunLight2.quadratic", 0.0013);

        // point light 0
        lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
        lightingShader.setVec3("pointLights[0].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[0].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[0].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[0].constant", 1.0f);
        lightingShader.setFloat("pointLights[0].linear", 0.35);
        lightingShader.setFloat("pointLights[0].quadratic", 0.44);

        // point light 1
        lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
        lightingShader.setVec3("pointLights[1].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[1].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[1].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[1].constant", 1.0f);
        lightingShader.setFloat("pointLights[1].linear", 0.35);
        lightingShader.setFloat("pointLights[1].quadratic", 0.44);


        // point light 2
        lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
        lightingShader.setVec3("pointLights[2].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[2].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[2].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[2].constant", 1.0f);
        lightingShader.setFloat("pointLights[2].linear", 0.35);
        lightingShader.setFloat("pointLights[2].quadratic", 0.44);

        // point light 3
        lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
        lightingShader.setVec3("pointLights[3].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[3].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[3].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[3].constant", 1.0f);
        lightingShader.setFloat("pointLights[3].linear", 0.35);
        lightingShader.setFloat("pointLights[3].quadratic", 0.44);

        // point light 4
        lightingShader.setVec3("pointLights[4].position", pointLightPositions[4]);
        lightingShader.setVec3("pointLights[4].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[4].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[4].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[4].constant", 1.0f);
        lightingShader.setFloat("pointLights[4].linear", 0.35);
        lightingShader.setFloat("pointLights[4].quadratic", 0.44);

        // point light 5
        lightingShader.setVec3("pointLights[5].position", pointLightPositions[5]);
        lightingShader.setVec3("pointLights[5].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[5].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[5].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[5].constant", 1.0f);
        lightingShader.setFloat("pointLights[5].linear", 0.35);
        lightingShader.setFloat("pointLights[5].quadratic", 0.44);


        // point light 6
        lightingShader.setVec3("pointLights[6].position", pointLightPositions[6]);
        lightingShader.setVec3("pointLights[6].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[6].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[6].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[6].constant", 1.0f);
        lightingShader.setFloat("pointLights[6].linear", 0.35);
        lightingShader.setFloat("pointLights[6].quadratic", 0.44);

        // point light 7
        lightingShader.setVec3("pointLights[7].position", pointLightPositions[7]);
        lightingShader.setVec3("pointLights[7].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[7].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[7].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[7].constant", 1.0f);
        lightingShader.setFloat("pointLights[7].linear", 0.35);
        lightingShader.setFloat("pointLights[7].quadratic", 0.44);

        //streetlight

        // point light 8
        lightingShader.setVec3("pointLights[8].position", pointLightPositions[8]);
        lightingShader.setVec3("pointLights[8].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[8].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[8].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[8].constant", 1.0f);
        lightingShader.setFloat("pointLights[8].linear", 0.22);
        lightingShader.setFloat("pointLights[8].quadratic", 0.20);

        // point light 9
        lightingShader.setVec3("pointLights[9].position", pointLightPositions[9]);
        lightingShader.setVec3("pointLights[9].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[9].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[9].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[9].constant", 1.0f);
        lightingShader.setFloat("pointLights[9].linear", 0.22);
        lightingShader.setFloat("pointLights[9].quadratic", 0.20);

        // point light 10
        lightingShader.setVec3("pointLights[10].position", pointLightPositions[10]);
        lightingShader.setVec3("pointLights[10].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[10].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[10].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[10].constant", 1.0f);
        lightingShader.setFloat("pointLights[10].linear", 0.22);
        lightingShader.setFloat("pointLights[10].quadratic", 0.20);

        // point light 11
        lightingShader.setVec3("pointLights[11].position", pointLightPositions[11]);
        lightingShader.setVec3("pointLights[11].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[11].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[11].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[11].constant", 1.0f);
        lightingShader.setFloat("pointLights[11].linear", 0.22);
        lightingShader.setFloat("pointLights[11].quadratic", 0.20);

        // point light 12
        lightingShader.setVec3("pointLights[12].position", pointLightPositions[12]);
        lightingShader.setVec3("pointLights[12].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[12].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[12].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[12].constant", 1.0f);
        lightingShader.setFloat("pointLights[12].linear", 0.22);
        lightingShader.setFloat("pointLights[12].quadratic", 0.20);

        // point light 13
        lightingShader.setVec3("pointLights[13].position", pointLightPositions[13]);
        lightingShader.setVec3("pointLights[13].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[13].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[13].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[13].constant", 1.0f);
        lightingShader.setFloat("pointLights[13].linear", 0.22);
        lightingShader.setFloat("pointLights[13].quadratic", 0.20);

        // point light 14
        lightingShader.setVec3("pointLights[14].position", pointLightPositions[14]);
        lightingShader.setVec3("pointLights[14].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[14].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[14].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[14].constant", 1.0f);
        lightingShader.setFloat("pointLights[14].linear", 0.22);
        lightingShader.setFloat("pointLights[14].quadratic", 0.20);

        // point light 15
        lightingShader.setVec3("pointLights[15].position", pointLightPositions[15]);
        lightingShader.setVec3("pointLights[15].ambient", 0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("pointLights[15].diffuse", 1.0f, 0.77f, 0.56f);
        lightingShader.setVec3("pointLights[15].specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("pointLights[15].constant", 1.0f);
        lightingShader.setFloat("pointLights[15].linear", 0.22);
        lightingShader.setFloat("pointLights[15].quadratic", 0.20);
    }



