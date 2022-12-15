#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

float win, aspecto;
int largura, altura, r = 1, g = 1, b = 0, tipoCor = 1,
ar1 = 0 , ag1 = 1, ab1 = 0, ar2 = 1, ag2 = 0, ab2 = 0,  submenutransformacao;
GLfloat translacao1 = 0, translacao2 = 0, escala = 1;

//Cenario1
//Chao
void chao1(){
    glBegin(GL_QUADS);
        glColor3f(0.13, 0.55, 0.13);
        glVertex2f(-33, -50);
        glVertex2f(-33, -35);
        glVertex2f(33, -35);
        glVertex2f(33, -50);
    glEnd();
}

//Casa
void casa1(){
    glBegin(GL_QUADS);
        glColor3f(0.86, 0.08, 0.24);
        glVertex2f(10, -20);
        glVertex2f(10, -40);
        glVertex2f(30, -40);
        glVertex2f(30, -20);
    glEnd();
}

void teto1(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.86, 0.44, 0.58);
        glVertex2f(10, -20);
        glVertex2f(20, -5);
        glVertex2f(30, -20);
    glEnd();
}

void janelas1(){
    glPointSize(15);
    glBegin(GL_POINTS);
        glColor3f(r,g,b);
        glVertex2f(15, -25);
        glVertex2f(15, -30);
        glVertex2f(20, -25);
        glVertex2f(20, -30);
        glVertex2f(25, -25);
        glVertex2f(25, -30);
    glEnd();
}

void porta1(){
    glBegin(GL_QUADS);
        glColor3f(0.55, 0.34, 0.26);
        glVertex2f(19, -35);
        glVertex2f(19, -40);
        glVertex2f(22, -40);
        glVertex2f(22, -35);
    glEnd();
}

void tronco1(){
    glBegin(GL_QUADS);
        glColor3f(0.24, 0.17, 0.12);
        glVertex2f(-10, -30);
        glVertex2f(-10, -40);
        glVertex2f(-14, -40);
        glVertex2f(-14, -30);
    glEnd();
}

void folha1(){
    glColor3f(ar1, ag1, ab1);
    glBegin(GL_POLYGON);
        glVertex2f(-7, -30);
        glVertex2f(-18, -30);
        glVertex2f(-18, -27);
        glVertex2f(-21, -27);
        glVertex2f(-21, -20);
        glVertex2f(-18, -20);
        glVertex2f(-18, -17);
        glVertex2f(-7, -17);
        glVertex2f(-7, -20);
        glVertex2f(-4, -20);
        glVertex2f(-4, -27);
        glVertex2f(-7, -27);
        glVertex2f(-7, -30);
    glEnd();
}

void sol1(){
    glColor3f(1, 0.75, 0);
    glBegin(GL_POLYGON);
        for(int i = 0; i < 350; i++){
            float theta = i*M_PI/180;
            glVertex2f (15+5*cos(theta), 40+5*sin(theta));
        }
    glEnd();
}


//Cenario2
//Chao
void chao2(){
    glBegin(GL_QUADS);
        glColor3f(0.13, 0.55, 0.13);
        glVertex2f(-33, -50);
        glVertex2f(-33, -32);
        glVertex2f(33, -32);
        glVertex2f(33, -50);
    glEnd();
}

//Casa
void casa2(){
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0.8);
        glVertex2f(10, -20);
        glVertex2f(10, -40);
        glVertex2f(30, -40);
        glVertex2f(30, -20);
    glEnd();
}

void teto2(){
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0.98, 0.6);
        glVertex2f(10, -20);
        glVertex2f(20, -5);
        glVertex2f(30, -20);
    glEnd();
}

void janelas2(){
    glPointSize(15);
    glBegin(GL_POINTS);
        glColor3f(r,g,b);
        glVertex2f(15, -25);
        glVertex2f(15, -30);
        glVertex2f(20, -25);
        glVertex2f(20, -30);
        glVertex2f(25, -25);
        glVertex2f(25, -30);
    glEnd();
}

void porta2(){
    glBegin(GL_QUADS);
        glColor3f(0.55, 0.27, 0.07);
        glVertex2f(19, -35);
        glVertex2f(19, -40);
        glVertex2f(22, -40);
        glVertex2f(22, -35);
    glEnd();
}

void tronco2(){
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex2f(-10, -30);
        glVertex2f(-10, -40);
        glVertex2f(-14, -40);
        glVertex2f(-14, -30);
    glEnd();
}

