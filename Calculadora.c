/*
Nome: Rafael Andrade Leite Barros
Email: ralb@cesar.school
Primeiro att:
Data: 27/08
Hora: 16:43

complemento a 2 dando errado ao botar negativo
*/

#include <stdio.h>
#define MAX 100

int main()
{
   int valor, escolha, resultado;
    float teste;
    char resposta[MAX] = {0}; // Inicializando o array com zeros

    printf("Digite um valor: ");
    scanf("%d", &valor);
    
    printf("Qual transformação você deseja? Base 2 (1), Base 8 (2), Base 16 (3), BCD (4), Float Bits (5)\n");
    scanf("%d", &escolha);


   if (escolha == 1) {
        // Conversão para binário
        int escolha2;
        printf("Completo a 2 s ou n? [1] [2] ");
        scanf("%d", &escolha2);

        if (escolha2 == 1) {
            // Conversão para complemento a 2
            unsigned int valorComplemento2 = valor; // Usar unsigned para evitar problemas de sinal
            if (valor < 0) {
                valorComplemento2 = ~(-valor) + 1; // Inverter todos os bits e adicionar 1 com o tio
            }

            for (int i = 31; i >= 0; i--) {
                resposta[i] = (valorComplemento2 % 2) + '0';
                valorComplemento2 /= 2;
            }

            resposta[32] = '\0'; // Null terminator para a string
            printf("Resultado em binário (Complemento a 2): %s\n", resposta);

        } else if (escolha2 == 2) {
            // Conversão normal
            unsigned int valorNormal = valor; // Para garantir que lidamos com o sinal

            for (int i = 31; i >= 0; i--) {
                resposta[i] = (valorNormal % 2) + '0';
                valorNormal /= 2;
            }

            resposta[32] = '\0'; // Null terminator para a string
            printf("Resultado em binário: %s\n", resposta);
        }
    }

    if (escolha == 2) {
        int i = MAX - 1; // Começar do final do array
        while (valor > 0 && i >= 0) {
            resultado = valor % 8;
            resposta[i] = resultado + '0'; // Armazena o dígito octal como caractere
            valor = valor / 8;
            i--;
        }
        printf("Resultado em octal: %s\n", &resposta[i+1]); // Exibe a parte útil do array
    }
    
    if (escolha == 3) {
    int i = MAX - 1; // Ajuste de i para começar do final do array
    resposta[i] = '\0'; // Terminar o string com caractere nulo

    while (valor > 0 && i > 0) {
        i--;
        int resultado = valor % 16; // Calcula o dígito hexadecimal

        // Ajusta para os dígitos hexadecimais A-F
        if (resultado < 10) {
            resposta[i] = resultado + '0'; // Converte para caractere 0-9
        } else {
            resposta[i] = resultado - 10 + 'A'; // Converte para caractere A-F
        }

        valor = valor / 16; // Reduz o valor
    }

    printf("Resultado em hexadecimal: %s\n", &resposta[i]); // Exibe a parte útil do array
}


   if (escolha == 4) {
        int i = MAX - 1;    // Começar do final do array
        resposta[i] = '\0'; // Adicionar o caractere nulo ao final

        // Loop para converter cada dígito decimal para BCD
        while (valor > 0 && i > 0) {
            int digito = valor % 10; // Extrai o último dígito decimal
            for (int j = 0; j < 4 && i > 0; j++) {
                i--;
                resposta[i] = (digito % 2) + '0'; // Converte o dígito em binário
                digito /= 2;
            }
            valor /= 10; // Passa para o próximo dígito decimal
        }

        // Ajuste para quando o valor inicial for 0
        if (i == MAX - 1) {
            resposta[--i] = '0';
        }

        printf("Resultado em BCD: %s\n", &resposta[i]); // Exibe a parte útil do array
    }
    return 0;
}

