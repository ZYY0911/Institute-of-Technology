//
//  main.c
//  多边形绘制
//
//  Created by 張瀛煜 on 2022/9/25.
//

#include <stdio.h>
#include<GLUT/GLUT.h>
int width = 500,height= 500;

void  init(){
    glViewport(0, 0,width ,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glMatrixMode(GL_PROJECTION);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0);
}

void myDispaly(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char * argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(width ,height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("square");
    glutDisplayFunc(myDispaly);
    init();
    return 0;
}
