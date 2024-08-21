/*
Nome: Rafael Andrade Leite Barros
Data de inicio: 21/08/24
Data de final:
Horario de inicio: 16:38
Email: ralb@cesar.school
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
    printf("Qual transformação você deseja? Base 2 (1), Base 8 (2), Base 16 (3), BCD (4) \n");
    scanf("%d", &escolha);

  if (escolha == 1) {
        // Conversão para binário
        for (int i = 31; i >= 0; i--) {
            resultado = valor % 2;
            resposta[i] = resultado + '0'; // Convertendo o resultado para caractere '0' ou '1'
            valor = valor / 2;
            if (valor == 0) {
                resposta[i]= '1';
                printf("Resultado em binário: %s\n", &resposta[i]);
                break; // Para o loop se o valor já foi totalmente convertido
            }
        }
    }

    if (escolha == 2) {
        int i = MAX - 1; // Começar do final do array
        while (valor > 0 && i >= 0) {
            resultado = valor % 8;
            if(resultado > 1){
                resultado=1;
            }
            resposta[i] = resultado + '0'; // Armazena o dígito octal como caractere
            valor = valor / 8;
            i--;
        }
        printf("Resultado em octal: %s\n", &resposta[i+1]); // Exibe a parte útil do array
    }
    
    if(escolha == 3){
        int i = MAX -1;
        for(i=63;i>=0;i++){
            resultado= valor % 16;
            valor=valor/16;
            resposta[i]= resultado + '0';
        }
        printf("Resultado em octa: %s\n",resposta);
    }

    if(escolha == 4){
        for(int i=63;i>=0;i++){
            resultado= valor % 16;
            valor=valor/16;
            resposta[i]= resultado + '0';
        }
        printf("Resultado em octa: %s\n",resposta);
    }
    return 0;
}

