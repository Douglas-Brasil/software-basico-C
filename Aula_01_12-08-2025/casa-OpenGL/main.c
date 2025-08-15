#include <GL/glut.h>

// Função de inicialização
void init() {
    // Define a cor de fundo da janela como branco
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // Configura o sistema de coordenadas
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

// Função para desenhar a casa
void drawSquare() {
    // Define a cor do triângulo como parecido com a telha
    glColor3f(0.8, 0.1, 0.1);
    // Desenha um quadrado usando GL_TRIANGLES (triângulo)
	glBegin(GL_TRIANGLES);
	    glVertex2i(240, 300); // Vértice inferior esquerdo
	    glVertex2i(320, 380); // Vértice superior esquerdo
	    glVertex2i(400, 300); // Vértice inferior direito
	glEnd();
	
	
	// Define a cor do quadrado como parecido com cinza
    glColor3f(0.5, 0.5, 0.5);
    // Desenha um quadrado usando GL_QUADS (quadrilátero)
	glBegin(GL_QUADS);
	    glVertex2i(240, 140); // Vértice inferior esquerdo
	    glVertex2i(240, 300); // Vértice superior esquerdo
	    glVertex2i(400, 300); // Vértice superior direito
	    glVertex2i(400, 140); // Vértice inferior direito
	glEnd();
	
	// Define a cor do quadrado como azul
    glColor3f(0.0, 0.0, 0.7);
    // Desenha um quadrado usando GL_QUADS (quadrilátero)
	glBegin(GL_QUADS);
	    glVertex2i(300, 140); // Vértice inferior esquerdo
	    glVertex2i(300, 220); // Vértice superior esquerdo
	    glVertex2i(340, 220); // Vértice superior direito
	    glVertex2i(340, 140); // Vértice inferior direito
	glEnd();
}


// Função de exibição
void display() {
    // Limpa o buffer de cor
    glClear(GL_COLOR_BUFFER_BIT);

    // Chama a função para desenhar a casa
    drawSquare();

    // Força a execução das operações do buffer gráfico
    glFlush();
}

int main(int argc, char** argv) {
    // Inicializa o GLUT e passa argumentos de linha de comando
    glutInit(&argc, argv);

    // Configura o modo de exibição do GLUT (usando buffer único e cores RGB)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Configura o tamanho da janela
    glutInitWindowSize(640, 480);

    // Configura a posição inicial da janela
    glutInitWindowPosition(100, 100);

    // Cria uma janela com o título "Casa com OpenGL"
    glutCreateWindow("Casa com OpenGL");

    // Chama a função de inicialização
    init();

    // Registra a função de exibição
    glutDisplayFunc(display);

    // Inicia o Loop principal do GLUT
    glutMainLoop();

    return 1;
}
