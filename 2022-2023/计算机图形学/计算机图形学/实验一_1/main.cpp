//
//  main.cpp
//  实验一_1
//
//  Created by 張瀛煜 on 2022/9/14.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>


void mydisplay(){
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.2f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();

}


int main(int argc, const char * argv[]) {
    
    GLFWwindow* win;
    if(!glfwInit()){
        return  -1;
    }
    win = glfwCreateWindow(600, 600, "OpenGl Base Project", NULL, NULL);
    if(!win){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    if(!glewInit()){
        return -1;
    }
    
    glfwMakeContextCurrent(win);
    while (!glfwWindowShouldClose(win)) {
        mydisplay();
        
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}

