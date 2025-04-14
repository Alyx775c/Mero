#ifndef _MERO_WINDOW_DEF
#define _MERO_WINDOW_DEF

#include "MERO_TYPES.hpp"

/**
 * Holds the window information, soon to be framebuffers too
 */
class C_MeroWindow
{
private:
	mWINDOW *window;
public:
	C_MeroWindow(int x, int y, const char* name);
	~C_MeroWindow();

	bool isValid() {
		return true;
		// return !(window == nullptr);
		// TODO: implement lmao
	};
};

#endif