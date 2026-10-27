#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int main()
{             //012345678
 char cad1[70],cad2[70];
 /*
 printf("Ingrese Cadena: ");
 scanf("%99[^\n]s",cad1);  
 printf("\n\n\t---%s---\n\n",cad1);       
 
 printf("\n  LONGITUD: %d",strlen(cad1)); 
 strcpy(cad2,cad1);  // >> cad2=cad1;
 printf("\n     COPIA: %d",cad2); 
 */
 
 strcpy(cad2,"ana");  // >> cad2=cad1;
 strcpy(cad1,"MANUELA");  // >> cad2=cad1;
 // printf("\n  %s <<>> %s\n",cad1,cad2); 
 // printf(">> %d\n", strcmp(cad1,cad2)     );
 if(strcmp(cad1,cad2)>0)
  printf("\n  %s >> %s\n",cad2,cad1); 
 else
  printf("\n  %s >> %s\n",cad1,cad2); 
  
 return 0;
}
