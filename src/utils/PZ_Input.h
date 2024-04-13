#pragma once

#include <GLFW/glfw3.h>
#include <vector>

namespace Input 
{
	static std::vector<bool> keys;
	static void invoke(GLFWwindow* window, int key, int scancode,
		int action, int mods)
	{
		keys[key] = action != GLFW_RELEASE;
	}

	static bool OnKeyDown(int key)
	{
		return keys[key];
	}
}