#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int main()
{
 char nombre[70];
 char CADENA[70];
  
  printf("Ingrese Cadena: ");
  scanf("%s",&nombre);
 printf("LONGITUD: %d\n",strlen(nombre));
 printf("CARACTER EN 3: %c\n",nombre[3]);
 strcpy(CADENA,nombre); // CADENA=nombre;
 printf("CADENA COPIADA: %s\n",CADENA);
 
 strcpy(CADENA,"LUIS"); 
 printf(">> %d\n",strcmp(nombre,CADENA));
 
 for(int i=0;i<strlen(nombre);i++)
   printf("%3d %3c\n",nombre[i],nombre[i]);
 
 return 0;
}



