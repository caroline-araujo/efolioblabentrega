#include <stdio.h>
#include <stdlib.h>

#define MAX_RECTANGLES 10

// Estrutura para representar um retângulo
typedef struct {
    int x, y; // Coordenadas do canto inferior esquerdo
    int l, h; // Comprimento e altura
} Rectangle;

// Função para criar um retângulo
void createRectangle(Rectangle *rectangles, int *numRectangles, int x, int y, int l, int h) {
    if (*numRectangles >= MAX_RECTANGLES) {
        printf("Não é possível criar mais retângulos.\n");
        return;
    }

    // Verificar se há interseção com outros retângulos
    for (int i = 0; i < *numRectangles; i++) {
        Rectangle *rect = &rectangles[i];
        if (x < rect->x + rect->l && x + l > rect->x && y < rect->y + rect->h && y + h > rect->y) {
            printf("Interseção com retângulo existente.\n");
            return;
        }
    }

    Rectangle rect = {x, y, l, h};
    rectangles[*numRectangles] = rect;
    (*numRectangles)++;
}

// Função para mover um retângulo para a direita
void moveRight(Rectangle *rectangles, int numRectangles, int x, int y, int p) {
    for (int i = 0; i < numRectangles; i++) {
        Rectangle *rect = &rectangles[i];
        if (x >= rect->x && x <= rect->x + rect->l && y >= rect->y && y <= rect->y + rect->h) {
            rect->x += p;
            return;
        }
    }

    printf("Retângulo não encontrado.\n");
}

// Função para mover um retângulo para a esquerda
void moveLeft(Rectangle *rectangles, int numRectangles, int x, int y, int p) {
    for (int i = 0; i < numRectangles; i++) {
        Rectangle *rect = &rectangles[i];
        if (x >= rect->x && x <= rect->x + rect->l && y >= rect->y && y <= rect->y + rect->h) {
            rect->x -= p;
            return;
        }
    }

    printf("Retângulo não encontrado.\n");
}

// Função para calcular o grau de instabilidade de um retângulo
float calculateInstability(Rectangle *rectangles, int numRectangles) {
    float instability = 0.0; // Grau de instabilidade
    float totalUnsupportedLength = 0.0;

    for (int i = 0; i < numRectangles; i++) {
        Rectangle *rect = &rectangles[i];
        float unsupportedLength = rect->l; // Comprimento não apoiado inicializado como o comprimento total

        for (int j = 0; j < numRectangles; j++) {
            float intersection = 0;

                if (j != i) {
                    Rectangle *otherRect = &rectangles[j];
                    if (rect->y == otherRect->y + otherRect->h) {
                    if (rect->y == otherRect->y + otherRect->h)                 {
                        if(rect->x + rect->l > otherRect->x + otherRect->l  && rect->x < otherRect->x + otherRect->l && rect->x > otherRect->x) {
                            intersection = rect->x+ rect->l  -  otherRect->x+ otherRect->l;
                            unsupportedLength += intersection;
                        }

                        if(rect->x + rect->l < otherRect->x + otherRect->l && rect->x < otherRect->x  && otherRect->x + otherRect->l > otherRect->x) {
                            intersection = otherRect->x - rect->x;
                            unsupportedLength += intersection;
                        }
                    }
                }

                if (unsupportedLength > 0) {
                    instability += (unsupportedLength / rect->l);             totalUnsupportedLength += unsupportedLength;
                }

            }
        }
    }
    if (instability > 0) {
        instability /= numRectangles * 100; // Dividir pelo comprimento total dos retângulos
    }

    return instability;
}


// Função para exibir os retângulos no console
void displayRectangles(Rectangle *rectangles, int numRectangles) {
    char display[25][80] = {0}; // Matriz para representar o plano

    // Preencher as bordas dos retângulos na matriz
    for (int i = 0; i < numRectangles; i++) {
        Rectangle *rect = &rectangles[i];
        for (int j = rect->x; j < rect->x + rect->l; j++) {
            display[rect->y][j] = 'x';
            display[rect->y + rect->h - 1][j] = 'x';
        }
        for (int j = rect->y; j < rect->y + rect->h; j++) {
            display[j][rect->x] = 'x';
            display[j][rect->x + rect->l - 1] = 'x';
        }
    }

    // Calcular o grau de instabilidade
    float instabilityDegree = calculateInstability(rectangles, numRectangles);

    // Exibir o plano no console com o grau de instabilidade
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (display[i][j] == 'x' || display[i][j] == 'x') {
                printf("%c", display[i][j]);
            } else {
                if (instabilityDegree > 0) {
                    printf("*");
                    instabilityDegree--;
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Rectangle rectangles[MAX_RECTANGLES];
    int numRectangles = 0;

    int command;
    int x, y, l, h, p, op;

    printf ("\t\t\t\t======================= MUNDO DOS RETANGULOS =======================\n\n");

    do {
        printf("\n\tMENU\n\n");
        printf ("1 - Editar mundo \n");
        printf ("0 - Sair\n");
        scanf ("%d", &op);

        switch (op) {

        case 1:
            printf("\nEscolha o comando:\n\n");
            printf("1 - create\n");
            printf("2 - moveright\n");
            printf("3 - moveleft\n\n");
            printf("Comando: ");
            char command[20];
            scanf("%s", command);

            if (strcmp(command, "create") == 0) {
                printf("Digite as coordenadas: \n");
                printf("Digite a coordenada x: ");
                scanf("%d", &x);
                printf("Digite a coordenada y: ");
                scanf("%d", &y);
                printf("Digite o comprimento l: ");
                scanf("%d", &l);
                printf("Digite a altura h: ");
                scanf("%d", &h);
                createRectangle(rectangles, &numRectangles, x, y, l, h);
            } else if (strcmp(command, "moveright") == 0) {
                printf("Digite as coordenadas: \n");
                printf("Digite a coordenada x: ");
                scanf("%d", &x);
                printf("Digite a coordenada y: ");
                scanf("%d", &y);
                printf("Digite a posição p: ");
                scanf("%d", &p);
                moveRight(rectangles, numRectangles, x, y, p);
            } else if (strcmp(command, "moveleft") == 0) {
                printf("Digite as coordenadas: \n");
                printf("Digite a coordenada x: ");
                scanf("%d", &x);
                printf("Digite a coordenada y: ");
                scanf("%d", &y);
                printf("Digite a posição p: ");
                scanf("%d", &p);
                moveLeft(rectangles, numRectangles, x, y, p);
            } else {
                printf("Comando inválido!\n");
            }

                // Exibir retângulos no console
                displayRectangles(rectangles, numRectangles);

                // Calcular o grau de instabilidade
                float instabilityDegree = calculateInstability(rectangles, numRectangles);

                // Exibir o grau de instabilidade
                printf("Grau de instabilidade: %.2f\n", instabilityDegree);

                // Verificar se o grau de instabilidade é superior ou igual a 70%
                if (instabilityDegree >= 0.7) {
                    printf("ALERTA: Grau de instabilidade superior ou igual a 70%!\n");
                }

                // Limpar o buffer de entrada
                while (getchar() != '\n');
                break;

            case 2:
                return;
            }
        } while (op == 1);

    return 0;
}
