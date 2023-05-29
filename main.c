#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "createrectangle.h"
#include "move.h"
#include "calculateinstability.h"
#include "display.h"

int main() {
    Rectangle rectangles[MAX_RECTANGLES];
    int numRectangles = 0;

    int command;
    int x, y, l, h, p;

    while (1) {
        printf("Escolha o comando:\n");
        printf("1 - create\n");
        printf("2 - moveright\n");
        printf("3 - moveleft\n");
        printf("Comando: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
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
                break;

            case 2:
                printf("Digite as coordenadas: \n");
                printf("Digite a coordenada x: ");
                scanf("%d", &x);
                printf("Digite a coordenada y: ");
                scanf("%d", &y);
                printf("Digite a posição p: ");
                scanf("%d", &p);
                moveRight(rectangles, numRectangles, x, y, p);
                break;

            case 3:
                printf("Digite as coordenadas: \n");
                printf("Digite a coordenada x: ");
                scanf("%d", &x);
                printf("Digite a coordenada y: ");
                scanf("%d", &y);
                printf("Digite a posição p: ");
                scanf("%d", &p);
                moveLeft(rectangles, numRectangles, x, y, p);
                break;

            default:
                printf("Comando inválido!\n");
                break;
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
    }

    return 0;
}