void folha2(){
    glColor3f(ar2,ag2,ab2);
    glBegin(GL_POLYGON);
        glVertex2f(-7, -30);
        glVertex2f(-18, -30);
        glVertex2f(-18, -27);
        glVertex2f(-21, -27);
        glVertex2f(-21, -20);
        glVertex2f(-18, -20);
        glVertex2f(-18, -17);
        glVertex2f(-7, -17);
        glVertex2f(-7, -20);
        glVertex2f(-4, -20);
        glVertex2f(-4, -27);
        glVertex2f(-7, -27);
        glVertex2f(-7, -30);
    glEnd();
}

void sol2(){
    glColor3f(1, 0.84, 0);
    glBegin(GL_POLYGON);
        for(int i = 0; i < 350; i++){
            float theta = i*M_PI/180;
            glVertex2f (21+5*cos(theta), 40+5*sin(theta));
        }
    glEnd();
}



//TrocaDeCorFolhaArvore
void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '1':
            ar1 = 1;
            ag1 = 0;
            ab1 = 0;
            ar2 = 0;
            ag2 = 1;
            ab2 = 0;
        break;
        case '2':
             ar1 = 0;
            ag1 = 1;
            ab1 = 0;
            ar2 = 1;
            ag2 = 0;
            ab2 = 0;
        break;
    }
    glutPostRedisplay();
}

//Liga_Desliga_Luz_Janela
void timerLuz(int passo){
    if (tipoCor == 1){
        r = 0;
        g = 0;
        b = 0;
        if(r == 0 && g == 0 && b == 0){
            tipoCor = -1;
        }
    }else{
        r = 1;
        g = 1;
        b = 0;
        tipoCor = 1;
    }
    glutPostRedisplay();
    glutTimerFunc(1000,timerLuz,1);
}

//SeraAplicadaAsTransformacoesDeAcordoComAEscolhaNoMenu
void escolheTransformacao(int op){
    switch(op){
        case 0:
            glRotatef(180, 0, 0, 1);
        break;
        case 1:
            escala = escala - 0.05;
        break;
        case 2:
            escala = escala + 0.05;
    }
    glutPostRedisplay();
}

//MenuTransformacoes
void menuTransformacao(){
    submenutransformacao = glutCreateMenu(escolheTransformacao);
    glutAddMenuEntry("Rotacao", 0);
    glutAddMenuEntry("EscalaDiminui", 1);
    glutAddMenuEntry("EscalaAumenta", 2);
}

//Menu
void criaMenu(){
    menuTransformacao();
    glutCreateMenu(0);
    glutAddSubMenu("EscolaTransformacao", submenutransformacao);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

//BotaoMouse
//EsquerdoMenu
//DireitoMexeSolParaBaixo&Esquerda
//MeioMexeSolParaCima&Direita
void gerenciaMouse(int botao, int estado, int x, int y){
    if(botao == GLUT_LEFT_BUTTON){
        if(estado == GLUT_DOWN){
            criaMenu();
        }
    }
    if(botao == GLUT_RIGHT_BUTTON){
        if(estado == GLUT_DOWN){
            translacao1--;
            translacao2--;
        }
    }
    if(botao == GLUT_MIDDLE_BUTTON){
        if(estado == GLUT_DOWN){
            translacao2++;
            translacao1++;
        }
    }
    glutPostRedisplay();
}

void contorno(){
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
        glColor3f(0,0,0);
        glVertex2f(-win*aspecto, -win);
        glVertex2f(-win*aspecto, win);
        glVertex2f(win*aspecto, win);
        glVertex2f(win*aspecto, -win);
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, largura, altura);
	glPushMatrix();
        contorno();
        glScalef(escala, escala, 0);
		chao1();
		casa1();
		teto1();
		porta1();
		janelas1();
		tronco1();
		folha1();
		sol1();
	 glPopMatrix();

	glViewport(largura, 0, largura, altura);
    glPushMatrix();
        contorno();
        chao2();
        casa2();
        teto2();
        porta2();
        janelas2();
        tronco2();
        folha2();
        glTranslatef(translacao1, translacao2, 0);
        sol2();
	 glPopMatrix();

	glutSwapBuffers();
}

void alteraTamanhoJanela(GLsizei w, GLsizei h){
    if(h == 0) h = 1;
    largura = w/2;
    altura = h;
    aspecto = (float) largura / altura;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-win*aspecto, win*aspecto, -win, win);
}

void inicializa(){
     glClearColor(1,1,1,0);
     win = 50;
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
	glutCreateWindow("ProvaPratica");
    glutDisplayFunc(desenhaObjetos);
    glutReshapeFunc(alteraTamanhoJanela);
    glutTimerFunc(1000,timerLuz,1);
    glutKeyboardFunc(teclas);
    glutMouseFunc(gerenciaMouse);
    inicializa();
    glutMainLoop();
    return 0;
}
