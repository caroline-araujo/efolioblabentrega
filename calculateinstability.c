#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "calculateinstability.h"

// Função para calcular instabilidade
float calculateInstability(Rectangle *rectangles, int numRectangles) {
    int unstableCount = 0;
    float instabilityDegree = 0.0;

    for (int i = 0; i < numRectangles; i++) {
        Rectangle *rect = &rectangles[i];

        // Verificar se o retângulo está apoiado em algum outro retângulo
        int supported = 0;

        for (int j = 0; j < numRectangles; j++) {
            if (i != j) {
                Rectangle *otherRect = &rectangles[j];
                if (rect->x >= otherRect->x && rect->x + rect->l <= otherRect->x + otherRect->l &&
                    rect->y - 1 == otherRect->y + otherRect->h) {
                    supported = 1;
                    break;
                }
            }
        }

        // Calcular a proporção das linhas de base
        float baseLineRatio = supported ? (float)(rect->l) / (float)(rect->h) : 1.0;

        if (supported && baseLineRatio > 1.0) {
            unstableCount++;
            instabilityDegree += baseLineRatio - 1.0;
        }
    }

    if (unstableCount > 0) {
        instabilityDegree /= unstableCount;
    }

    return instabilityDegree;
}