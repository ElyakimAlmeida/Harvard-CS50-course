#include <stdio.h>

// Declaração da função para obter a altura
int getinfo();

int height;

int main() {
    // Chama a função para obter a altura do usuário
    getinfo();

    // Loop principal para imprimir os hashes
    for (int i = 0; i < height; i++) {

        // Loop para imprimir os espaços à esquerda
        for (int j = 0; j < (height - i - 1); j++) {
            printf(" ");
        }

        // Loop para imprimir os hashes
        for (int k = 0; k <= i; k++) {
            printf("#");
        }

        // Nova linha após cada linha de hashes
        printf("\n");
    }

    return 0;
}

// Função para obter informações do usuário e validar a entrada
int getinfo() {
    // Loop até o usuário digitar uma altura válida
    do {
        printf(" ----------------------------------- \n");
        printf("| Please enter the height desired: |\n  ");
        scanf("%d", &height);
        printf(" ----------------------------------- \n");

        // Verifica se a altura está entre 1 e 12
        if (height < 1 || height > 12) {
            printf("Height must be between 1 and 12.\n");
        }
    } while (height < 1 || height > 12);

    return height;
}
