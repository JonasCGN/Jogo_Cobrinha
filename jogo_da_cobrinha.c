#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>

#define MAX 25
#define TEMP 200

enum{
    Sair_ESC = 27,
    Subir = 256 + 72,
    Descer = 256 + 80,
    Esquerdo = 256 + 75,
    Direito = 256 + 77
};
int tm=1,inicio = 0;

#include "./funcoes/blindagem.h"
#include "./funcoes/interacao.h"
#include "./funcoes/jogo.h"

int main(){
	srand(time(NULL));

    char opc;
    
    printf("------------------------------------\n");
    printf("Escolha a forma de jogar\n");
    printf("1 - Jogar com as setas\n");
    printf("2 - Jogar com WASD\n");
    printf("------------------------------------\n");
    printf("Opcao: ");
    do{
        opc = getche();
        if('1' != opc && '2' != opc)
            printf("\nOpcao invalida\n");
    }while('1' != opc && '2' != opc);
    system("cls");
    switch (opc)
    {
    case '1':
        jogoCobra_Seta();
        break;
    case '2':
        jogoCobra_wasd();
        break;
    }
    
    return 0;
}
