#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int main()
{
 char nombre[70];
 int cont=0;
   
 printf("Ingrese Cadena: ");
 scanf("%s",&nombre);
 cont=0;
 for(int i=0;i<strlen(nombre);i++)
   {
   	     if(toupper(nombre[i])=='A') cont++;
   	     if(toupper(nombre[i])=='E') cont++;
   	     if(toupper(nombre[i])=='I') cont++;
   	     if(toupper(nombre[i])=='O') cont++;
   	     if(toupper(nombre[i])=='U') cont++;
   }
   printf("%s tiene %d vocales",nombre,cont);
    
 return 0;
}
