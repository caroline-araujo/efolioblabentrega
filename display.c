#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "calculateinstability.h"
#include "display.h"

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