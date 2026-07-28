#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define LIM 5

int main()
{
	int V[LIM];
	
	// LLENAR CON CEROS
	for(int i=0;i<LIM;i++)
	{
		V[i]=0;	printf("%3d",V[i]);
	}
	printf("\n\v");
	
	// LLENAR CON X
	for(int i=0;i<LIM;i++)
	{
		V[i]='x';	printf("%3c",V[i]);
	}
		printf("\n\v");
		
	// LLENAR PARES CON 0 E IMPARES CON 1
	
		for(int i=0;i<LIM;i++)
	{
		
		if (i%2==0) V[i]=0;	else V[i]=1;	
		printf("%3d",V[i]);
	}
		printf("\n\v");
		
	// SECUENCIA QUE COMIENCE EN 1
	int j=1;
	for(int i=0;i<LIM;i++)
	{
			V[i]=j;	printf("%3d",V[i]);	j++;
	}
		printf("\n\v");
		
	// SECUENCIA QUE COMIENCE EN N
	int n; scanf("%d",&n);
	
	for(int i=0;i<LIM;i++)
	{
		V[i]=n;n++;	printf("%3d", V[i]);
		
	}	
		printf("\n\v");		
		
	// SECUENCIA ALEATORIA ENTRE UNO Y CIEN
		
	srand((unsigned)time(NULL));
	for(int i=0;i<LIM;i++)
	{
		V[i]= rand()%100+1; printf("%3d",V[i]);	
	}	
		printf("\n\v");
		
	//	SECUENCIA ALEATORIA ENTEROS POS Y NEG
	
	for(int i=0;i<LIM;i++)
	{
		V[i]=-100 + rand()%(100-(-100)+1); printf("\t%d",V[i]);	
	}	
		printf("\n\v");	
		
	// SECUENCIA ALEATORIA CON FLOAT
		float Vreal[LIM];
	for(int i=0;i<LIM;i++)
	{
		Vreal[i]=-100.0f + (float)rand() / RAND_MAX *(100.0f-(-100.0f));
		printf("\t%.2f",Vreal[i]); 
	}	
		printf("\n\v");			
		
	//	SECUENCIA ALEATORIA ENTEROS CUENTA DE POS Y NEG
	int pos=0, neg=0;
	for(int i=0;i<LIM;i++)
	{
		V[i]=-100 + rand()%(100-(-100)+1); printf("\t%d",V[i]);	
		if (V[i]<0) neg++;	if(V[i]>0) pos++;
	}	
		printf("\nHay %d positivos y %d negativos\n\v",pos,neg);					

	
	// LLENAR MANUALMENTE Y DESPLAZARLO A LA izquierda
	int aux=0;
	for(int i=0;i<LIM;i++)	{		scanf("%d",&V[i]);	}
	aux=V[0];
	for(int i=0;i<LIM;i++)	{	V[i]=V[i+1];	}
	V[LIM-1]=aux;
	for(int i=0;i<LIM;i++)	{		printf("\t%d",V[i]);	}
	printf("\n\v");
	
	//ORDENAR ENTEROS LEIDOS
	for(int i=0;i<LIM;i++)	{		scanf("%d",&V[i]);	}
	aux=0;
	for(int j=0; j<LIM-1;j++)
		for(int i=0;i<(LIM-1);i++)
			if (V[i]>V[i+1])
			{
				aux=V[i];	V[i]=V[i+1]; V[i+1]=aux;
			}
	for(int i=0;i<LIM;i++)	{		printf("\t%d",V[i]);	}
	printf("\n\v");	
		return 0; 
}