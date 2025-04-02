#include "iostream"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

#include "Shader.h"

void DefineVertex();

GLuint VAO;
GLuint VBO;
GLuint FBO;
GLuint shaderProgram;

void DefineVertex()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // VBO para os vértices
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    std::vector<GLfloat> vertex{
        // posição           
         0.5f,  0.5f,  0.0f,    // Vértice superior direito
         0.0f, -0.5f,  0.0f,    // Vértice inferior
        -0.5f,  0.5f,  0.0f,
    };

    glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(GL_FLOAT), vertex.data(), GL_STATIC_DRAW);

    // Atributo de posição (local 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // FBO para as cores
    glGenBuffers(1, &FBO);
    glBindBuffer(GL_ARRAY_BUFFER, FBO);

    std::vector<GLfloat> fragColor{
       0.7f, 0.7f, 1.0f,
       1.0f, 0.0f, 0.0f,
       0.5f, 1.0f, 0.0f
    };

    glBufferData(GL_ARRAY_BUFFER, fragColor.size() * sizeof(GL_FLOAT), fragColor.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(1);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(680, 480, "All by myself", NULL, NULL);
    if (window == NULL) {
        std::cout << "Window creation failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    DefineVertex();
    Shader shader1("shaderVert.glsl", "shaderFrag.glsl");

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        shader1.Use();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //shader1.UpdateOffset();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}