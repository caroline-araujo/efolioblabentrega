#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "createrectangle.h"
#include "move.h"
#include "calculateinstability.h"
#include "display.h"

int main() {

    setlocale(LC_ALL, "Portuguese");

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
            printf("\nDigite o comando:\n\n");
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
                return 0;
                break;

            default: 
                printf ("Opção inválida");
                break;
            }
        } while (op == 1);

    return 0;
}


