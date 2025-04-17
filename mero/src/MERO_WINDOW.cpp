#include "MERO_WINDOW.hpp"
#include "MERO.hpp"

C_MeroWindow::C_MeroWindow(int x, int y, const char *name)
{
    // Remove the GLFW_NO_API hint to allow OpenGL context creation
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // Set OpenGL version (e.g., 4.5)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(x, y, name, NULL, NULL);
    if (window)
        MERO_LOG::getInstance().LOG(std::format("Successfully initialized GLFWwindow {}", name));
    else
        MERO_LOG::getInstance().LOG("Failed to create GLFW window", true);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        MERO_LOG::getInstance().LOG("Failed to initialize GLAD", true);
    }
}

void C_MeroWindow::SwapBuffers()
{
    glfwSwapBuffers(window);
}

bool C_MeroWindow::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

C_MeroWindow::~C_MeroWindow()
{
    glfwDestroyWindow(window);
}
