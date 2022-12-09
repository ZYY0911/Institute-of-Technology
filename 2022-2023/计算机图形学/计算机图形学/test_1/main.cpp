//
//  main.cpp
//  Demotext
//
//  Created by 張瀛煜 on 2022/9/14.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

GLfloat size = 30;
GLint winWitdh = 500,winHeight=500;
void  init(){
    glViewport(0, 0,winWitdh ,winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,(GLdouble)winWitdh, 0.0, (GLdouble)winHeight, -1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0);
}

void myDispaly(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void drawSquare(int x, int y ){
    y = 500- y;
    glBegin(GL_POLYGON);
    glVertex2f(x+size, y+size);
    glVertex2f(x-size, y+size);
    glVertex2f(x-size, y-size);
    glVertex2f(x+size, y-size);
    glEnd();
    glFlush();
}

void mymouse(int btn , int state ,int x ,int y){
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        exit(0);
    }
    if (btn==GLUT_LEFT_BUTTON && state ==GLUT_DOWN) {
        drawSquare(x, y);
    }
    
}

void myReshape(int w ,int h){
    winWitdh = w;
    winHeight = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, (GLdouble)winWitdh, 0.0, (GLdouble)winHeight, -1.0, 1.0);
    glViewport(0, 0, winWitdh, winHeight);
}


void mykey(unsigned char key , int x  ,int y){
    if (key=='Q' | key == 'q') {
        exit(0);
    }
}
void demo_menu(int id){
    switch (id) {
        case 1:
            size = 2*size;
            break;
        case 2 :
            if(size>1)
                size = size/2;
            break;
    }
}

void color_menu(int id){
    switch (id) {
        case 0 :
            glColor3f(1.0, 1.0, 1.0);
            break;
        case 1:
            glColor3f(1.0f, 0.0f, 0.0f);
            break;
        case 2:
            glColor3f(0.0f, 0.0f, 1.0f);
            break;
        case 3:
            glColor3f(0.0f, 1.0f, 0.0f);
            break;
        default:
            break;
    }
}

void top_menu(int id)
{
    switch (id) {
        case 1:
            exit(0);
            break;
    }
}

int main(int argc, char * argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(winWitdh ,winHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("square");
    glutDisplayFunc(myDispaly);
    init();
    //点击绘制
    //glutMouseFunc(mymouse);
    //按住鼠标左键
    glutMotionFunc(drawSquare);
    glutKeyboardFunc(mykey);
    glutReshapeFunc(myReshape);
    //创建菜单
    int sub_menu=   glutCreateMenu(demo_menu);
    
    glutAddMenuEntry("Increase square size", 1);
    glutAddMenuEntry("Decrease square size", 2);
    
    //颜色菜单
    int col_menu = glutCreateMenu(color_menu);
    glutAddMenuEntry("White",0);
    glutAddMenuEntry("Red",1);
    glutAddMenuEntry("Blue",2);
    glutAddMenuEntry("Green",3);
    
    
    int menu = glutCreateMenu(top_menu);
    glutAddMenuEntry("Quit", 1);
    glutAddSubMenu("Resize", sub_menu);
    glutAddSubMenu("Color",col_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutMainLoop();
    return 0;
}
