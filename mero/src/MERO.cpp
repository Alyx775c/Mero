#include <iostream>

#include "MERO.hpp"

// shell func
void error_callback(int error, const char* description)
{
    MERO_LOG::getInstance().LOG(std::format("Error {}, description: {}", error, description));
}

std::string tFormat(std::string str, bool inTest) {
    if (inTest)
        return std::format("[TEST-MODE] {}", str);

    return str;
}

MERO::MERO(glm::ivec2 size, const char* name, bool testing)
{
    if (INIT)
        return;

    INIT = true;
    
    if (!glfwInit())
        MERO_LOG::getInstance().LOG(tFormat(std::format("Failed to initialize GLFW on window: {}", name), testing), true);
    else
        MERO_LOG::getInstance().LOG(tFormat(std::format("Successfully initialized GLFW on window: {}", name), testing));
    glfwSetErrorCallback(error_callback);

    window = new C_MeroWindow(size.x, size.y, name);

    Poll();
}

void MERO::Poll()
{
    if (!glfwWindowShouldClose(window->window))
        glfwPollEvents();
}

MERO::~MERO()
{
    glfwTerminate();
}

