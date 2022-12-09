//
//  main.c
//  彩色立方体2
//
//  Created by 張瀛煜 on 2022/9/27.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <math.h>

const GLubyte mindex[] =
{0,3,2,1,
    2,3,7,6,
    0,4,7,3,
    1,2,6,5,
    4,5,6,7,
    0,1,5,4};

const float vertex[] = { -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0,-1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0 };
const float color[] = { 0, 0, 0, 1.0, 0, 0, 1.0, 1.0, 0, 0, 1.0, 0,0, 0, 1.0, 1.0, 0, 1.0, 1.0, 1.0, 1.0, 0, 1.0, 1.0 };
float angle[] = { 40, 40, 0, 0 };
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    //清除颜色缓存和深度缓存
    glLoadIdentity();
    
    glTranslated(0, 0, -6);
    glRotatef(angle[0], 1, 0, 0);
    glRotatef(angle[1], 0, 1, 0);
    glRotatef(angle[2], 0, 0, 1);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, mindex);      //绘制正方体
    
    glutSwapBuffers();
}

void Reshape(int w, int h){//两个参数：窗口被移动后大小
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initWindow(int argc, char *argv[], int width, int height, char *title){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);       //使用双缓存模式和深度缓存
    glutInitWindowSize(width, height);       //指定窗口大小
    glutCreateWindow(title);
    
    glClearColor(1, 1, 1, 0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);//激活深度测试
    
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertex);
    glColorPointer(3, GL_FLOAT, 0, color);

}

int main(int argc, char *argv[]){
    initWindow(argc, argv, 600, 600, "彩色立方体");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    
    return 0;
}
