//
//  main.c
//  基于投影的阴影
//
//  Created by 張瀛煜 on 2022/9/28.
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
float light[] = { 0, 0, 0, 0 };
float theta[] = { 0, 0, 0, 0 };
int axis;
GLfloat m[16];

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    //清除颜色缓存和深度缓存
    glLoadIdentity();
    
    glTranslated(0, 0, -6);
    glRotatef(30, 1.0, 0.0, 0.0);
    glRotatef(180, 0.0, 1.0, 0.0);
    glRotatef(0, 0.0, 0.0, 1.0);

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, mindex);      //绘制正方体
    
   
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glEnd();
    glPushMatrix(); //保存当前矩阵状态
    glTranslatef(light[0], light[1],light[2]); //平移回原位置
    //glMultMatrixf(m); //透视投影
    glTranslatef(-light[0], -light[1],-light[2]); //把光源移动到原点
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glEnd();
    glPopMatrix();//恢复矩阵状态
    glutSwapBuffers();  //清除颜色缓存和深度缓存
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
    for(int i=0;i<16;i++)
        m[i]=0.0;
    m[0]=m[5]=m[10]=1.0;
    m[7]=-1.0/light[1];
    initWindow(argc, argv, 600, 600, "基于投影的阴影");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(Reshape);
   // glutIdleFunc(spinCube);
//    glutMouseFunc(mouse);
//    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
