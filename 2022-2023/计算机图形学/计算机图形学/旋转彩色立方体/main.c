//
//  main.c
//  旋转彩色立方体
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
float theta[] = { 0, 0, 0, 0 };
int axis;
float scaled[]= {1.0f,1.0f,1.0f};
float tranXYZ = 0.0;

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    //清除颜色缓存和深度缓存
    glLoadIdentity();
    
    glTranslated(0, 0, -6);
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    //旋转，参数含义(旋转量,x轴,y轴,z轴)
    glScaled(scaled[0],scaled[1],scaled[2]);
    
    glTranslatef(tranXYZ, tranXYZ, 0);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, mindex);      //绘制正方体
    
    glutSwapBuffers();
}


void spinCube(void){
    theta[axis] += 2.0;
    if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
    glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y){
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        axis = 0;
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        axis = 1;
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        axis = 2;
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

void keyboard(unsigned char key, int x, int y){
    if (key == 'x'){
        theta[0]+=30;
        glutPostRedisplay();
    }else if (key == 'y'){
            theta[1]+=30;
        glutPostRedisplay();
    }else if (key == 'z'){
            theta[2] +=30;
            glutPostRedisplay();
    }else if(key=='t'){
        tranXYZ = -1.0f;
        glutPostRedisplay();
    }else if(key=='s'){
        scaled[0] = 2.0f;
        scaled[1] = 0.5f;
        scaled[2] = 1.5f;
        glutPostRedisplay();
    }
}
int main(int argc, char *argv[]){
    initWindow(argc, argv, 600, 600, "旋转彩色立方体");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(Reshape);
    //glutIdleFunc(moveDisplay);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
