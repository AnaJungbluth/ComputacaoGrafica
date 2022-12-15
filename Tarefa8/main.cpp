#include <GL/gl.h>
#include <GL/glut.h>

GLfloat r = 1, g = 1, b = 1;
int movexA = -5, moveyA = -5, movexB = -5, moveyB = 5,
movexC = 5, moveyC = 5, movexD = 5, moveyD = -5,
submenucor, submenuformato;

//Quadrado
void quadrado(){
    glBegin(GL_QUADS);
        glVertex2f(movexA, moveyA);
        glVertex2f(movexB, moveyB);
        glVertex2f(movexC, moveyC);
        glVertex2f(movexD, moveyD);
    glEnd();
}

//Desenha
void desenhaObjeto(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30,30,-30,30);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(r, g, b);
    glPushMatrix();
        quadrado();
    glPopMatrix();

 	glutSwapBuffers();
}

//MontaCor
void escolheCor(int op){
    switch(op){
        case 0:
            r = 1;
            g = 0;
            b = 0;
        break;
        case 1:
            r =  0.75;
            g = 1;
            b = 0;
        break;
        case 2:
            r = 0;
            g = 0.5;
            b = 1;
        break;
    }
    glutPostRedisplay();
}

//MontaFormato
void escolheFormato(int op){
    switch(op){
        case 0:
            movexA = -5;
            moveyA = -5;
            movexB = 0;
            moveyB = 5;
            movexC = 0;
            moveyC = 5;
            movexD = 5;
            moveyD = -5;
        break;
        case 1:
            movexA = -5;
            moveyA = -5;
            movexB = -5;
            moveyB = 5;
            movexC = 5;
            moveyC = 5;
            movexD = 5;
            moveyD = -5;
        break;
        case 2:
            movexA = -5;
            moveyA = 0;
            movexB = 0;
            moveyB = -5;
            movexC = 5;
            moveyC = 0;
            movexD = 0;
            moveyD = 5;
        break;
    }
    glutPostRedisplay();
}

//MenuCores
void menuCor(){
    submenucor = glutCreateMenu(escolheCor);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Lima", 1);
    glutAddMenuEntry("Azul celeste brilhante", 2);
}

//MenuFormatos
void menuFormato(){
    submenuformato = glutCreateMenu(escolheFormato);
    glutAddMenuEntry("Triangulo", 0);
    glutAddMenuEntry("Quadrado", 1);
    glutAddMenuEntry("Losango", 2);
}

//Menu
void criaMenu(){
    menuCor();
    menuFormato();
    glutCreateMenu(0);
    glutAddSubMenu("Escolha a Cor", submenucor);
    glutAddSubMenu("Escolha o Formato", submenuformato);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

//BotaoMouse
void gerenciaMouse(int botao, int estado, int x, int y){
    if(botao == GLUT_LEFT_BUTTON)
        if(estado == GLUT_DOWN){
            criaMenu();
        }
    glutPostRedisplay();
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
	glutCreateWindow("MenuInteração");
    glutDisplayFunc(desenhaObjeto);
    glutMouseFunc(gerenciaMouse);
    glClearColor(0,0,0,0);
    glutMainLoop();
    return 0;
}
