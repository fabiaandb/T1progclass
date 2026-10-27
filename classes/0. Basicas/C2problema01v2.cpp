#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main()
{
  int op;  // char
  
do{

  system("cls");
  printf("*******************************\n");
  printf("*       M  E  N  U            *\n");
  printf("*******************************\n");
  printf(" 1.- RAICES DE CUADRATICA     *\n");
  printf(" 2.- TOTAL FACTURA. (IVA 18%) *\n");
  printf(" 3.- SALIR.                   *\n");
  printf("*******************************\n");
  printf(" OPCION: "); scanf("%d",&op);
  
  system("cls");
  switch(op)
   {
   	 case 1:{ 
   	          int A,B,C,DIS;
		      printf("\t CALCULO DE RESOLVENTE\n"); 
			  printf(" A: "); scanf("%d",&A);		      
			  printf(" B: "); scanf("%d",&B);		      
			  printf(" C: "); scanf("%d",&C);		      
			  DIS=B*B-4*A*C;
			  if(DIS<0)
			    printf("NO HAY SOLUCIONES EN R");
			  else
			    if(DIS==0)			      
			      printf("HAY UNA UNICA SOLUCION EN R");  
			    else  
			      printf("HAY DOS SOLUCIONES EN R");
			  Sleep(3000);			  
			  break; 
			}
   	 case 2:{ 
   	         float MC,IVA,MN;
		     printf("--- FACTURACION ---\n\n"); 
		     printf(" MONTO de CONSUMO: "); 
			 scanf("%f",&MC);
			 IVA=0.18*MC;
			 MN=IVA+MC;
		     printf(" CONSUMO : %.2f\n",MC);  
		     printf("     IVA : %.2f\n",IVA);  
		     printf("    PAGO : %.2f\n",MN);  
			 Sleep(4000);			  
			 break;}   	 
   	 case 3:{ 
			  printf("   --- SALIENDO DEL SISTEMA ---\n"); 
			  Sleep(3);			  
			  break;
		    }   	 
   	 default:
   	 	{ 
		 printf("CONTACTE AL ADMIN!!!\n");
		}      	 	
   }    
   }while(op!=3);
  return 0;
}
