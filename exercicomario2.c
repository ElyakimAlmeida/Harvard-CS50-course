#include <stdio.h>

// Declaração da função para obter a altura
int getinfo();

int userInput, space;

int main()
{
    // Chama a função para obter a altura do usuário
    getinfo();

    // Loop principal para imprimir as pirâmides de hashes
    for (int height = 0; height < userInput; height++)
    {

        // Loop para imprimir os espaços à esquerda
        for (space = 0; space < (userInput - height - 1); space++)
        {
            printf(" ");
        }

        // Loop para imprimir os hashes à esquerda
        for (int hash = 0; hash <= height; hash++)
        {
            printf("#");
        }

        printf(" "); // Adiciona um espaço entre os dois conjuntos de hashes

        // Loop para imprimir os hashes à direita
        for (int hash2 = 0; hash2 <= height; hash2++)
        {
            printf("#");
        }

        printf("\n"); // Nova linha após cada linha de hashes
    }

    return 0;
}

// Função para obter a altura do usuário e validar a entrada
int getinfo()
{
    // Loop até o usuário digitar uma altura válida
    do
    {
        printf(" ----------------------------------- \n");
        printf("| Please enter the height desired: |\n");
        printf(" ----------------------------------- \n");
        printf("Height: ");
        scanf("%d", &userInput); // Captura a entrada do usuário

        if (userInput < 1 || userInput > 8)
        {
            printf("Height must be between 1 and 8 \n");
        }
    }
    while (userInput < 1 || userInput > 8);

    return userInput;
}
