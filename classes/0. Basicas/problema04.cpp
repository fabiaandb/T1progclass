#include<stdio.h>
#include<conio.h>
int main()
{
	int edad;
	
	printf("INGRESE SU EDAD: ");
	scanf("%d",&edad);	
	if(edad>=18)
	 {	 
	  printf("Esta pesona es MAYOR de Edad\n");
	  printf("Acceso Permitido\n\n");	  
	 }
	else
	 {
	  printf("Esta pesona es MENOR de Edad\n");
	  printf("Acceso Denegado\n\n");
     }
	return 0;
}
