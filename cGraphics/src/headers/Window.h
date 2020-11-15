#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine {

	class Window {

	private:
		const char* w_title;
		int w_width, w_height;
		GLFWwindow* window;
		bool w_closed;

		bool init();
	public:
		Window(const char* title, int width, int height);

		void update();
		void clear() const;
		bool closed() const;
	};
}
