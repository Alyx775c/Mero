#include "MERO_WINDOW.hpp"

#include "MERO.hpp"

C_MeroWindow::C_MeroWindow(int x, int y, const char* name)
{
    window = glfwCreateWindow(x, y, name, NULL, NULL);
    if (window)
        MERO_LOG::getInstance().LOG(std::format("Successfully initialized GLFWwindow {}", name));
}

C_MeroWindow::~C_MeroWindow()
{
    glfwDestroyWindow(window);
}
