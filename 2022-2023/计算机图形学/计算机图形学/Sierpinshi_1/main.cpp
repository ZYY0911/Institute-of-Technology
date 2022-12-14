//
//  main.cpp
//  Sierpinshi_1
//
//  Created by 張瀛煜 on 2022/9/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>


GLfloat v[3][2] = {{-1.0,-0.58},{1.0,-0.58},{0.0,1.15}};

int n;


//画一个三角形
void triangle(GLfloat *a ,GLfloat *b,GLfloat *c){
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
}


//剖分三角形
void divide_triangle (GLfloat *a,GLfloat *b,GLfloat *c,int m){
    GLfloat v0[2],v1[2],v2[2];
    int j;
    if (m>0) {
        for (j=0; j<2; j++) {
            v0[j]=(a[j]+b[j])/2;
        }
        for (j=0; j<2; j++) {
            v1[j]=(a[j]+c[j])/2;
        }
        for (j=0; j<2; j++) {
            v2[j]=(b[j]+c[j])/2;
        }
        divide_triangle(a, v0,v1, m-1);
        divide_triangle(c, v1,v2, m-1);
        divide_triangle(b, v2,v0, m-1);
    }else{
        triangle(a, b, c);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    divide_triangle(v[0], v[1], v[2], n);
    glEnd();
    glFlush();
}

void myinit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
}

int main(int argc, char * argv[]) {
    n = 8;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500 ,500);
    glutCreateWindow("2D Gasket");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
