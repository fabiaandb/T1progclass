#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

struct empleado
{
 int cedula;
 char nombre[100];
 char sexo; 
 char bil; 
 float sueldoBase;
};

int main()
{ 
  struct empleado A;
  FILE *archivo;
  
  // APERTURAMOS EL ARCHIVO PARA ESCRITURA
   archivo = fopen("EMPLEADOS.DAT","rb");
  // VERIFICAMOS ESTATUS DEL ARCHIVO
   if(archivo==NULL)
      {
       system("cls");
       printf("*******************************************");
       printf("*   ERROR AL TRATAR DE ABRIR EL ARCHIVO   *");
       printf("*       CONTACTE AL ADMINISTRADOR         *");
       printf("*******************************************");
       Sleep(2500); system("cls"); return -1;
	  }  
   
   // CARGAMOS LOS DATOS AL ARCHIVO
    int cont=0;
    printf("\n===========================================");
    printf("\nCEDULA          NOMBRE  SEXO   B     SUELDO");
    printf("\n===========================================");
    while(fread(&A,sizeof(struct empleado),1,archivo)==1)
       {
       	cont++; 
  	    printf("\n%6d %15s %5c %3c %10.2f",A.cedula,
		                                   A.nombre,
								   		   A.sexo,
								           A.bil,
								           A.sueldoBase);
       }
    printf("\n===========================================");
	printf("\n%d Registros Mostrados...",cont);
	getch(); system("cls");
 return 0;
}








