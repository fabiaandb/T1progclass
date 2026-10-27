#include<stdio.h>
#include<conio.h>
int main()
{
  int dia;
  
  printf("INGRESE DIA (1-7):");
  scanf("%d",&dia);
  
  switch(dia)   // ASCII
   {
     case 1:{  printf("LUNES");     break;}
     case 2:{  printf("MARTES"); 	break; }
     case 3:{  printf("MIERCOLES"); break; }
     case 4:{  printf("JUEVES"); 	break; }
     case 5:{  printf("VIERNES"); 	break; }
     case 6:{  printf("SABADO"); 	break; }
     case 7:{  printf("DOMINGO"); 	break; }
     default:
     	    {  printf("ERROR POR CAPA 8...");   }
   } 
  return 0;
}

