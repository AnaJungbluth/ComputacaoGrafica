#include <GL/gl.h>
#include <GL/glut.h>

float win, aspecto;
int largura, altura;
GLfloat escala = 1, movepontoX = 0, movepontoY = 0, rotacao = 0, r = 0, g = 0.39, b = 0;
GLint direcao = 1;

void timerLinha(int passo);

//Quadrado
void quadrado(){
    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2f(-10, -10);
        glVertex2f(-10, 10);
        glVertex2f(10, 10);
        glVertex2f(10, -10);
    glEnd();
}

//Triangulo
void triangulo(){
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0.75, 0);
        glVertex2f(-10, -10);
        glVertex2f(0, 10);
        glVertex2f(10, -10);
    glEnd();
}

//Teclas
void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': escala++;
        break;
        case '-': escala--;
        break;
    }
    glutPostRedisplay();
}

//Ponto
void ponto(){
   glPointSize(15);
    glColor3f(0, 0.75, 1);

    glBegin(GL_POINTS);
        glVertex2f(0, 0);
    glEnd();
}

//TecladoSetas
void setasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){
        case GLUT_KEY_LEFT: movepontoX--;
        break;
        case GLUT_KEY_RIGHT: movepontoX++;
        break;
        case GLUT_KEY_UP: movepontoY++;
        break;
        case GLUT_KEY_DOWN: movepontoY--;
        break;
    }
    glutPostRedisplay();
}

//ContornoViewport
void contorno(){
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glColor3f(1,1,1);
        glVertex2f(-win*aspecto, -win);
        glVertex2f(-win*aspecto, win);
        glVertex2f(win*aspecto, win);
        glVertex2f(win*aspecto, -win);
    glEnd();
}

//Linha
void linha(){
    glLineWidth(5);
    glColor3f(0.6, 0.2, 0.8);

    glBegin(GL_LINE_STRIP);
        glVertex2f(-10, 0);
        glVertex2f(10, 0);
    glEnd();
}

//ClickMouse
void gerenciaMouse(int botao, int estado, int x, int y){
    if (botao == GLUT_RIGHT_BUTTON){
        if(estado == GLUT_DOWN){
            if(r >= 1 && g >= 1 && b >= 1){
                r = 0;
                g = 0.39;
                b = 0;
            }else{
                if(r <= 1){
                    r += 0.4;
                }else if(g <= 1){
                    g += 0.4;
                }else if(b <= 1){
                    b += 0.4;
                }
            }
        }
    }
    if (botao == GLUT_LEFT_BUTTON){
        if(estado == GLUT_DOWN){
            glutTimerFunc(10,timerLinha,1);
        }
    }
    glutPostRedisplay();
}

//LinhaRotacionando
void timerLinha(int passo){
    if (direcao == 1){
        rotacao+= 1;
    }

    glutPostRedisplay();
    glutTimerFunc(10,timerLinha,1);
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);

    //TopoEsquerdo
	glViewport(0, altura, largura, altura);
    glPushMatrix();
		contorno();
		quadrado();
	 glPopMatrix();

	 //TopoDireito
    glViewport(largura, altura, largura, altura);
    glPushMatrix();
		contorno();
		glScalef(escala, escala, 0);
		triangulo();
	 glPopMatrix();

    //BaixoEsquerda
	glViewport(0, 0, largura, altura);
	glPushMatrix();
		contorno();
		glTranslatef(movepontoX, movepontoY, 0);
		ponto();
	 glPopMatrix();

    //BaixoDireita
	glViewport(largura, 0, largura, altura);
    glPushMatrix();
		contorno();
		glRotatef(rotacao, 0,0,1);
		linha();
	 glPopMatrix();

	 glutSwapBuffers();
}

//TamanhoJanela
void alteraTamanhoJanela(GLsizei w, GLsizei h){
    if(h == 0) h = 1;
    largura = w/2;
    altura = h/2;

    aspecto = (float) largura / altura;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-win*aspecto, win*aspecto, -win, win);
}

//Inicializa
void inicializa(){
     glClearColor(0,0,0,0);
     win = 40;
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
	glutCreateWindow("Viewport");
    glutDisplayFunc(desenhaObjetos);
    glutReshapeFunc(alteraTamanhoJanela);
    glutKeyboardFunc(teclas);
    glutSpecialFunc(setasDirecionais);
    glutMouseFunc(gerenciaMouse);
    inicializa();
    glutMainLoop();
    return 0;
}
