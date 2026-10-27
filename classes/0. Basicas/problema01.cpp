#include<stdio.h>
#include<conio.h>
#define PI 3.1416
int main ()
{
float base,altura,area,costo;
float tierra=35;

printf ("ingrese la base:");   scanf ("%f",&base);
printf ("ingrese la altura:"); scanf ("%f",&altura);
area = base * altura;
costo= area * tierra;
printf ("\n\nel area es: %.2f\n",area);
printf ("el costo es: %.2f\n",costo);
return 0;
}

