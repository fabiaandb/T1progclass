#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// REGISTROS

struct persona { int cedula; char nombre[100]; float sueldo; };
int main() // registrar cedula, nombre y el sueldo de una persona
{
	struct persona A,B;
	
	printf("Ingrese su cedula: "); scanf("%d", &A.cedula);
	printf("Ingrese su nombre: "); scanf("%s", A.nombre);
	printf("Ingrese su sueldo: "); scanf("%f", &A.sueldo);
	
	system("cls");
	B=A;
	printf("A.%d - %s (%.2fdls)",A.cedula,A.nombre,A.sueldo);
	printf("\n\nB.%d - %s (%.2fdls)",B.cedula,B.nombre,B.sueldo);
	
	return 0;
}