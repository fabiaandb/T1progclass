#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
typedef struct Empleado
{
	int codigo;
	int cantidad;
} F;
//================================================================================
// PROTOTIPADO
//================================================================================
void crearArchivo();
void mostrarArchivo();
void matchingrecord();
//================================================================================
//================================================================================
//================================================================================
//================================================================================
int main()
{
	crearArchivo();
//	mostrarArchivo();
	matchingrecord();
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
			Sleep(2500);
			return;
		}
	srand((unsigned)time(NULL));
	cuantos=rand()%20+10;
	for(int i=1; i<=cuantos; i++)
		{
			if( (rand()%100) >= 65) i+=rand()%3+2;
			empEsc.codigo=i*50;
			empEsc.cantidad=(rand()%5+1)*(100);
			fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
		}
	fclose(archivo);
	printf("\n\n\tArchivo F1 --- Creado Exitosamente... \n\n");
	//================================================================================
	// CREANDO F2
	//================================================================================
	archivo = fopen("archivoF2.dat", "wb");
	if (archivo == NULL)
		{
			printf("\n\n =============================================\n");
			printf("   ERROR AL TRATAR DE CREAR EL ARCHIVO F2...  \n");
			printf(" =============================================\n");
			Sleep(2500);
			return;
		}

	cuantos=rand()%20+10;
	for(int i=1; i<=cuantos; i++)
		{
			if( (rand()%100) >= 65) i+=rand()%3+2;
			empEsc.codigo=i*50;
			empEsc.cantidad=(rand()%5+1)*(100);
			fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
		}
	fclose(archivo);
	printf("\n\n\tArchivo F2 --- Creado Exitosamente... \n\n");
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
			Sleep(2500);
			return;
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
			printf("                           \n\n\n");
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
			Sleep(2500);
			return;
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
			printf("                      \n\n\n");
		}
};
void matchingrecord()
{
	//================================================================================
	// MATCHING RECORD
	//================================================================================
	FILE *f1, *f2;
	struct Empleado emp1, emp2;
	
			f1 = fopen("archivoF1.dat", "rb");
			f2 = fopen("archivoF2.dat", "rb");

	if ((f1 == NULL) &&(f2 == NULL) )
		{
			printf("\n\n\n");
			printf(" =============================================\n");
			printf("   ERROR AL TRATAR DE ABRIR EL ARCHIVO F1...  \n");
			printf(" =============================================\n");
			Sleep(2500);
			return;
		}
	else
		{
			printf("\n\n");
			printf("\t=================================================\n");
			printf("\tI               MATCHING RECORD                 I\n");
			printf("\tI-----------------------------------------------I\n");	
			printf("\tI                Fabian Delgado                 I\n");
			printf("\t=================================================\n");
			printf("\t=================================================\n");
			int num=1;

			// F1

			printf("\n\t======================F1=========================\n");
			while (fread(&emp1, sizeof(struct Empleado), 1, f1) == 1)
				{
					printf("\t\t%5d) %8d %12d \n",(num++),emp1.codigo,emp1.cantidad);
				}
			num=1;
			// F2
			printf("\n\t======================F2=========================\n");
			while (fread(&emp2, sizeof(struct Empleado), 1, f2) == 1)
				{
					printf("\t\t%5d) %8d %12d \n",(num++),emp2.codigo,emp2.cantidad);
				}
			num=1;
			rewind(f1);	rewind(f2);

			int leidof1 = fread(&emp1, sizeof(struct Empleado), 1, f1);
			int leidof2 = fread(&emp2, sizeof(struct Empleado), 1, f2);

			printf("\n\t====================MATCHING=====================\n");

			while(leidof1==1 || leidof2==1)
				{

					if(leidof1==1 && leidof2==1)
						{
							if(emp1.codigo<emp2.codigo)
								{
									printf("\t\t%5d) %8d %12d \n", (num++), emp1.codigo, emp1.cantidad);
									leidof1 = fread(&emp1, sizeof(struct Empleado), 1, f1);
								}
							else if (emp2.codigo < emp1.codigo)
								{
									printf("\t\t%5d) %8d %12d \n", (num++), emp2.codigo, emp2.cantidad);
									leidof2 = fread(&emp2, sizeof(struct Empleado), 1, f2);
								}
							else
								{
									printf("\t\t%5d) %8d %12d \n", (num++), emp1.codigo, emp1.cantidad + emp2.cantidad);
									leidof1 = fread(&emp1, sizeof(struct Empleado), 1, f1);
									leidof2 = fread(&emp2, sizeof(struct Empleado), 1, f2);
								}
						}
					else if (leidof1 == 1)
						{
							printf("\t\t%5d) %8d %12d \n", (num++), emp1.codigo, emp1.cantidad);
							leidof1 = fread(&emp1, sizeof(struct Empleado), 1, f1);
						}
					else if (leidof2 == 1)
						{
							printf("\t\t%5d) %8d %12d \n", (num++), emp2.codigo, emp2.cantidad);
							leidof2 = fread(&emp2, sizeof(struct Empleado), 1, f2);
						}
				}



			fclose(f1);
			fclose(f2);
			printf(" -------------------------------------------------\n"); getch();
		}


	//================================================================================
};
