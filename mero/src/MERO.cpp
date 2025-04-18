#include "MERO.hpp"

#include <iostream>

// shell func
void error_callback(int error, const char *description)
{
    MeroLogger::getInstance().LOG(std::format("Error {}, description: {}", error, description));
}

std::string tFormat(std::string str, bool inTest)
{
    if (inTest)
        return std::format("[TEST-MODE] {}", str);

    return str;
}

Mero::Mero(glm::ivec2 size, const char *name, bool testing)
{
    if (INIT)
        return;

    INIT = true;

    if (!glfwInit())
        MeroLogger::getInstance().LOG(tFormat(std::format("Failed to initialize GLFW on window: {}", name), testing), true);
    else
        MeroLogger::getInstance().LOG(tFormat(std::format("Successfully initialized GLFW on window: {}", name), testing));
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
