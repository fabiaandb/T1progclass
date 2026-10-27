#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#define LIM 10
int main()		//vectores
{
	int i,j,num,ENC,temp;
	int vec[LIM];
	
	//Llenar el vector con numeros ALEATORIOS
	srand((unsigned)time(NULL));
	for(i=0;i<LIM;i++)
	{
		vec[i]=rand()%100;
	}
	
	//Mostrar el Contenido del vector
	printf("\n\nORIGINAL\n");
	for(i=0;i<LIM;i++)
	{
		printf("%5d",vec[i]);
	}
	printf("\n\n");
	
	//METODO DE ORDENAMIENTO: BURBUJA / INVESTIGAR METODO DE ORDENAMIENTO: INSERCION / INVESTIGAR METODO DE ORDENAMIENTO: SELECCION 
	
	for(i=0;i<LIM-1;i++)
	{
		for(j=0;j<LIM-1;j++)
		{
			if(vec[j]>vec[j+1])
			{
				temp=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=temp;
			}
		}
	}
	
	printf("\n\nORDENADO\n");
	for(i=0;i<LIM;i++)
	{
		printf("%5d",vec[i]);
	}
	printf("\n\n");
	
	return 0;
}