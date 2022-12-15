#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

void cartesiano(){
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(-50.0, 0.0);
        glVertex2f(50, 0.0);
        glVertex2f(0.0, -50.0);
        glVertex2f(0, 50);
    glEnd();
}

void quadrado1(){
    glColor3f(0.0,0.0,0.1);
    glBegin(GL_QUADS);
        glVertex2f(2, 1);
        glVertex2f(6, 1);
        glVertex2f(6, 4);
        glVertex2f(2, 4);
    glEnd();
}

void triangulo1(){
    glColor3f(0, 1, 0.5);
    glBegin(GL_TRIANGLES);
        glVertex2f(6, 4);
        glVertex2f(2, 4);
        glVertex2f(4, 7);
    glEnd();
}

void quadrado2(){
    glColor3f(0.5, 0, 1);
    glBegin(GL_QUADS);
        glVertex2f(10, 6);
        glVertex2f(11, 6);
        glVertex2f(11, 7);
        glVertex2f(10, 7);
    glEnd();
}

void quadrado3(){
    glColor3f(0.5, 0, 1);
    glBegin(GL_QUADS);
        glVertex2f(11, 7);
        glVertex2f(12, 7);
        glVertex2f(12, 8);
        glVertex2f(11, 8);
    glEnd();
}

void quadrado4(){
    glColor3f(0.5, 0, 1);
    glBegin(GL_QUADS);
        glVertex2f(11,8);
        glVertex2f(11, 9);
        glVertex2f(10, 9);
        glVertex2f(10, 8);
    glEnd();
}

void quadrado5(){
    glColor3f(0.5, 0, 1);
    glBegin(GL_QUADS);
        glVertex2f(9, 7);
        glVertex2f(10, 7);
        glVertex2f(10, 8);
        glVertex2f(9, 8);
    glEnd();
}

void quadrado6(){
    glColor3f(1, 0.84, 0);
    glBegin(GL_QUADS);
        glVertex2f(13, 0);
        glVertex2f(15, 0);
        glVertex2f(15, 2);
        glVertex2f(13, 2);
    glEnd();
}

void triangulo2(){
    glColor3f(0.53, 0.81, 0.92);
    glBegin(GL_TRIANGLES);
        glVertex2f(15, 2);
        glVertex2f(13, 2);
        glVertex2f(14, 4);
    glEnd();
}

void quadrado7(){
    glColor3f(0, 0.1, 0);
    glBegin(GL_QUADS);
        glVertex2f(17, 2);
        glVertex2f(22, 2);
        glVertex2f(22, 5);
        glVertex2f(17, 5);
    glEnd();
}

void triangulo3(){
    glColor3f(0.75, 1, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(22, 5);
        glVertex2f(17, 5);
        glVertex2f(19.5, 9);
    glEnd();
}

void escala(){
     glRotatef(75, 0, 0, 1);
     quadrado1();
     quadrado2();
     quadrado3();
     quadrado4();
     quadrado5();
     quadrado6();
     quadrado7();
     triangulo1();
     triangulo2();
     triangulo3();
}



void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-60,60,-60,60);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
         cartesiano();
    glPopMatrix();

    glPushMatrix();
         quadrado1();
    glPopMatrix();

    glPushMatrix();
         quadrado2();
    glPopMatrix();

    glPushMatrix();
         quadrado3();
    glPopMatrix();

    glPushMatrix();
         quadrado4();
    glPopMatrix();

    glPushMatrix();
         quadrado5();
    glPopMatrix();

    glPushMatrix();
         quadrado6();
    glPopMatrix();

    glPushMatrix();
         quadrado7();
    glPopMatrix();

    glPushMatrix();
         triangulo1();
    glPopMatrix();

    glPushMatrix();
         triangulo2();
    glPopMatrix();

    glPushMatrix();
         triangulo3();
    glPopMatrix();

     glPushMatrix();
         escala();
    glPopMatrix();

	glFlush();

}

int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("Introdução ao OpenGL");
    glutDisplayFunc(desenhaObjetos);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}
