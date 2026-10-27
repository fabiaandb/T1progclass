#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#define LIM 5
int main()		//vectores
{
	int i;
	int vec[LIM];
	
	//Inicializar el vector en CERO
	for(i=0;i<LIM;i++)
	{
		vec[i]=0;
	}
	
	//Mostrar el Contenido del vector
	for(i=0;i<LIM;i++)
	{
		printf("%5d",vec[i]);
	}
	printf("\n");
	return 0;
}