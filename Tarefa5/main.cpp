#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

GLint movePonto = -55;
GLint movePonto1 = -52;
GLint direcao = 1;

//Carro
void ponto(){
    glPointSize(20);
    glColor3f(0, 0.75, 1);

    glBegin(GL_POINTS);
        glVertex2f(movePonto1, movePonto);
    glEnd();
}

//Timer
void timerPonto(int passo){
    if (direcao == 1){
        movePonto+=1;
        if(movePonto == 31){
            direcao = 2;
        }
    }
    if(direcao == 2){
            movePonto1 +=1;
        if(movePonto1 == 55){
            direcao = 3;
        }
    }
    if(direcao == 3){
        movePonto -=1;
        if(movePonto == 12){
            direcao = 4;
        }
    }
    if(direcao == 4){
        movePonto1 -=1;
        if(movePonto1 == -37){
            direcao = -1;
        }
    }
    if(direcao == -1){
        movePonto -=1;
        if(movePonto == -55){
            direcao = 5;
        }
    }
    if(direcao == 5){
        movePonto1 -=1;
        if(movePonto1 == -52){
            direcao =1;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10,timerPonto,1);
}

//Estrada
void quadradoEstrada1(){
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(-59, 40);
        glVertex2f(-59, -60);
        glVertex2f(-30, -60);
        glVertex2f(-30, 40);
    glEnd();
}

void quadradoEstrada2(){
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(-30, 40);
        glVertex2f(-30, 5);
        glVertex2f(60, 5);
        glVertex2f(60, 40);
    glEnd();
}

void listrasVerticais(){
    glLineWidth(5);
    glColor3f(1, 1, 0);
    int x = -44, y;
    for (y = - 50; y <= 20; y = y + 9.5){
    glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        glVertex2f(x, y + 4);
    glEnd();
    }
}

void listrasHorizontais(){
    glLineWidth(5);
    glColor3f(1, 1, 0);
    int x , y = 22;
    for (x = -44; x <= 50; x = x + 9){
    glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        glVertex2f(x + 4, y);
    glEnd();
    }
}

//Casa parte de cima
void quadrado1(){
    glColor3f(0.6, 0.2, 0.8);
    glBegin(GL_QUADS);
        glVertex2f(-41, 41);
        glVertex2f(-41, 50);
        glVertex2f(-55, 50);
        glVertex2f(-55, 41);
    glEnd();
}

void triangulo1(){
    glColor3f(1, 0, 0.5);
    glBegin(GL_TRIANGLES);
        glVertex2f(-41, 50);
        glVertex2f(-55, 50);
        glVertex2f(-48, 60);
    glEnd();
}

void quadrado2(){
    glColor3f(1, 0.55, 0);
    glBegin(GL_QUADS);
        glVertex2f(-21, 41);
        glVertex2f(-21, 50);
        glVertex2f(-35, 50);
        glVertex2f(-35, 41);
    glEnd();
}

void triangulo2(){
    glColor3f(0.99, 0.91, 0.06);
    glBegin(GL_TRIANGLES);
        glVertex2f(-21, 50);
        glVertex2f(-35, 50);
        glVertex2f(-28, 60);
    glEnd();
}

void quadrado3(){
    glColor3f(0.6, 0.2, 0.8);
    glBegin(GL_QUADS);
        glVertex2f(-1, 41);
        glVertex2f(-1, 50);
        glVertex2f(-15, 50);
        glVertex2f(-15, 41);
    glEnd();
}

void triangulo3(){
    glColor3f(1, 0, 0.5);
    glBegin(GL_TRIANGLES);
        glVertex2f(-1, 50);
        glVertex2f(-15, 50);
        glVertex2f(-8, 60);
    glEnd();
}

void quadrado4(){
    glColor3f(1, 0.55, 0);
    glBegin(GL_QUADS);
        glVertex2f(19, 41);
        glVertex2f(19, 50);
        glVertex2f(5, 50);
        glVertex2f(5, 41);
    glEnd();
}

void triangulo4(){
    glColor3f(0.99, 0.91, 0.06);
    glBegin(GL_TRIANGLES);
        glVertex2f(19, 50);
        glVertex2f(5, 50);
        glVertex2f(12, 60);
    glEnd();
}
void quadrado5(){
    glColor3f(0.6, 0.2, 0.8);
    glBegin(GL_QUADS);
        glVertex2f(39, 41);
        glVertex2f(39, 50);
        glVertex2f(25, 50);
        glVertex2f(25, 41);
    glEnd();
}

void triangulo5(){
    glColor3f(1, 0, 0.5);
    glBegin(GL_TRIANGLES);
        glVertex2f(39, 50);
        glVertex2f(25, 50);
        glVertex2f(32, 60);
    glEnd();
}

void quadrado6(){
    glColor3f(1, 0.55, 0);
    glBegin(GL_QUADS);
        glVertex2f(59, 41);
        glVertex2f(59, 50);
        glVertex2f(45, 50);
        glVertex2f(45, 41);
    glEnd();
}

void triangulo6(){
    glColor3f(0.99, 0.91, 0.06);
    glBegin(GL_TRIANGLES);
        glVertex2f(59, 50);
        glVertex2f(45, 50);
        glVertex2f(52, 60);
    glEnd();
}

//Casa principal
void quadrado7(){
    glColor3f(0.0,0.0,0.1);
    glBegin(GL_QUADS);
        glVertex2f(-25, -60);
        glVertex2f(-25, -15);
        glVertex2f(-10, -15);
        glVertex2f(-10, -60);
    glEnd();
}

void triangulo7(){
    glColor3f(0.29, 0, 0.51);
    glBegin(GL_TRIANGLES);
        glVertex2f(-25, -15);
        glVertex2f(-10, -15);
        glVertex2f(-17, 0);
    glEnd();
}

void quadrado8(){
    glColor3f(0.0,0.0,0.1);
    glBegin(GL_QUADS);
        glVertex2f(55, -60);
        glVertex2f(55, -15);
        glVertex2f(40, -15);
        glVertex2f(40, -60);
    glEnd();
}

void triangulo8(){
    glColor3f(0.29, 0, 0.51);
    glBegin(GL_TRIANGLES);
        glVertex2f(55, -15);
        glVertex2f(40, -15);
        glVertex2f(48, 0);
    glEnd();
}

void quadrado9(){
    glColor3f(0.29, 0, 0.51);
    glBegin(GL_QUADS);
        glVertex2f(40, -60);
        glVertex2f(40, -30);
        glVertex2f(-10, -30);
        glVertex2f(-10, -60);
    glEnd();
}

void triangulo9(){
    glColor3f(0.85, 0.65, 0.13);
    glBegin(GL_TRIANGLES);
        glVertex2f(40, -30);
        glVertex2f(-10, -30);
        glVertex2f(15.5, -6);
    glEnd();
}

//Desenha
void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-60,60,-60,60);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        quadradoEstrada1();
    glPopMatrix();

    glPushMatrix();
        quadradoEstrada2();
    glPopMatrix();

    glPushMatrix();
        listrasVerticais();
    glPopMatrix();

     glPushMatrix();
        listrasHorizontais();
    glPopMatrix();

    glPushMatrix();
        ponto();
    glPopMatrix();

    glPushMatrix();
         quadrado1();
        triangulo1();
    glPopMatrix();

    glPushMatrix();
        quadrado2();
        triangulo2();
    glPopMatrix();

    glPushMatrix();
        quadrado3();
        triangulo3();
    glPopMatrix();

    glPushMatrix();
        quadrado4();
        triangulo4();
    glPopMatrix();

    glPushMatrix();
         quadrado5();
        triangulo5();
    glPopMatrix();

    glPushMatrix();
        quadrado6();
        triangulo6();
    glPopMatrix();

    glPushMatrix();
        quadrado7();
        triangulo7();
    glPopMatrix();

    glPushMatrix();
        quadrado8();
        triangulo8();
    glPopMatrix();

    glPushMatrix();
        quadrado9();
        triangulo9();
    glPopMatrix();

	glutSwapBuffers();
}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("TimerCarro");
    glutDisplayFunc(desenhaObjetos);
    glutTimerFunc(10,timerPonto,1);
    glClearColor(0.2,0.8,0.2,0);
    glutMainLoop();
    return 0;
}
