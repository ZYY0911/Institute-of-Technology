//
//  main.c
//  sphere
//
//  Created by 張瀛煜 on 2022/9/28.
//

#include <stdlib.h>
#include <GLUT/GLUT.h>


void shade(int mode){
    if(mode==1){
        GLfloat light0_pos[]={1.0,1.0,1.0,0.0};
        GLfloat light0_diffuse[]={1.0,1.0,0.0,1.0};
        GLfloat light0_ambient[]={1.0,1.0,0.0,1.0};
        GLfloat light0_specular[]={1.0,1.0,0.0,1.0};
        GLfloat global_ambient[]={0.1,0.1,0.1,1.0};
        
        GLfloat material_ambient[]={1.0,1.0,1.0,1.0};
        GLfloat material_diffuse[]={1.0,1.0,1.0,1.0};
        GLfloat material_specular[]={1.0,1.0,1.0,1.0};
        GLfloat material_shinness = 50.0;
        
        //glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
        glLightfv(GL_LIGHT0,GL_AMBIENT,light0_ambient);
        glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);
        glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_ambient);
        
        //glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,material_ambient);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,material_diffuse);
        //glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,material_specular);
        glMaterialf(GL_FRONT,GL_SHININESS,material_shinness);
    }else if(mode==2){
        GLfloat light0_pos[]={1.0,1.0,1.0,0.0};
        GLfloat light0_diffuse[]={1.0,0.0,0.0,1.0};
        GLfloat light0_ambient[]={1.0,0.0,0.0,1.0};
        GLfloat light0_specular[]={1.0,0.0,0.0,1.0};
        GLfloat global_ambient[]={0.1,0.1,0.1,1.0};
        
        GLfloat material_ambient[]={1.0,1.0,1.0,1.0};
        GLfloat material_diffuse[]={1.0,1.0,1.0,1.0};
        GLfloat material_specular[]={1.0,1.0,1.0,1.0};
        GLfloat material_shinness = 50.0;
        
        glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
        //glLightfv(GL_LIGHT0,GL_AMBIENT,light0_ambient);
        glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);
        glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_ambient);
        
        //glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,material_ambient);
        //glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,material_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,material_specular);
        glMaterialf(GL_FRONT,GL_SHININESS,material_shinness);
    }
}

void inti(void){
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glColor3f (0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-2.0,0.0,0.0);
    shade(1);
    glutSolidSphere(1.0,20,20);
    glTranslatef(4.0,0.0,0.0);
    shade(2);
    glutSolidSphere(1.0,20,20);
    glFlush();
}

void reshape(int w,int h){
    glViewport(0,0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-5.0,5.0,-5.0*(GLfloat) h/(GLfloat) w,5.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
        glOrtho(-5.0*(GLfloat)w/(GLfloat)h,5.0*(GLfloat) w/(GLfloat) h,-5.0,5.0,-10.0,10.0);
    
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200,400);
    glutCreateWindow("Shaded Sphere");
    inti();
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
