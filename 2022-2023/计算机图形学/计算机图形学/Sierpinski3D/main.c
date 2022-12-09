//
//  main.c
//  Sierpinski3D
//
//  Created by 張瀛煜 on 2022/9/21.
//


#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>


GLfloat v[4][3] = {{0.0,0.0,1.0},{0.0,0.942809,-0.33333}
    ,{-0.816497,-0.471405,-0.33333},{0.816497,-0.471405,-0.33333}};

int n;


//画一个三角形
void triangle(GLfloat *a ,GLfloat *b,GLfloat *c){
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
}

GLfloat colors[4][3] = {{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,0.0,0.0}};

void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d){
    glColor3fv(colors[0]);
    triangle(a, b, c);
    glColor3fv(colors[1]);
    triangle(a,c,d);
    glColor3fv(colors[2]);
    triangle(a, d,b);
    glColor3fv(colors[3]);
    triangle(b, d,c);
}


void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m){
    GLfloat mid[6][3];
    int j;
    if (m>0) {
        for (j=0; j<3; j++) {
            mid[0][j]=(a[j]+b[j])/2;
        }
        for (j=0; j<3; j++) {
            mid[1][j]=(a[j]+c[j])/2;
        }
        for (j=0; j<3; j++) {
            mid[2][j]=(a[j]+d[j])/2;
        }
        for (j=0; j<3; j++) {
            mid[3][j]=(b[j]+c[j])/2;
        }
        for (j=0; j<3; j++) {
            mid[4][j]=(c[j]+d[j])/2;
        }
        for (j=0; j<3; j++) {
            mid[5][j]=(b[j]+d[j])/2;
        }
        divide_tetra(a,mid[0],mid[1], mid[2],m-1);
        divide_tetra(mid[0],b,mid[3], mid[5],m-1);
        divide_tetra(mid[1],mid[3], c,mid[4],m-1);
        divide_tetra(mid[2],mid[4], d,mid[5],m-1);
        
    }else{
        tetra(a, b, c,d);
    }
}

void display(void){
    
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    divide_tetra(v[0], v[1], v[2],v[3], n);
    glEnd();
    glFlush();
}

void myReshape(int w,int h){
    glViewport(2, 0, w, h );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h){
        glOrtho(-2.0, 2.0, -2.0*(GLfloat) h/(GLfloat)w, 2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    }else{
        glOrtho(-2.0*(GLfloat) h/(GLfloat)w, 2.0*(GLfloat)h/(GLfloat)w, -2.0, 2.0,-10.0,10.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
    
}

int main(int argc, char * argv[]) {
    n = 5;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500 ,500);
    glutCreateWindow("3D Gasket");
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
    return 0;
}
