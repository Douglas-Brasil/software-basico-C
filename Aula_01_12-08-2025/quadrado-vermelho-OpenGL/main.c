#include <GL/glut.h>

// Função de inicialização
void init() {
    // Define a cor de fundo da janela como branco
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // Configura o sistema de coordenadas
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

// Função para desenhar um quadrado vermelho
void drawSquare() {
    // Define a cor do quadrado como vermelho
    glColor3f(1.0, 0.0, 0.0);

    // Desenha um quadrado usando GL_QUADS (quadrilátero)
	glBegin(GL_QUADS);
	    glVertex2i(240, 160); // Vértice inferior esquerdo
	    glVertex2i(240, 320); // Vértice superior esquerdo
	    glVertex2i(400, 320); // Vértice superior direito
	    glVertex2i(400, 160); // Vértice inferior direito
	glEnd();
}

// Função de exibição
void display() {
    // Limpa o buffer de cor
    glClear(GL_COLOR_BUFFER_BIT);

    // Chama a função para desenhar o quadrado vermelho
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

    // Cria uma janela com o título "Quadrado Vermelho"
    glutCreateWindow("Quadrado Vermelho");

    // Chama a função de inicialização
    init();

    // Registra a função de exibição
    glutDisplayFunc(display);

    // Inicia o Loop principal do GLUT
    glutMainLoop();

    return 0;
}




