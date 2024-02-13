#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>

void jogoCobra_Seta(){
    
    int cobra_X[(MAX-1)*(MAX+1)] = {};
	int cobra_Y[(MAX+1)*(MAX-1)] = {};
	int ponto_X,ponto_Y;
	int i,b=0,p=1;
	int ch,chA;
    
    loading();
    limitador();

    do{
        funcaoRandomBolinha(&ponto_X,&ponto_Y);
    }while(ponto_X == 1 && ponto_Y == 1);
    
    cobra_X[0] = 1;
    cobra_Y[0] = 1;
    irColunaLinha(cobra_X[0],cobra_Y[0]);
    printf("%c",'o'); 
    
    irColunaLinha(MAX,0);
    printf("Usa a seta do teclado\n");
    do{
        seta(&ch);
    }while(ch != Subir && ch != Descer && ch != Esquerdo && ch != Direito);
    
 	while (ch != Sair_ESC ){
        for (int i = 0; i < MAX-1; ++i){
 			irColunaLinha(i,MAX);
 			printf(" ");
 		}

        if((cobra_Y[0]==0) || (cobra_Y[0]==MAX-1) || (cobra_X[0]==0) || (cobra_X[0]==MAX-1)){
            mostrarGameOver();
            break;
        } 		   

		for(i = tm; i > 0; i--){   
        	cobra_X[i]=cobra_X[i-1];
            cobra_Y[i]=cobra_Y[i-1];
        }
   
        irColunaLinha(cobra_X[tm],cobra_Y[tm]);
        printf(" "); 

        chA = (int)ch;
        if(kbhit()){
            if(chA == Subir){
        	    seta(&ch);
                if(ch == Descer){
                    ch = Subir;
                }
            }else if(chA == Descer){
        	    seta(&ch);
                if(ch == Subir){
                    ch = Descer;
                }
            }else if(chA == Esquerdo){
        	    seta(&ch);
                if(ch == Direito){
                    ch = Esquerdo;
                }
            }else if(chA == Direito){
        	    seta(&ch);
                if(ch == Esquerdo){
                    ch = Direito;
                }
            }
        }

        switch ((int) ch){
	        case Subir:
	        	cobra_X[0]--;
	            break;
	        case Descer:                    
	        	cobra_X[0]++;
	            break;
	        case Esquerdo:
	        	cobra_Y[0]--;
	            break;
	        case Direito:
	        	cobra_Y[0]++;
	            break;
            default:
                seta(&ch);
            	break;
        }

        irColunaLinha(cobra_X[0],cobra_Y[0]);
        printf("%c",'o'); 

        if(cobra_X[0] == ponto_X && cobra_Y[0] == ponto_Y){
            p++;
        }

        if(p == (MAX-2)*(MAX-2)){
            mostrarGanhou();
            break;
        }
        
        if(ponto_X == cobra_X[0] && ponto_Y == cobra_Y[0]){   
            gerarBolinha(&ponto_X,&ponto_Y,cobra_X,cobra_Y,&tm);
        }

        if(inicio == 0){
            irColunaLinha(ponto_X,ponto_Y);
            printf("%c",'*');
            inicio = 1;
        }

        exibirPontuacao(p);

        Sleep(TEMP);
        for(i=1; i < tm; i++) {
            if(cobra_X[0] == cobra_X[i] && cobra_Y[0] == cobra_Y[i]){
				mostrarGameOver();
                b=1;
            }
        }
        if(b == 1)
            break;
        
    }	
}

void jogoCobra_wasd(){
    
    int cobra_X[(MAX-1)*(MAX+1)] = {};
	int cobra_Y[(MAX+1)*(MAX-1)] = {};
	int ponto_X,ponto_Y;
	int i,b=0,p=1;
	char ch,chA;
    
    loading();
    limitador();

    do{
        funcaoRandomBolinha(&ponto_X,&ponto_Y);
    }while(ponto_X == 1 && ponto_Y == 1);	

    cobra_X[0] = 1;
    cobra_Y[0] = 1;
    irColunaLinha(cobra_X[0],cobra_Y[0]);
    printf("%c",'o'); 
    
    irColunaLinha(MAX+1,0);
    printf("Use o wasd com CAPS_LOCK desativado do teclado\n");
    do{
        letrawasd(&ch);
    }while(ch != 'w' && ch != 's' && ch != 'a' && ch != 'd');
 	while (ch != Sair_ESC ){
        for (int i = 0; i < MAX-1; ++i){
 			irColunaLinha(i,MAX);
 			printf(" ");
 		}

        if((cobra_Y[0]==0) || (cobra_Y[0]==MAX-1) || (cobra_X[0]==0) || (cobra_X[0]==MAX-1)){
        	mostrarGameOver();
            break;
        } 		
   
		for(i=tm; i>0; i--){   
        	cobra_X[i]=cobra_X[i-1];
            cobra_Y[i]=cobra_Y[i-1];
        }
   
        irColunaLinha(cobra_X[tm],cobra_Y[tm]);
        printf(" "); 

        chA = ch;
        if(kbhit()){
            if(chA == 'w'){
                letrawasd(&ch);
                if(ch == 's'){
                    ch = 'w';
                }
            }else if(chA == 's'){
                letrawasd(&ch);
                if(ch == 'w'){
                    ch = 's';
                }
            }else if(chA == 'a'){
                letrawasd(&ch);
                if(ch == 'd'){
                    ch = 'a';
                }
            }else if(chA == 'd'){
                letrawasd(&ch);
                if(ch == 'a'){
                    ch = 'd';
                }
            }
        }

        switch (ch){
	        case 'w':
	        	cobra_X[0]--;
            break;
	        case 's':
	        	cobra_X[0]++;
            break;
	        case 'a':
	        	cobra_Y[0]--;
            break;
	        case 'd':
	        	cobra_Y[0]++;
            break;
        }

        if(cobra_X[0] == ponto_X && cobra_Y[0] == ponto_Y){
            p++;
        }

        if(p == (MAX-2)*(MAX-2)){
            mostrarGanhou();
            break;
        }

        if(ponto_X == cobra_X[0] && ponto_Y == cobra_Y[0]){   
            gerarBolinha(&ponto_X,&ponto_Y,cobra_X,cobra_Y,&tm);        
        }

        irColunaLinha(cobra_X[0],cobra_Y[0]);
        printf("%c",'o'); 

        if(inicio == 0){
            irColunaLinha(ponto_X,ponto_Y);
            printf("%c",'*');
            inicio = 1;
        }

        exibirPontuacao(p);

        Sleep(TEMP);
        for(i=1; i<tm; i++) {
            if(cobra_X[0]==cobra_X[i] && cobra_Y[0]==cobra_Y[i]){
				mostrarGameOver();
                b=1;
            }
        }
        if(b == 1)
            break;

    }	
}
