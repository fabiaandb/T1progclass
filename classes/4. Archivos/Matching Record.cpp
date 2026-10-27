#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
typedef struct Empleado 
{
    int codigo;
    int cantidad;
}F;
//================================================================================  
// PROTOTIPADO
//================================================================================  
  void crearArchivo();
  void mostrarArchivo();
//================================================================================  
//================================================================================  
//================================================================================  
//================================================================================  
int main() 
{
  crearArchivo();    
  mostrarArchivo();    
  return 0;
}
//================================================================================  
//================================================================================  
//================================================================================  
//================================================================================    
  void crearArchivo()
  {
  	FILE *archivo;
    struct Empleado empEsc;
    int cuantos;
   
    //================================================================================
    // CREANDO F1
    //================================================================================
        archivo = fopen("archivoF1.dat", "wb");
	    if (archivo == NULL) 
		{
	      printf("\n\n =============================================\n");
		  printf("   ERROR AL TRATAR DE CREAR EL ARCHIVO F1...  \n");
		  printf(" =============================================\n");
		  Sleep(2500); return;
	    }
	    srand((unsigned)time(NULL));
	    cuantos=rand()%20+10;
	    for(int i=1;i<=cuantos;i++)
		 {	 	  
		  if( (rand()%100) >= 65) i+=rand()%3+2;
		  empEsc.codigo=i*50;
		  empEsc.cantidad=(rand()%5+1)*(100);
	      fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);      
	     }
	    fclose(archivo);
	    printf("\n\n\tArchivo F1 --- Creado Exitosamente... \n\n");  Sleep(2500);    
    //================================================================================
    // CREANDO F2
    //================================================================================
        archivo = fopen("archivoF2.dat", "wb");
	    if (archivo == NULL) 
		{
	      printf("\n\n =============================================\n");
		  printf("   ERROR AL TRATAR DE CREAR EL ARCHIVO F2...  \n");
		  printf(" =============================================\n");
		  Sleep(2500); return;
	    }
	    srand((unsigned)time(NULL));
	    cuantos=rand()%20+10;
	    for(int i=1;i<=cuantos;i++)
		 {	 	  
		  if( (rand()%100) >= 65) i+=rand()%3+2;
		  empEsc.codigo=i*50;
		  empEsc.cantidad=(rand()%5+1)*(100);
	      fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);      
	     }
	    fclose(archivo);
	    printf("\n\n\tArchivo F2 --- Creado Exitosamente... \n\n");  Sleep(3000);
	    system("cls");
    //================================================================================
  };  
//================================================================================  
  void mostrarArchivo()
  {
  	FILE *archivo;
    struct Empleado empLeer;
    
    //================================================================================
    // LECTURA DE F1
    //================================================================================    
	    archivo = fopen("archivoF1.dat", "rb");
	    if (archivo == NULL) 
		   {
	        printf("\n\n\n");
	        printf(" =============================================\n");
		    printf("   ERROR AL TRATAR DE ABRIR EL ARCHIVO F1...  \n");
		    printf(" =============================================\n");
		    Sleep(2500); return;
	       }
	    else
	       {
		    printf("\n\n");	    
		    printf(" -------------------------------------------------\n");
		    printf(" ---         REGISTROS DE MATCHING F1          ---\n");
		    printf(" -------------------------------------------------\n");
		    printf("    #    CODIGO     CANTIDAD                        \n");
		    printf(" -------------------------------------------------\n");
		    int num=1;
		    while (fread(&empLeer, sizeof(struct Empleado), 1, archivo) == 1) 
			 {
			  printf("%5d) %8d %12d \n",(num++),empLeer.codigo,empLeer.cantidad);
		     }
		    fclose(archivo);  
		    printf(" -------------------------------------------------\n");
		    printf(" Fin del archivo F1.DAT                           \n\n\n");	    
	       }
	//================================================================================
    // LECTURA DE F2
    //================================================================================    
	    archivo = fopen("archivoF2.dat", "rb");
	    if (archivo == NULL) 
		   {
	        printf("\n\n\n");
	        printf(" =============================================\n");
		    printf("   ERROR AL TRATAR DE ABRIR EL ARCHIVO F2...  \n");
		    printf(" =============================================\n");
		    Sleep(2500); return;
	       }
	    else
	       {
		    printf("\n\n");	    
		    printf(" -------------------------------------------------\n");
		    printf(" ---         REGISTROS DE MATCHING F2          ---\n");
		    printf(" -------------------------------------------------\n");
		    printf("    #    CODIGO     CANTIDAD                        \n");
		    printf(" -------------------------------------------------\n");
		    int num=1;
		    while (fread(&empLeer, sizeof(struct Empleado), 1, archivo) == 1) 
			 {
			  printf("%5d) %8d %12d \n",(num++),empLeer.codigo,empLeer.cantidad);
		     }
		    fclose(archivo);  
		    printf(" -------------------------------------------------\n");
		    printf(" Fin del archivo F2.DAT                       \n\n\n");	    
	       }       
	//================================================================================    
  };  