//
//  main.c
//  彩色立方体
//
//  Created by 張瀛煜 on 2022/9/21.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
GLfloat vertices[8][3] =
{{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
    {1.0,1.0,-1.0}, {-1.0,1.0,-1.0},
    {-1.0,-1.0,1.0},{1.0,-1.0,1.0},
    {1.0,1.0,1.0}, {-1.0,1.0,1.0}};
typedef GLfloat point3[3];

GLfloat colors[8][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},
    {0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0},
    {0.0,1.0,1.0}};

GLubyte cubeIndices[24] =
{0,3,2,1,
    2,3,7,6,
    0,4,7,3,
    1,2,6,5,
    4,5,6,7,
    0,1,5,4};


//定义一个面
void polygon(int a,int b,int c ,int d){
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}

void colorcube(void){
    polygon(0, 3, 2, 1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0, 0, -6);
    glRotatef(40, 1.0, 0.0, 0.0);
    glRotatef(40, 0.0, 1.0, 0.0);
    glRotatef(0, 0.0, 0.0, 1.0);
    colorcube();
    glutSwapBuffers();
}

void myReshape(int w, int h)  {    //两个参数：窗口被移动后大小{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |
                        GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("彩色立方体");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
