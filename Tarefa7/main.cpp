#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int moveEX = 250, moveEY = 200, moveDX = 550 , moveDY = 200;

//Quadrado
void quadrado(){
    glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(250,500);
        glVertex2f(550,500);
        glVertex2f(moveDX,moveDY);
        glVertex2f(moveEX,moveEY);
    glEnd();
}

//PontoMouse
void gerenciaMouse(int botao, int estado, int x, int y){
    if (botao == GLUT_LEFT_BUTTON){
        if(estado == GLUT_DOWN){
            printf("\nBotao esquerdo.");
            printf("\nPressionado na posicao: ");
            moveEX = x;
            moveEY = y;
            printf("(%d, %d)\n", x,y);
        }
    }
    if (botao == GLUT_RIGHT_BUTTON)
        if(estado == GLUT_DOWN){
            printf("\nBotao direito.");
            printf("\nPressionado na posicao: ");
            moveDX = x;
            moveDY = y;
            printf("(%d, %d)\n", x,y);
        }
    if (botao == GLUT_MIDDLE_BUTTON)
        if(estado == GLUT_DOWN){
           printf("\nBotao do meio.");
           printf("\nPressionado na posicao: ");
           moveEX = x;
           moveEY = y;
           moveDX = x;
           moveDY = y;
           printf("(%d, %d)\n", x,y);
        }else{
            moveEX = 250;
            moveEY = 200;
            moveDX = 550;
            moveDY = 200;
        }

    glutPostRedisplay();
}

//MouseAndandoPelaTela
void MouseAndandoNaoPressionado (int x, int y)
{
    printf("\nMouse ANDANDO solto na janela.");
    printf("Posicao: (%d, %d)\n", x,y);
}

//Desenha
void desenhaObjeto(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,600,0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        quadrado();
    glPopMatrix();

	glutSwapBuffers();
	glFlush();
}


int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
     glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2, (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
	glutCreateWindow("Interação com o Mouse");
    glutDisplayFunc(desenhaObjeto);
    glutMouseFunc(gerenciaMouse);
    glutPassiveMotionFunc(MouseAndandoNaoPressionado);
    glClearColor(0,0,0,0);
    glutMainLoop();

    return 0;
}
