#include<stdio.h>
#include<conio.h>
int main ()
{
  float MC,IMP,MN;
  
  printf("INGRESE MONTO de CONSUMO: ");
  scanf("%f",&MC);
    
  IMP=0.18*MC;
  MN=IMP+MC;
  printf("\n\n");
  printf("IMPUESTO: %.2f\n",IMP);
  printf("   TOTAL: %.2f\n",MN);
return 0;
}

