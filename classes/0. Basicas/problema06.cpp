#include<stdio.h>
#include<conio.h>
int main()
{
  char EC;
  
  printf("INGRESE EC(C/V/D/S):");
  scanf("%c",&EC);  
  switch(EC)   // ASCII
   {
     case 'C':{  printf("CASADO");     	break; }
     case 'V':{  printf("VIUDO"); 		break; }
     case 'D':{  printf("DIVORCIADO"); 	break; }
     case 'S':{  printf("SOLTERO"); 	break; }
     default:
     	    {  printf("ERROR POR CAPA 8...");   }
   } 
  return 0;
}

