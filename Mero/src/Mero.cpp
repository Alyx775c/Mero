#include "Mero.h"

#include <iostream>

// shell func
void error_callback(int error, const char *description)
{
    MeroLogger::getInstance().LOG(std::format("Error {}, description: {}", error, description));
}

Mero::Mero(glm::ivec2 size, const char *name, bool testing)
{
    if (INIT)
        return;

    INIT = true;

    if (!glfwInit())
        MeroLogger::getInstance().LOG(std::format("Failed to initialize GLFW on window: {}", name), true);
    else
        MeroLogger::getInstance().LOG(std::format("Successfully initialized GLFW on window: {}", name));
    glfwSetErrorCallback(error_callback);

    window = new MeroWindow(size.x, size.y, name);

    if (!window)
    {
        MeroLogger::getInstance().LOG("Failed to initialize MeroWindow or its GLFW window.", true);
        return;
    }
}

void Mero::MainLoop()
{
    glfwPollEvents();

    Update();
    Render();

    window->SwapBuffers();
}

Mero::~Mero()
{
    Shutdown();
}
