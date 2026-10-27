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
	
	//Llenar MANUALMENTE el vector
	for(i=0;i<LIM;i++)
	{
		printf("\nIngrese un NUMERO: ");
		scanf("%d",&vec[i]);
		
	}
	
	//Mostrar el Contenido del vector
	printf("\n");
	for(i=0;i<LIM;i++)
	{
		printf("%5d",vec[i]);
	}
	printf("\n");
	return 0;
}