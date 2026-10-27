#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define LIM 5
int main()
{
	int v[LIM];
	int i,aux,j;
	int num,enc;
	
	//Inicializacion con numeros aleatorios de vector 
	printf("\n\n");
	srand((unsigned)time(NULL));
	for(i=0;i<LIM;i++)
	v[i]=rand()%100+1;
	printf("\n\n");
	
	//Mostrar contenido del vector 
	printf("\nORDEN ORIGINAL\n");
	for(i=0;i<LIM;i++)
	printf("%5d",v[i]);
	printf("\n\n");
	
	//Metodo de ordenamiento 
	for(j=0;j<(LIM-1);j++)
	 for(i=0;i<(LIM-1);i++)
	  if(v[i]>v[i+1])
	  {
	  	aux=v[i];
	  	v[i]=v[i+1];
	  	v[i+1]=aux;
	  }
	
	//Mostrar contenido del vector 
	printf("\nORDENADO\n");
	for(i=0;i<LIM;i++)
	printf("%5d",v[i]);
	printf("\n\n");
	
	//Buscar valor
	printf("Valor a buscar: ");
	scanf("%d",&num);
	enc=0;
	for(i=0;i<LIM;i++)
	if(v[i]==num)
	{
		printf("Encontre a %3d en la pos = %3d\n",num,(i+1));
		enc=1;
		break;
	}
	if(!enc)
	printf("ELEMENTO NO EXISTENTE....\n");
	printf("\n\n");
	
	return 0;	
}