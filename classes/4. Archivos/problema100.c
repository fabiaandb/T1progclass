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
    archivo = fopen("EMPLEADOS.DAT","wb");
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
     do{
  	    system("cls");
  	    printf("\n");  	  
	    printf("     INGRESE CEDULA: "); scanf("%d",&A.cedula); fflush(stdin);
	    printf("     INGRESE NOMBRE: "); scanf("%s",A.nombre);  fflush(stdin);
	    printf("     INGRESE   SEXO: "); scanf("%c",&A.sexo);   fflush(stdin);
	    printf("           BILINGUE: "); scanf("%c",&A.bil);    fflush(stdin);
	    printf("INGRESE SUELDO BASE: "); scanf("%f",&A.sueldoBase);
	    fwrite(&A,sizeof(struct empleado),1,archivo);
 	    printf("\n\nDeseas hacer otro(S/N): ");  	  
       }while(toupper(getch())!='N'); 
       
    system("cls"); 
	printf("\n\n\tSaliendo del Programa...");
	Sleep(2500); system("cls");
 return 0;
}
 
 	











