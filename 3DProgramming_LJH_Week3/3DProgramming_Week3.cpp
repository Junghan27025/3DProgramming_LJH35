#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define _USE_MATH_DEFINES
#include <math.h>



#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}


int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(960, 960, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);



        glColor3f(0.0f, 1.0f, 0.0f);
        double rad = 1.0;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < 360; i++)
        {
            double angle, x, y;
            angle = i * 3.141592 / 180;
            x = rad * cos(angle);
            y = rad * sin(angle);

            glVertex2f(x, y);
        }
        glEnd();






        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();








    }

    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}