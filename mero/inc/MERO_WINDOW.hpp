#ifndef _MERO_WINDOW_HPP
#define _MERO_WINDOW_HPP

typedef struct GLFWwindow GLFWwindow;

/**
 * Holds the window information, soon to be framebuffers too
 */
class C_MeroWindow
{
public:
	GLFWwindow* window;
	C_MeroWindow(int x, int y, const char *name);
	~C_MeroWindow();

	bool isValid()
	{
		return true;
		// return !(window == nullptr);
		// TODO: implement lmao
	};
};

#endif