/*
Nome: Rafael Andrade Leite Barros
Email: ralb@cesar.school
Primeiro att:
Data: 27/08
Hora: 16:43

Segunda att:
Data: 29/08
Hora: 14:32

complemento a 2 dando errado ao botar negativo
*/

#include <stdio.h>
#define MAX 100

int main() {
    int valor, escolha, resultado,tipo;
    char resposta[MAX] = {0}; // Inicializando o array com zeros
    printf("voce quer fazer operacao com flaot ou double? sim ou nao ? [1] [2]");
    scanf("%d",&tipo);
    
    if(tipo == 2){
    printf("Insira o valor inteiro: ");
    scanf("%d",&valor);
    
    printf("Qual transformação você deseja? Base 2 (1), Base 8 (2), Base 16 (3), BCD (4), Float Bits (5)\n");
    scanf("%d", &escolha);
    
    if (escolha == 1) {
        // Conversão para binário
        int escolha2;
        printf("Completo a 2 s ou n? [1] [2] ");
        scanf("%d", &escolha2);

        if (escolha2 == 1) {
            // Conversão para complemento a 2
            unsigned int valorComplemento2 = valor;

            if (valor < 0) {
                valorComplemento2 = ~(-valor) + 1; // Inverter todos os bits e adicionar 1
            }

            for (int i = 31; i >= 0; i--) {
                resposta[i] = (valorComplemento2 % 2) + '0';
                valorComplemento2 /= 2;
            }

            resposta[32] = '\0'; // Null terminator para a string
            printf("Resultado em binário (Complemento a 2): %s\n", resposta);
        } 
        else if (escolha2 == 2) {
            // Conversão normal
            unsigned int valorNormal = (unsigned int) valor;

            for (int i = 31; i >= 0; i--) {
                resposta[i] = (valorNormal % 2) + '0';
                valorNormal /= 2;
            }

            resposta[32] = '\0'; // Null terminator para a string
            printf("Resultado em binário: %s\n", resposta);
        }

    } 
    else if (escolha == 2) {
        // Conversão para octal
        int i = MAX - 1; // Começar do final do array
        while (valor > 0 && i >= 0) {
            resultado = valor % 8;
            resposta[i] = resultado + '0'; // Armazena o dígito octal como caractere
            valor = valor / 8;
            i--;
        }
        printf("Resultado em octal: %s\n", &resposta[i + 1]); // Exibe a parte útil do array

    } 
    else if (escolha == 3) {
        // Conversão para hexadecimal
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
    else if (escolha == 4) {
        // Conversão para BCD
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
    }
    if(tipo == 1){    
        // Representação de ponto flutuante em bits
        float num;
        printf("Digite um número real para visualizar em bits de ponto flutuante: ");
        scanf("%f", &num);

        // Interpreta os bits de ponto flutuante diretamente
        unsigned int floatBits = *((unsigned int*) &num);

        // Extraindo partes do float
        unsigned int floatSign = (floatBits >> 31) & 1;            // Sinal
        unsigned int floatExponent = (floatBits >> 23) & 0xFF;     // Expoente
        unsigned int floatFraction = floatBits & 0x7FFFFF;         // Fração

        printf("Representação do Float:\n");
        printf("Sinal: %u\n", floatSign);
        printf("Expoente: %u\n", floatExponent);
        printf("Expoente com viés: %d\n", floatExponent - 127);
        printf("Fração (mantissa): 0x%x\n", floatFraction);

        printf("Bits: ");
        for (int i = 31; i >= 0; i--) {
            printf("%u", (floatBits >> i) & 1);
            if (i % 4 == 0) printf(" "); // Espaçamento para melhor leitura
        }
        printf("\n\n");
    }
    return 0;
}
