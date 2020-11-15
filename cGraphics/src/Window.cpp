#include "headers/Window.h"

namespace Engine {

    void frameBufferSizeCallback(GLFWwindow* window, int width, int height) 
    {
        glViewport(0, 0, width, height);
    }

    bool Window::init()
    {
        if (!glfwInit()) {
            std::cout << "Failed to start GLFW" << std::endl;
            return 0;
        }

        window = glfwCreateWindow(w_width, w_height, w_title, NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            std::cout << "Failed to create GLFW window" << std::endl;
            return 0;
        }

        glfwMakeContextCurrent(window);

        glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
        return 1;
    }

    Window::Window(const char* title, int width, int height)
    {
        w_title = title;
        w_width = width;
        w_height = height;

        if (!init()) 
        {
            glfwTerminate();
        }
    }

    void Window::clear() const 
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::update()
    {
        // glfwGetFramebufferSize(window, &w_width, &w_height);
        // std::cout << "window size:" << w_width << "," << w_height << std::endl;
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    bool Window::closed() const 
    {
        return glfwWindowShouldClose(window);
    }
}

