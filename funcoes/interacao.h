#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>

void mostrarGameOver();
void mostrarGanhou();
void funcaoRandomBolinha(int *ponto_X, int *ponto_Y);
void gerarBolinha(int *ponto_X, int *ponto_Y, int *cobra_X, int *cobra_Y, int *tm);
void limitador();
void irColunaLinha(int linha, int coluna);

void mostrarGameOver(){
    system("cls");
	Sleep(600);
    char tela1[31] = {"-----------------------------"};
    char tela2[31] = {"-----V O C E P E R D E U-----"};
    char tela3[31] = {"-----------------------------"};

    for(int i=0;i<31;i++){
        irColunaLinha(0,i);
        printf("%c",tela1[i]);
        irColunaLinha(1,i);
        printf("%c",tela2[i]);
        irColunaLinha(2,i);
        printf("%c",tela3[i]);
        Sleep(25);
    }
	
    getch();
	system("cls");
}

void mostrarGanhou(){
    system("cls");
	Sleep(600);
    char tela1[31] = {"-----------------------------"};
    char tela2[31] = {"-----V O C E G A N H O U-----"};
    char tela3[31] = {"-----------------------------"};

    for(int i=0;i<31;i++){
        irColunaLinha(0,i);
        printf("%c",tela1[i]);
        irColunaLinha(1,i);
        printf("%c",tela2[i]);
        irColunaLinha(2,i);
        printf("%c",tela3[i]);
        Sleep(25);
    }
	
    getch();
	system("cls");

}

void funcaoRandomBolinha(int *ponto_X, int *ponto_Y){
    do{
        
        *ponto_X = (rand()% MAX - 2) + 1;
        *ponto_Y = (rand()% MAX - 2) + 1;

    }while(*ponto_X <= 0 || *ponto_X >= MAX - 1 || *ponto_Y <= 0 || *ponto_Y >= MAX - 1);
}

void gerarBolinha(int *ponto_X, int *ponto_Y, int *cobra_X, int *cobra_Y, int *tm) {
    int i;
    (*tm)++;

    if (*tm >= ((MAX-2)*(MAX-2))) {
        return;
    }

    do {
        funcaoRandomBolinha(ponto_X, ponto_Y);
        for (i = 0; i < *tm; i++) {
            if (*ponto_X == cobra_X[i] && *ponto_Y == cobra_Y[i]) {
                break;
            }
        }
    } while (i < *tm);

    irColunaLinha(*ponto_X, *ponto_Y);
    printf("%c", '*');
}

void loading(){
    char tela[11] = {"Carregando"};

	for (int i = 0; i < MAX; ++i)
	{   


		for (int j = 0; j < MAX; ++j)
		{
			if((j==0) || (i==0) || (i==MAX-1) || (j==MAX-1)){
                Sleep(50);
				printf("X");
			}else{
				printf(" ");
                if(i== MAX/2){
                    irColunaLinha(MAX/2,(MAX/4)-3);
                    for(int z=0;z<11;z++){
                        printf("%c ",tela[z]);
                    }
                }
			}
			
		}
		printf("\n");
    }
    system("cls||clear");
}

void limitador(){
	for (int i = 0; i < MAX; ++i)
	{   


		for (int j = 0; j < MAX; ++j)
		{
			if((j==0) || (i==0) || (i==MAX-1) || (j==MAX-1)){
				printf("X");
			}else{
				printf(" ");
			}
			
		}
		printf("\n");
    }
    
}

void exibirPontuacao(int pont){
    irColunaLinha(0,MAX+1);
    printf("Pontuacao: %04d",pont);
}

void irColunaLinha(int linha, int coluna){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD) {
        coluna,linha
    });
}