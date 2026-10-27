#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int main()
{   
char cad1[70];
int i,cont=0;
 
 printf("Ingrese Cadena: ");
 scanf("%99[^\n]s",cad1);  
 printf("\n\n");
 
 // LLEVAR LA CADENA A MAYUSCULA
 for(i=0;i<strlen(cad1);i++)
    cad1[i]=toupper(cad1[i]);
    
 for(i=0;i<strlen(cad1);i++)
    {
     if(cad1[i]=='A')cont++;
     if(cad1[i]=='E')cont++;
     if(cad1[i]=='I')cont++;
     if(cad1[i]=='O')cont++;
     if(cad1[i]=='U')cont++;
	}
	printf("La oracion tiene %d vocales\n",cont);
    
  /*
 int i; 
 for(i=65;i<=100;i++)
    printf("%5d  %c  \n",i,i);
 */ 
 return 0;
}
