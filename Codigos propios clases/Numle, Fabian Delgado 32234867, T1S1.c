#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

#define E5  659
#define B4  494
#define C5  523
#define D5  587
#define A4  440
#define G4  392
#define F4  349
#define N 400  
#define C 200  
#define B 800  

void p(int freq, int duration) {
    Beep(freq, duration);
    Sleep(20);
}


void musica_fondo(void *arg) {
    while (1) { 
        p(E5, N); p(B4, C); p(C5, C); p(D5, N); p(C5, C); p(B4, C);
        p(A4, N); p(A4, C); p(C5, C); p(E5, N); p(D5, C); p(C5, C);
        p(B4, N + C); p(C5, C); p(D5, N); p(E5, N);
        p(C5, N); p(A4, N); p(A4, N); Sleep(N);
        
        p(D5, N + C); p(F4, C); p(A4, N); p(G4, C); p(F4, C);
        p(E5, N + C); p(C5, C); p(E5, N); p(D5, C); p(C5, C);
        p(B4, N); p(B4, C); p(C5, C); p(D5, N); p(E5, N);
        p(C5, N); p(A4, N); p(A4, N);
    }
}

int main ()//programa que compare num del usuario con el programa y ver si lo pego en 10 intentos
{
	char num1[5], num2[5]; int i,tries,j,corr,acer,opp,inte=11,record=0;//'corr' es poscicion correcta del num, 'acer' numero correcto lugar correto
	
	_beginthread(musica_fondo, 0, NULL);
	do {
		
		system("cls"); // limpia pantalla al iniciar el menu, el menu muestra para jugar, el manual, y salir
  	printf("\t=============================================\n");
  	printf("\tI              NUMLE / Adivina 4            I\n");
  	printf("\tI        by Fabian Delgado(32234867)        I\n");
  	printf("\t=============================================\n");
  	printf("\tI               1.PLAY/JUGAR                I\n");
  	printf("\tI                 2.MANUAL                  I\n");
  	printf("\tI               3.EXIT/SALIR                I\n");
 	printf("\t=============================================\n\n");
 	printf("\tRECORD = %d intentos                \n\n",record);
  	printf("\tOPTION: "); scanf("%d",&opp);
  	
  	//para que el numero sea aleatoreo y no se repitan entre si
	int n[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    srand(time(NULL));
    for (i = 9; i > 0; i--) { 
        int j_rand = rand() % (i + 1);
        int t = n[i]; 
        n[i] = n[j_rand]; n[j_rand] = t; 
    }
    for (i = 0; i < 4; i++) num1[i] = n[i] + '0'; 
    num1[4] = '\0';
	 
	switch (opp) //para las opciones del menu
	{
	
	case 1:{
		system("cls");
		printf("\tIntroduzca un numero de 4 digitos\n");
	
	for (tries = 10; tries > 0; tries--) { //ciclo para los 10 intentos
        acer = 0; corr = 0;

        printf("\n\n\t");scanf("%4s", num2); inte++;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (num2[i] == num1[j]) { 
                    if (i == j) acer++;
                     else corr++;
                }
            }
        } //identificacion de aciertos y correctos
        
        printf("\t%d aciertos y %d numeros correctos\n\n", acer, corr);
       
        if (acer == 4) {
        	system("cls");
            printf("\n\tFELICIDADES\n\tGanaste en %d intentos, Record Actual: %d",inte,record);if (inte<record) record=inte; break;
        } //verificacion de ganar
        else{
        	 Sleep(500);printf("\aIntentos restantes %d. Prueba otra vez\n", tries - 1);
		}
        
    }
    Sleep(1200);
    inte=0;
        printf("\a\n\n\tEl numero era %s\npresione cualquier tecla para salir al menu",num1); getch(); 
		break; //salir del juego
	}
	case 2:{
		system ("cls");
		printf("\t=============================================\n");
    	printf("\tI          MANUAL DE INSTRUCCIONES          I\n");
    	printf("\t=============================================\n\n");
    	printf("\tEl objetivo es adivinar un numero de 4 cifras\n");
    	printf("\tTienes un maximo de 10 intentos\n");
    	printf("\t                  Pistas:                    \n");
   	 	printf("\t- ACIERTOS: Digito correcto en posicion correcta\n");
    	printf("\t- CORRECTOS: Digito correcto en posicion MAL\n");
    	printf("\tLos digitos NO se repiten.\n\n");
    	printf("\tPresione cualquier tecla para volver al menu...");
   		 getch();
		break; //un manual con intrucciones y como se juega
	}
	case 3:{
		system ("cls");
		printf("babai"); Sleep(1000);
		break;
	}
	default:
		system ("cls");
		printf("\aOpcion no establecida intente denuevo"); Sleep(1000);
	}
} while (opp!=3);
	return 0;
}