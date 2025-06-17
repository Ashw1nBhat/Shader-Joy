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
	glBufferData(GL_ARRAY_BUFFER, sizeof(TRIANGLE_DATA), TRIANGLE_DATA, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &buffer);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}