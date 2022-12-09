//
//  main.c
//  直线绘制
//
//  Created by 張瀛煜 on 2022/9/22.
//

#include <stdio.h>
#include <GLUT/GLUT.h>

void diaplay(void){
    void  myDrawFun(int i );
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth((GLfloat)5);
    myDrawFun(1);
}

void myDrawFun(int i){
    int p1[] = {1,1};
    int p2[] = {5,4};
    int p3[] = {1,4};
    int p4[] = {5,1};
    int p5[] = {3,5};
    glClear(GL_COLOR_BUFFER_BIT);
    if(i==1)glBegin(GL_LINES);
    else if(i==2)glBegin(GL_LINE_STRIP);
    else {glBegin(GL_LINE_LOOP);
        glLineStipple((GLint)5, 0X100f);
    }
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
    glVertex2iv(p5);
    glEnd();
    glFlush();
}


void polygonTriangle(int id){
    int p1[] = {1,3};
    int p2[] = {3,0};
    int p3[] = {6,0};
    int p4[] = {7,3};
    int p5[] = {6,6};
    int p6[] = {3,6};
    int p7[] = {4,8};
    int p8[] = {5,8};
    int p9[] = {2,8};
    int p10[] = {1,0};
    int p11[] = {8,9};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.8, 0.5);
    glPointSize(3);
    if(id==4){
        glBegin(GL_POLYGON);//多边形
    }else if(id==5){
        glBegin(GL_TRIANGLES);//三角形
    }else if(id==6){
        glBegin(GL_QUADS);
    }
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
    glVertex2iv(p5);
    glVertex2iv(p6);
    glVertex2iv(p7);
    glVertex2iv(p8);
    glVertex2iv(p9);
    glVertex2iv(p10);
    glVertex2iv(p11);
    glEnd();
    glFlush();
}

void ChangeSize(GLsizei w,GLsizei h){
    if (h==0) {
        h=1;
    }
    //设置视区尺寸
    glViewport(0, 0, w, h);
    //重置坐标系统，使用投影变换复位
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w<=h) {
        glOrtho (0.0f,250.0f, 0.0f,250.0f*h/w, 1.0f, -1.0f);
    }else{
        glOrtho (0.0f,250.0f*w/h, 0.0f,250.0f, 1.0f, -1.0f);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myMenu(int id){
    if(id<=3){
        myDrawFun(id);
    }else{
        polygonTriangle(id);
    }
}

void addmenu(void){
    int sub_menu=   glutCreateMenu(myMenu);
    
    glutAddMenuEntry("GL_LINES", 1);
    glutAddMenuEntry("GL_GLINE_STRIP", 2);
    glutAddMenuEntry("GL_LINE_LOOP", 3);
    glutAddMenuEntry("多边形", 4);
    glutAddMenuEntry("三角形", 5);
    glutAddMenuEntry("四边形", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


//自定义函数
void init(){
    //rgb都是1,黑色背景颜色
    glClearColor(1.0,1.0,1.0,0.0);
    //正投影方式
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //显示的范围,超过部分不会显示出来
    gluOrtho2D(-10,20,-10,20);
}

int main(int argc, char * argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(600 ,600);
    glutCreateWindow("直线绘制");
    init();
    addmenu();
    glutDisplayFunc(diaplay);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
    return 0;
}
