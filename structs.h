#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

// Definicao das constantes
#define MAX_RECTANGLES 10

// Estrutura para representar um retângulo
typedef struct {
    int x, y; // Coordenadas do canto inferior esquerdo
    int l, h; // Comprimento e altura
} Rectangle;

#endif // STRUCTS_H_INCLUDED