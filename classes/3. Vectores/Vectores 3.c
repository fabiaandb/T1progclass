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
	
	//Llenar el vector con numeros ALEATORIOS
	srand((unsigned)time(NULL));
	for(i=0;i<LIM;i++)
	{
		vec[i]=rand()%100;
	}
	
	//Mostrar el Contenido del vector
	printf("\n");
	for(i=0;i<LIM;i++)
	{
		printf("%10d",vec[i]);
	}
	printf("\n");
	return 0;
}