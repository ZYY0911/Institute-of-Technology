//
//  main.c
//  demo
//
//  Created by 張瀛煜 on 2022/10/15.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <math.h>
//
//
//typedef float point[4];
//
///* initial tetrahedron */
//
//point v[]={{0.0, 0.0, 1.0}, {0.0, 0.942809, -0.33333},
//          {-0.816497, -0.471405, -0.333333}, {0.816497, -0.471405, -0.333333}};
//
//int n;
//int mode;
//
//
//void triangle( point a, point b, point c)
//
///* display one triangle using a line loop for wire frame, a single
//normal for constant shading, or three normals for interpolative shading */{
//    if (mode==0) glBegin(GL_LINE_LOOP);
//    else glBegin(GL_POLYGON);
//       if(mode==1) glNormal3fv(a);
//       if(mode==2) glNormal3fv(a);
//       glVertex3fv(a);
//       if(mode==2) glNormal3fv(b);
//       glVertex3fv(b);
//       if(mode==2) glNormal3fv(c);
//       glVertex3fv(c);
//    glEnd();
//}
//
//void mnormal(point p){
//
///* normalize a vector */
//
//    double sqrt();
//    float d =0.0;
//    int i;
//    for(i=0; i<3; i++) d+=p[i]*p[i];
//    d=sqrt(d);
//    if(d>0.0) for(i=0; i<3; i++) p[i]/=d;
//}
//
//void divide_triangle(point a, point b, point c, int m){
//
///* triangle subdivision using vertex numbers
//righthand rule applied to create outward pointing faces */
//
//    point v1, v2, v3;
//    int j;
//    if(m>0){
//        for(j=0; j<3; j++) v1[j]=a[j]+b[j];
//        mnormal(v1);
//        for(j=0; j<3; j++) v2[j]=a[j]+c[j];
//        mnormal(v2);
//        for(j=0; j<3; j++) v3[j]=b[j]+c[j];
//        mnormal(v3);
//        divide_triangle(a, v1, v2, m-1);
//        divide_triangle(c, v2, v3, m-1);
//        divide_triangle(b, v3, v1, m-1);
//        divide_triangle(v1, v3, v2, m-1);
//    }
//    else(triangle(a,b,c)); /* draw triangle at end of recursion */
//}
//
//void tetrahedron( int m){
//
///* Apply triangle subdivision to faces of tetrahedron */
//
//    divide_triangle(v[0], v[1], v[2], m);
//    divide_triangle(v[3], v[2], v[1], m);
//    divide_triangle(v[0], v[3], v[1], m);
//    divide_triangle(v[0], v[2], v[3], m);
//}
//
//void display(void){
//
///* Displays all three modes, side by side */
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//       glLoadIdentity();
//    mode=0;
//    tetrahedron(n);
//    mode=1;
//    glTranslatef(-2.0, 0.0,0.0);
//    tetrahedron(n);
//    mode=2;
//    glTranslatef( 4.0, 0.0,0.0);
//    tetrahedron(n);
//
//
//    glFlush();
//}
//
//
//void myReshape(int w, int h){
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    if (w <= h)
//        glOrtho(-4.0, 4.0, -4.0 * (GLfloat) h / (GLfloat) w,
//            4.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
//    else
//        glOrtho(-4.0 * (GLfloat) w / (GLfloat) h,
//            4.0 * (GLfloat) w / (GLfloat) h, -4.0, 4.0, -10.0, 10.0);
//    glMatrixMode(GL_MODELVIEW);
//    display();
//}
//
//
//void myinit(){
//    GLfloat mat_specular[]={1.0, 1.0, 1.0, 1.0};
//    GLfloat mat_diffuse[]={1.0, 1.0, 1.0, 1.0};
//    GLfloat mat_ambient[]={1.0, 1.0, 1.0, 1.0};
//    GLfloat mat_shininess={100.0};
//    GLfloat light_ambient[]={0.0, 0.0, 0.0, 1.0};
//    GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
//    GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};
//
///* set up ambient, diffuse, and specular components for light 0 */
//
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//
///* define material proerties for front face of all polygons */
//
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glShadeModel(GL_SMOOTH); /*enable smooth shading */
//    glEnable(GL_LIGHTING); /* enable lighting */
//    glEnable(GL_LIGHT0);  /* enable light 0 */
//    glEnable(GL_DEPTH_TEST); /* enable z buffer */
//
//    glClearColor (1.0, 1.0, 1.0, 1.0);
//    glColor3f (0.0, 0.0, 0.0);
//}
//
//
//void main(int argc, char **argv){
//    n=5;
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("sphere");
//    myinit();
//    glutReshapeFunc(myReshape);
//    glutDisplayFunc(display);
//    glutMainLoop();
//}


static int day = 200; // day的变化：从0到359
void myDisplay(void)
{
    //glEnable(GL_DEPTH_TEST); //启动深度测试（这样后绘制的图形如果在已经存在的图形的前面，它会被遮住，而不是遮住别人
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清空颜色和深度缓冲
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 10, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

    // 绘制红色的“太阳”
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    // 绘制蓝色的“地球”
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    // 绘制黄色的“月亮”
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day / 30.0 * 360.0 - day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 20, 20);

    glFlush();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);//对GLUT进行初始化，这个函数必须在其它的GLUT使用之前调用一次
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //设置显示方式
    glutInitWindowPosition(100, 100); //设置窗口位置
    glutInitWindowSize(400, 400);//窗口大小
    glutCreateWindow("我的OpenGL程序"); //根据前面设置的信息创建窗口。参数将被作为窗口的标题。
    glutDisplayFunc(&myDisplay); //当需要画图时，请调用myDisplay函数
    glutMainLoop(); //进行一个消息循环
    return 0;
}
