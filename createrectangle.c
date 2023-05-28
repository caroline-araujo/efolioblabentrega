#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "createrectangle.h"

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