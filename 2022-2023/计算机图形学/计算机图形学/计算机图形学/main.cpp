//
//  main.cpp
//  计算机图形学
//
//  Created by 張瀛煜 on 2022/9/17.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <algorithm>

const GLubyte mindex[] =
{0,3,2,1,
    2,3,7,6,
    0,4,7,3,
    1,2,6,5,
    4,5,6,7,
    0,1,5,4};

const float vertex[] = { -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0,-1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0 };
const float color[] = { 0, 0, 0, 1.0, 0, 0, 1.0, 1.0, 0, 0, 1.0, 0,0, 0, 1.0, 1.0, 0, 1.0, 1.0, 1.0, 1.0, 0, 1.0, 1.0 };
float speed = 0.1;
int der = 3;        //0x轴，1y轴，2z轴
float angle[] = { 0, 0, 0, 0 };
int pr_x, pr_y;     //上次鼠标位置
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    //清除颜色缓存和深度缓存
    glLoadIdentity();
    
    glTranslated(0, 0, -6
                 );
    glRotatef(angle[0], 1, 0, 0);
    glRotatef(angle[1], 0, 1, 0);
    glRotatef(angle[2], 0, 0, 1);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, mindex);      //绘制正方体
    
    glutSwapBuffers();
}
void idle()
{
    if (der == 3)
        return;
    angle[der] += speed;
    if (angle[der] > 360)
        angle[der] -= 360;
    if (angle[der] < 0)
        angle[der] += 360;
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 27)      //按ESC退出程序
        exit(0);
    else if (key == '+')
        speed =  speed + 1.02;
    else if (key == '-')
        speed = speed - 1.02;
    else if (key == 'x')
        der = 0;
    else if (key == 'y')
        der = 1;
    else if (key == 'z')
        der = 2;
    else if (key == 'p')
        der = 3;
}
void motion(int x,int y)
{
    if (der != 3)
        return;
    if (x > pr_x)
        angle[1] += 1.5;
    if (x < pr_x)
        angle[1] -= 1.5;
    if (y > pr_y)
        angle[0] += 1.5;
    if (y < pr_y)
        angle[0] -= 1.5;
    pr_x = x;
    pr_y = y;
    glutPostRedisplay();
}
void Reshape(int w, int h)      //两个参数：窗口被移动后大小
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initWindow(int &argc, char *argv[], int width, int height, char *title)    //初始化并显示到屏幕中央
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);       //使用双缓存模式和深度缓存      //指定窗口位置
    glutInitWindowSize(width, height);       //指定窗口大小
    glutCreateWindow(title);
    
    glClearColor(1, 1, 1, 0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);//激活深度测试
    
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertex);
    glColorPointer(3, GL_FLOAT, 0, color);
    
    pr_x = width / 2.0;
    pr_y = height / 2.0;
}

int main(int argc, char *argv[])
{
    initWindow(argc, argv, 600, 600, "彩色立方体");
    glutDisplayFunc(myDisplay);
   glutReshapeFunc(Reshape);
    glutIdleFunc(idle);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    
    return 0;
}
