#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>

static int recebeTecla(void){    int ch = getch();
    if (ch == 0 || ch == 224)
        ch = 256 + getch();

    return ch;
}

void letrawasd(char *o){
    int ch;

    ch = recebeTecla();
    if(ch == 'w' || ch == 'a' || ch == 's' || ch == 'd'){
        *o = ch;
    }
    
}

void seta(int *o){
    int ch;

    ch = recebeTecla();
    if(ch == Subir || ch == Descer || ch == Esquerdo || ch == Direito){
        *o = ch;
    }
}