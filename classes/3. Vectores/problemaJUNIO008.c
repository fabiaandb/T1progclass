#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define LIM 8
int main()
{ 
 int V[LIM];
 int i,num,enc;

 
 // INICIALIZACION CON NUMEROS ALEATORIOS
 printf("\n\n");
 srand((unsigned)time(NULL));
 for(i=0;i<LIM;i++)
   V[i]=rand()%100+1;
 printf("\n\n");  
 
 // MOSTRAR CONTENIDO DEL VECTOR
 printf("\n\n");
 for(i=0;i<LIM;i++)
   printf("%5d",V[i]);
 printf("\n\n");  
   
 printf("   Valor a Buscar: "); 
 scanf("%d",&num);
 enc=0;
 for(i=0;i<LIM;i++)
   if(V[i]==num)
     {	 
      printf("   encontre a %3d en la pos = %3d\n",num,(i+1));
      enc=1;
      break;
     }
 if(!enc)    
    printf("   ELEMENTO NO EXISTENTE...\n");
 printf("\n\n");  
   
 
 
 
 
 return 0;
}
      




