#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#define LIM 10
int main()		//vectores
{
	int i,num,ENC;
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
		printf("%5d",vec[i]);
	}
	printf("\n");
	
	printf("\nElemento a buscar: ");
	scanf("%d",&num);
	
	//Buscamos el valor de num en VEC
	ENC=0;
	printf("\n");
	for(i=0;i<LIM;i++)
	{
		if(vec[i]==num)
		{
			ENC=1;
			printf("\n\t==========================");
			printf("\n\t%d esta en la posicion %d",num,(i+1));
			printf("\n\t==========================");
			break;
		}
	}
	if(!ENC)
	{	
		printf("\n\t=======================");
		printf("\n\t%d NO esta en la lista",num);
		printf("\n\t=======================");
	}
	printf("\n");
	
	return 0;
}