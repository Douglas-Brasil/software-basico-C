#include <GL/glut.h>

// Fun��o de inicializa��o
void init() {
    // Define a cor de fundo da janela como branco
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // Configura o sistema de coordenadas
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

// Fun��o para desenhar a casa
void drawSquare() {
    // Define a cor do tri�ngulo como parecido com a telha
    glColor3f(0.8, 0.1, 0.1);
    // Desenha um quadrado usando GL_TRIANGLES (tri�ngulo)
	glBegin(GL_TRIANGLES);
	    glVertex2i(240, 300); // V�rtice inferior esquerdo
	    glVertex2i(320, 380); // V�rtice superior esquerdo
	    glVertex2i(400, 300); // V�rtice inferior direito
	glEnd();
	
	
	// Define a cor do quadrado como parecido com cinza
    glColor3f(0.5, 0.5, 0.5);
    // Desenha um quadrado usando GL_QUADS (quadril�tero)
	glBegin(GL_QUADS);
	    glVertex2i(240, 140); // V�rtice inferior esquerdo
	    glVertex2i(240, 300); // V�rtice superior esquerdo
	    glVertex2i(400, 300); // V�rtice superior direito
	    glVertex2i(400, 140); // V�rtice inferior direito
	glEnd();
	
	// Define a cor do quadrado como azul
    glColor3f(0.0, 0.0, 0.7);
    // Desenha um quadrado usando GL_QUADS (quadril�tero)
	glBegin(GL_QUADS);
	    glVertex2i(300, 140); // V�rtice inferior esquerdo
	    glVertex2i(300, 220); // V�rtice superior esquerdo
	    glVertex2i(340, 220); // V�rtice superior direito
	    glVertex2i(340, 140); // V�rtice inferior direito
	glEnd();
}


// Fun��o de exibi��o
void display() {
    // Limpa o buffer de cor
    glClear(GL_COLOR_BUFFER_BIT);

    // Chama a fun��o para desenhar a casa
    drawSquare();

    // For�a a execu��o das opera��es do buffer gr�fico
    glFlush();
}

int main(int argc, char** argv) {
    // Inicializa o GLUT e passa argumentos de linha de comando
    glutInit(&argc, argv);

    // Configura o modo de exibi��o do GLUT (usando buffer �nico e cores RGB)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Configura o tamanho da janela
    glutInitWindowSize(640, 480);

    // Configura a posi��o inicial da janela
    glutInitWindowPosition(100, 100);

    // Cria uma janela com o t�tulo "Casa com OpenGL"
    glutCreateWindow("Casa com OpenGL");

    // Chama a fun��o de inicializa��o
    init();

    // Registra a fun��o de exibi��o
    glutDisplayFunc(display);

    // Inicia o Loop principal do GLUT
    glutMainLoop();

    return 1;
}
