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

void pontos(){
    glPointSize(6);
    glColor3f(1,0,0);

    glBegin(GL_POINTS);
        glVertex2f(7, 20);
        glVertex2f(7, 15);
        glVertex2f(4, 10);
        glVertex2f(1, 15);
        glVertex2f(1, 20);
    glEnd();

}

void poligono(){
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2f(4, 25);
        glVertex2f(7, 20);
        glVertex2f(7, 15);
        glColor3f(0, 0, 1);
        glVertex2f(4, 10);
        glVertex2f(1, 15);
        glVertex2f(1, 20);
    glEnd();
}

void rotacao(){
    glRotatef(30,0,0,1);
    poligono();
    pontos();
}

void escala(){
    glScalef(2, 2, 2);
    poligono();
    pontos();
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
        poligono();
    glPopMatrix();

    glPushMatrix();
        pontos();
    glPopMatrix();

    glPushMatrix();
        escala();
    glPopMatrix();

    glPushMatrix();
        rotacao();
    glPopMatrix();

	glFlush();
}

int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("ProvaTeorica");
    glutDisplayFunc(desenhaObjetos);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}
