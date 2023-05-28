#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "move.h"

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