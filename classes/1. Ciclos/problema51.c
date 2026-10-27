#include<stdio.h>
#include<conio.h>
int main()
{
 int num,X;
 char res='N'; 
   while(res!='N')  
     {
	   system("cls");
	   printf("Ingrese Valor: "); 
	   scanf("%d",&num);
	   printf("\n\nLos Divisores de %d son:\n",num);
	   for(X=1;X<=num;X++)
	     {
	      if((num%X)==0) printf("%3d ",X);
		 }
	  printf("\n\n");  
	  printf("Deseas realizar otro Calculo (S/N):");  
	  res=toupper(getch());  //   'S' 'N'
    }  
 return 0;
}