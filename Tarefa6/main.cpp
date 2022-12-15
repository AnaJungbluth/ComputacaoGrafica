#include <GL/gl.h>
#include <GL/glut.h>

GLint movepontoY = 90;
GLint movepontoX = 10;
GLint altura = 60;
GLint direcao = 1;

//Ponto
void ponto(){
    glPointSize(40);
    glBegin(GL_POINTS);
        glColor3f(1,0,1);
        glVertex2f(movepontoX,movepontoY);
    glEnd();
}


//Timer
void timerPonto(int passo){
   if(direcao == 1){
        movepontoX += 1;
        movepontoY -= 1;
        if(movepontoY == 40){
            direcao = 2;
        }
   }
   if(direcao == 2 && movepontoX <= 195){
       movepontoX += 1;
       movepontoY += 1;
       if(movepontoY >= altura){
        direcao = 1;
        altura = altura/1.05;
       }
   }

   glutPostRedisplay();
   glutTimerFunc(20,timerPonto,1);

}


//Teclado
void teclas(unsigned char tecla, GLint x, GLint y){
    if(tecla == 'a'){
            glutTimerFunc(20,timerPonto,1);
    }
    glutPostRedisplay();
}


//Desenho
void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,210,0,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        ponto();
    glPopMatrix();

	glutSwapBuffers();
}


int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2, (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
	glutCreateWindow("Timer&Teclado");
    glutDisplayFunc(desenhaObjetos);
    glutKeyboardFunc(teclas);
    glClearColor(0,0,0,0);
    glutMainLoop();
    return 0;
}
