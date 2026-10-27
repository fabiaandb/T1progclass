#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define LIM 100

struct F1 {		int codigo; float valor;	};
struct F2 {		int codigo; float valor;	};
struct F3 {		int codigo; float valor;	};

void creararchivo();
void mostrararchivo();

int main()
{
	creararchivo();
	mostrararchivo();
	
	return 0;
}

void creararchivo()
{
	FILE *archivo;
	struct F1 reg;

	float minimo = 100.00f;		float maximo = 999.99f;
	
	archivo= fopen("F1.DAT","wb");
	if (archivo == NULL) 
	{
      printf("\n\n ==========================================\n");
	  printf("   ERROR AL TRATAR DE CREAR EL ARCHIVO...  \n");
	  printf(" ==========================================\n");
	  Sleep(2500); system("cls"); return;
    }
	srand((unsigned)time(NULL));
	for	(int i=0;i>=LIM;i++)
	{
		reg.valor= minimo + ((maximo - minimo) * ((float)rand() / (float)RAND_MAX));
		reg.codigo=rand()%100+1;
	fwrite(&reg, sizeof(struct F1), 1, archivo);
    }
    
    fclose(archivo);
};