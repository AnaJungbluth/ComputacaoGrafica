#include <gl/glut.h>
#include <GL/gl.h>

/*Como mexer no programa
    Ao clicar com o botão esquerdo abre um menu onde tem a duas opção
    de sub menu a primeira é a escolha da cor dos olhos do personagem e
    a segunda é a escolha da emoção do personagem
*/

GLfloat aspecto, angulo;               // aspecto: variável para controlar windowsize; angulo: para projeção/perspectiva; rotação: para o objeto.
GLint largura, altura;                          //largura e altura da minha janela
GLint tipoCor = 1;
int r = 1, g = 1, b = 1, submenu, submenu1, boca = -48, para;
float rO = 1, gO = 1, bO = 1;

void timerLuz(int passo){
    if (tipoCor == 1){
        r = 1;
        g = 0;
        b = 0;
        if(r == 1 && g == 0 && b == 0){
            tipoCor = 2;
        }
    }
     else if (tipoCor == 2){
        r = 1;
        g = 1;
        b = 0;
        if(r == 1 && g == 1 && b == 0){
            tipoCor = 3;
        }
    }
    else if (tipoCor == 3){
        r = 0;
        g = 1;
        b = 0;
        if(r == 0 && g == 1 && b == 0){
            tipoCor = 4;
        }
    }
    else if (tipoCor == 4){
        r = 0;
        g = 0;
        b = 1;
        if(r == 0 && g == 0 && b == 1){
            tipoCor = 1;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(1000,timerLuz,1);
}

void escolheCor(int op){
    switch(op){
        case 0:
            rO = 0.69; //atribui valores como variáveis ​​de cor
            gO = 0.88; //atribui valores como variáveis ​​de cor
            bO = 0.9; //atribui valores como variáveis ​​de cor
        break;
        case 1: //caso o valor de opção para 1 pinta de verde
            rO = 0.66; //atribui valores como variáveis ​​de cor
            gO = 0.66; //atribui valores como variáveis ​​de cor
            bO = 0.66; //atribui valores como variáveis ​​de cor
        break;
        case 2: //caso o valor de opção para 2 pinta de azul
            rO = 0.56; //atribui valores como variáveis ​​de cor
            gO = 0.93; //atribui valores como variáveis ​​de cor
            bO = 0.56; //atribui valores como variáveis ​​de cor
        break;
        case 3: //caso o valor de opção para 2 pinta de azul
            rO = 1; //atribui valores como variáveis ​​de cor
            gO = 1; //atribui valores como variáveis ​​de cor
            bO = 1; //atribui valores como variáveis ​​de cor
        break;
    }
    glutPostRedisplay(); //chama a função desenha toda vez que for necessário
}

void menuCor(){
    submenu = glutCreateMenu(escolheCor); //cria um novo menu pop-up
    glutAddMenuEntry("Azul polvora", 0); //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Cinza escuro", 1); //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Verde claro", 2); //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Cancela", 3);
}

void escolheEmocao(int op){
    switch(op){
        case 0:
            boca = -46;
        break;
        case 1:
            boca = -50;
        break;
        case 2:
            boca = -48;
        break;
    }
    glutPostRedisplay(); //chama a função desenha toda vez que for necessário
}

void menuEmocao(){
    submenu1 = glutCreateMenu(escolheEmocao); //cria um novo menu pop-up
    glutAddMenuEntry("Feliz", 0); //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Triste", 1); //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Indiferente", 2); //adiciona uma entrada de menu na parte inferior do menu atual
}

void criaMenu(){
    menuCor(); //Chama a função que cria o submenu cor
    menuEmocao();
    glutCreateMenu(0); //cria um novo menu pop-up (no caso, o principal, onde serão adicionados os outros submenus)
    glutAddSubMenu("Escolher Cor dos Olhos", submenu); //adiciona um gatilho de submenu à parte inferior do menu atual
    glutAddSubMenu("Escolher Emocao", submenu1);
    glutAttachMenu(GLUT_LEFT_BUTTON); //anexa um botão do mouse para a janela
}

void gerenciaMouse(int botao, int estado, int x, int y){ //Parâmetros de entrada da função: (int button, int state, int x, int y). Os parâmetros xey indicam uma localização do mouse que o evento ocorreu.
    if(botao == GLUT_LEFT_BUTTON) //se o botão do mouse clicado for o esquerdo
        if(estado == GLUT_DOWN){ //O estado do parâmetro pode ser GLUT_UP ou GLUT_DOWN.
            criaMenu(); //chama a função que cria o menu
        }
    glutPostRedisplay(); //chama a função desenha toda vez que for necessário
}

void desenhaObjetos(void){
      glClear(GL_COLOR_BUFFER_BIT);                 //buffer padrão (limpa a tela toda vez que a função é chamada)

    /*vaso*/
     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(0.72, 0.25, 0.05);
        glRotatef(40,-1,0,0);    //adiciona cor a nossa forma
        glTranslatef(50, -20, 10);
        glutSolidCube(20);
        glColor3f(0.85, 0.65, 0.13);                       //adiciona cor a nossa forma
        glutWireCube(20);                 //cria uma forma 3d sólida
     glPopMatrix();


     //troncoArvore
    glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor4f(0.24, 0.17, 0.12, 0.5);
        glRotatef(40,-1,0,0);                   //adiciona cor a nossa forma
        glTranslatef(50, -10, 10);            //realiza a rotação em todos os eixos
        glutSolidCube(10);                      //cria uma forma 3d sólida
        glColor3f(0.24, 0.17, 0.12);                       //adiciona cor a nossa forma
        glutWireCube(10);                       //cria uma forma 3d de arame
     glPopMatrix();

    glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(0.24, 0.17, 0.12);
        glRotatef(40,-1,0,0);                   //adiciona cor a nossa forma
        glTranslatef(50, -6, 10);            //realiza a rotação em todos os eixos
        glutSolidCube(10);                      //cria uma forma 3d sólida
        glColor3f(0.24, 0.17, 0.12);                       //adiciona cor a nossa forma
        glutWireCube(10);                       //cria uma forma 3d de arame
     glPopMatrix();

      glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(0.24, 0.17, 0.12);
        glRotatef(40,-1,0,0);                   //adiciona cor a nossa forma
        glTranslatef(50, 0, 10);            //realiza a rotação em todos os eixos
        glutSolidCube(10);                      //cria uma forma 3d sólida
        glColor3f(0.24, 0.17, 0.12);                       //adiciona cor a nossa forma
        glutWireCube(10);                       //cria uma forma 3d de arame
     glPopMatrix();



      /*trocoCorpo*/
     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(0.42, 0.35, 0.8);
        glScalef(2,1,1);
        glRotatef(40,-1,0,0);
        glTranslatef(-28, -60, 10);
        glutSolidCube(50);
        glColor3f(0,0,0);                       //adiciona cor a nossa forma
        glutWireCube(50);                 //cria uma forma 3d sólida                             //cria uma forma 3d de arame
     glPopMatrix();                             //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

       /*cabeça*/
     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(0.55, 0.34, 0.26);
        glRotatef(5,0,1,-1);
        glTranslatef(-55, -18, 10);
        glutSolidCube(35);
        glColor3f(0,0,0);                       //adiciona cor a nossa forma
        glutWireCube(35);                 //cria uma forma 3d sólida                             //cria uma forma 3d de arame
     glPopMatrix();

       /*olho1*/
     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(rO,gO,bO);
        glRotatef(5,0,1,-1);
        glTranslatef(-62, -30, 10);
        glutSolidCube(5);
     glPopMatrix();

        /*olho2*/
     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(rO,gO,bO);
        glRotatef(5,0,1,-1);
        glTranslatef(-50, -30, 10);
        glutSolidCube(5);
     glPopMatrix();

     //Sorriso
     glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(-62, boca, 10);
        glutSolidCube(2);
     glPopMatrix();

     glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(-61, -48, 10);
        glutSolidCube(2);
     glPopMatrix();

     glPushMatrix();
        glColor3f(1,1,1);
         glTranslatef(-59, -48, 10);
        glutSolidCube(2);
     glPopMatrix();

     glPushMatrix();
        glColor3f(1,1,1);
         glTranslatef(-57, -48, 10);
        glutSolidCube(2);
     glPopMatrix();

     glPushMatrix();
        glColor3f(1,1,1);
         glTranslatef(-56, boca, 10);
        glutSolidCube(2);
     glPopMatrix();

    /*chapeu*/
     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(1,0,0);                       //adiciona cor a nossa forma
        glRotatef(130,-1,1,0.7);                   //adiciona cor a nossa forma
        glTranslatef(-105, 40, 43);            //realiza a rotação em todos os eixos
        glutSolidCone(20,30,30,30);             //cria uma forma 3d sólida
        glColor3f(0.55,0,0);                       //adiciona cor a nossa forma
        glutWireCone(20,30,30,30);              //cria uma forma 3d de arame
     glPopMatrix();

     /*esfera*/
     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(1,1,1);                       //adiciona cor a nossa forma
        glTranslatef(-52, 45, 10);              //realiza a rotação em todos os eixos
        glutSolidSphere(5,4,4);              //cria uma forma 3d sólida
        glColor3f(1,1,1);                       //adiciona cor a nossa forma
        glutWireSphere(5,4,4);               //cria uma forma 3d de arame
     glPopMatrix();

     //Pisca-Pisca-Atras-Arvore
     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(23, 26, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(19, 30, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(13, 28, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(19, 43, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(22, 37, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(26, 33, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(38, 21, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

       glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(15, 36, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     /*PartedeCimadaArvore*/
     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor4f(0.13, 0.55, 0.13, 0.3);                       //adiciona cor a nossa forma
        glRotatef(135,-1,1,0.7);                   //adiciona cor a nossa forma
        glTranslatef(-70, -40, 43);            //realiza a rotação em todos os eixos
        glutSolidCone(30,40,10,10);             //cria uma forma 3d sólida
        glColor3f(0, 0.39, 0);                         //adiciona cor a nossa forma
        glutWireCone(30,40,10,10);              //cria uma forma 3d de arame
     glPopMatrix();

     //Pisca-Pisca
     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(10, 19, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(18, 20, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(23, 21, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(30, 19, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(10, 27, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(35, 22, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(18, 27, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(23, 32, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(28, 27, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(34, 27, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(29, 33, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

      glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(15, 32, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(19, 36, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(25, 38, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(17, 40, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(22, 42, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(14, 23, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor3f(r, g, b);
        glScalef(2,2,2);
        glTranslatef(26, 15, 10);                       //insere a matriz de transformação corrente na pilha
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glPushMatrix();
        glColor4f(r, g, b, 3);
        glScalef(2,2,2);
        glTranslatef(20, 15, 10);
        glutSolidIcosahedron();
        glColor3f(0,0,0);
        glutWireIcosahedron();
     glPopMatrix();

     glutSwapBuffers();                         //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}

void Inicializa (void){
   glClearColor(0,0,0,0);
    angulo = 20;

   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void projetaPlano(void){
    glMatrixMode(GL_PROJECTION);                    //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                               //carrega a projeção
    gluPerspective(angulo, aspecto, 0.1, 500);      //função que estabelece os parâmetros da Projeção Perspectiva, atualizando a matriz de projeção perspectiva.
    glMatrixMode(GL_MODELVIEW);                     //projeção do tipo modelo
    glLoadIdentity();                               //carrega a identidade de projeção de modelo
    gluLookAt(0, 300, 300, 0, 0, 0, 0, 1, 0);       //define a transformação de visualização, através dos argumentos é possível indicar a posição da câmera (para onde ela está direcionada).
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){      //faz o controle do tamanho das viewports (padrão de parâmetros, altura e largura) (800x600 no glutInitWindowSize)
    glViewport(0, 0, w, h);                          //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
    largura = w;                                     //altura eu mantenho a mesma, pois não vou dividir a janela.
    altura = h;                                      //largura eu mantenho a mesma, pois não vou dividir a janela.
    aspecto = (float)largura / altura;               //largura dividida pela altura (utilizada para controlar a largura da janela automaticamente, independente de eu alterar a windowsize) (faz com que as janelas tenham a mesma proporção em cada viewport)
    projetaPlano();                                  //chama a função projetaPlano
}

int main(void)
{
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);       //somente um double buffer | sistema de cores RGB
     glutInitWindowSize(800,600);                       //define o tamanho da janela
     glutInitWindowPosition(300,120);                   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
     glutCreateWindow("Atividade 3D");         //permite a criação de uma janela
     glutDisplayFunc(desenhaObjetos);                   //função de callback - chama a função desenhaObjetos
     glutTimerFunc(10,timerLuz,1);
     glutMouseFunc(gerenciaMouse);           //chama a função que escuta nossas teclas direcionais
     glutReshapeFunc(AlteraTamanhoJanela);              //função que altera o tamanho da janela, redesenha o tamanho da janela
     Inicializa();                                      //função que inicializa nossas variáveis
     glutMainLoop();                                    //loop infinito - escuta as informações do sistema até encerrar a aplicação
     return 0;                                          //retorna zero
}
