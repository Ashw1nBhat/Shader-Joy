#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const float TRIANGLE_DATA[] = {
	0, 1, 0, 1, 0, 0,
	-1, -1, 0, 0, 1, 0,
	1, -1, 0, 0, 0, 1
};

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

	GLuint buffer = 0;
	glGenBuffers(1, &buffer);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(buffer, sizeof(TRIANGLE_DATA), TRIANGLE_DATA, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &buffer);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}