#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "calculateinstability.h"

// Função para calcular instabilidade
float calculateInstability(Rectangle *rectangles, int numRectangles) {
    float instability = 0.0; // Grau de instabilidade
    float totalUnsupportedLength = 0.0; // Comprimento total não apoiado

    for (int i = 0; i < numRectangles; i++) {
        Rectangle *rect = &rectangles[i];
        float unsupportedLength = rect->l; // Comprimento não apoiado inicializado como o comprimento total

        for (int j = 0; j < numRectangles; j++) {
            if (j != i) {
                Rectangle *otherRect = &rectangles[j];
                if (rect->y == otherRect->y + otherRect->h && rect->x + rect->l > otherRect->x && rect->x < otherRect->x + otherRect->l) {
                    float intersection = (rect->x + rect->l < otherRect->x + otherRect->l) ? (rect->x + rect->l - otherRect->x) : (otherRect->x + otherRect->l - rect->x);
                    unsupportedLength -= intersection;
                }
            }
        }

        if (unsupportedLength > 0) {
            instability += (unsupportedLength / rect->l);
            totalUnsupportedLength += unsupportedLength;
        }
    }

    if (totalUnsupportedLength > 0) {
        instability /= numRectangles;
    }

    return instability;
}