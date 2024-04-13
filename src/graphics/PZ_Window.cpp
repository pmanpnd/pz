#include "PZ_Window.h"

Window::Window(const std::string& title, int width, int height, const RendererTypes& renderer)
	: m_WindowTitle(title), m_Width(width), m_Height(height), m_RendererType(renderer)
{
	switch (m_RendererType)
	{
		case RendererTypes::OpenGL:
		{
			Input::keys.resize(65536);

			if (!glfwInit())
				throw std::exception("Failed to initialize OpenGL.");

			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			m_Window = glfwCreateWindow(m_Width, m_Height, m_WindowTitle.c_str(), nullptr, nullptr);

			if (!m_Window)
				throw std::exception("Failed to create GLFW window.");

			const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
			glfwSetWindowPos(m_Window, (vidmode->width - m_Width) / 2, (vidmode->height - m_Height) / 2);
			glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
				glViewport(0, 0, width, height);
				});
			glfwSetKeyCallback(m_Window, Input::invoke);
			glfwMakeContextCurrent(m_Window);
			glfwSwapInterval(1);

			if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
				throw std::exception("Failed to initialize GLAD.");
			
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glfwShowWindow(m_Window);
		} break;
		case RendererTypes::OpenGL_M2:
		{
			Input::keys.resize(65536);

			if (!glfwInit())
				throw std::exception("Failed to initialize OpenGL.");

			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			glfwWindowHint(GLFW_SAMPLES, 2);

			glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			m_Window = glfwCreateWindow(m_Width, m_Height, m_WindowTitle.c_str(), nullptr, nullptr);

			if (!m_Window)
				throw std::exception("Failed to create GLFW window.");

			const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
			glfwSetWindowPos(m_Window, (vidmode->width - m_Width) / 2, (vidmode->height - m_Height) / 2);
			glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
				glViewport(0, 0, width, height);
				});
			glfwSetKeyCallback(m_Window, Input::invoke);
			glfwMakeContextCurrent(m_Window);
			glfwSwapInterval(1);

			if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
				throw std::exception("Failed to initialize GLAD.");
			
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_MULTISAMPLE);

			glfwShowWindow(m_Window);
		} break;
		case RendererTypes::OpenGL_M3:
		{
			Input::keys.resize(65536);

			if (!glfwInit())
				throw std::exception("Failed to initialize OpenGL.");

			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			glfwWindowHint(GLFW_SAMPLES, 3);

			glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			m_Window = glfwCreateWindow(m_Width, m_Height, m_WindowTitle.c_str(), nullptr, nullptr);

			if (!m_Window)
				throw std::exception("Failed to create GLFW window.");

			const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
			glfwSetWindowPos(m_Window, (vidmode->width - m_Width) / 2, (vidmode->height - m_Height) / 2);
			glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
				glViewport(0, 0, width, height);
				});
			glfwSetKeyCallback(m_Window, Input::invoke);
			glfwMakeContextCurrent(m_Window);
			glfwSwapInterval(1);

			if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
				throw std::exception("Failed to initialize GLAD.");
			
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_MULTISAMPLE);

			glfwShowWindow(m_Window);
		} break;
	}
}

Window::~Window()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Window::Update() const
{
	glfwPollEvents();
	if (Input::OnKeyDown(GLFW_KEY_ESCAPE))
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
		exit(0);
	}

	switch (m_RendererType)
	{
		case RendererTypes::OpenGL:
		case RendererTypes::OpenGL_M2:
		case RendererTypes::OpenGL_M3:
			glClear(GL_COLOR_BUFFER_BIT);
			break;
	}
}

void Window::Render() const
{
	switch (m_RendererType)
	{
		case RendererTypes::OpenGL:
		case RendererTypes::OpenGL_M2:
		case RendererTypes::OpenGL_M3:
			glfwSwapBuffers(m_Window);
			break;
	}
}
