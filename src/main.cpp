#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
	if (!glfwInit()) {
		std::cout << "GLFW initialization failed" << "\n";
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Shader Joy", NULL, NULL);
	if (!window) {
		std::cout << "GLFW window creation failed" << "\n";
		return 1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD initialization failed" << "\n";
		return 1;
	}

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}