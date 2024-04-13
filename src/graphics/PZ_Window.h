#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>
#include <exception>

#include "PZ_Renderer.h"
#include "..\utils\PZ_Input.h"

class Window
{
	GLFWwindow *m_Window;
	const int m_Width = 0, m_Height = 0;
	const std::string m_WindowTitle;
	const RendererTypes m_RendererType;
public:
	Window(const std::string& title, int width, int height, const RendererTypes& renderer);
	~Window();

	inline bool GetWindowCloseEvent() { return glfwWindowShouldClose(m_Window); }

	void Update() const;
	void Render() const;
};