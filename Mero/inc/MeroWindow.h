#ifndef _MERO_WINDOW_HPP
#define _MERO_WINDOW_HPP

typedef struct GLFWwindow GLFWwindow;

/**
 * @brief Holds window information
 *
 */
class MeroWindow
{
public:
	/**
	 * @brief Construct a new MeroWindow object
	 *
	 * @param x Width of window
	 * @param y Height of window
	 * @param name Name of the new window
	 */
	MeroWindow(int x, int y, const char *name);
	~MeroWindow();

	/**
	 * @brief Swaps the buffers
	 *
	 */
	void SwapBuffers();
	/**
	 * @brief Should the window close?
	 *
	 */
	bool ShouldClose();

	/**
	 * @brief Is the window a valid window?
	 *
	 */
	bool isValid()
	{
		return !(window == nullptr);
	};

private:
	GLFWwindow *window;
};

#endif