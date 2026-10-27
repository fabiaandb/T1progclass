#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#define LIM 850
struct Empleado 
{
    char id[8];
    char nombre[50];
    char sexo,bilingue;
    int antiguedad,cargo,cantFamSeg;
    float salario;
};
//=============================================================================
// PROTOTIPADO
//=============================================================================
  void crearArchivo();
  void mostrarArchivo();
  void mostrarMujeresBilingue();
  void crearArchivoPruebas();
//=============================================================================
int main() 
{
  // crearArchivo();  
  // crearArchivoPruebas();
  mostrarArchivo();    
  return 0;
}
//=============================================================================  
  void mostrarMujeresBilingue()
  {
  	FILE *archivo;
    struct Empleado empLeer;
    struct Empleado V[LIM];
    
    archivo = fopen("empleadosv2.dat", "rb");
    if (archivo == NULL) 
	   {
        printf("\n\n ==========================================\n");
	    printf("   ERROR AL TRATAR DE ABRIR EL ARCHIVO...  \n");
	    printf(" ==========================================\n");
	    Sleep(2500); system("cls"); return;
       }
    else
       {
       	// Cargar el vector
       	int i=0;
	    while (fread(&V[i], sizeof(struct Empleado), 1, archivo) == 1) 
	        i++;
	    fclose(archivo); 	    
		// printf("\n\n %d \n",i);	        
		//VISUALIZAR LAS PERSONAS OBJETIVOS (MUJERES BILINGUE)
		for(i=0;i<LIM;i++)
		  {
	         if( (V[i].sexo=='F') && (V[i].bilingue=='S')  )	  	
	           {
	             printf("\n  CODIGO: %s",V[i].id);	           	
	             printf("\n  NOMBRE: %s",V[i].nombre);	           	
	             printf("\nBILINGUE: %c",V[i].bilingue);	           	
	             printf("\n  SUELDO: %.2f",V[i].salario);	           	
				 printf("\n======================================");	           		             
			   }
		  }
       }
  };  
  //=============================================================================  
  void mostrarArchivo()
  {
  	FILE *archivo;
    struct Empleado empLeer;
    
    archivo = fopen("empleadosv2.dat", "rb");
    if (archivo == NULL) 
	   {
        printf("\n\n ==========================================\n");
	    printf("   ERROR AL TRATAR DE ABRIR EL ARCHIVO...  \n");
	    printf(" ==========================================\n");
	    Sleep(2500); system("cls"); return;
       }
    else
       {
	    printf("\n\n");	    
	    printf(" -------------------------------------------------\n");
	    printf(" ---            EMPLEADOS REGISTRADOS          ---\n");
	    printf(" -------------------------------------------------\n");
	    printf(" CEDULA          NOMBRE                           \n");
	    printf(" -------------------------------------------------\n");
	    int num=1;
	    while (fread(&empLeer, sizeof(struct Empleado), 1, archivo) == 1) 
		 {
		  printf("%5d) %8s %25s \n",(num++),empLeer.id,empLeer.nombre);
	     }
	    printf(" -------------------------------------------------\n");
	    printf(" Pulse una tecla para continuar...                \n");
	    fclose(archivo); getch();
       }
  };  
  //=============================================================================  
  void crearArchivo()
  {
  	FILE *archivo;
    struct Empleado empEsc;
        
    archivo = fopen("registros.dat", "wb");
    if (archivo == NULL) 
	{
      printf("\n\n ==========================================\n");
	  printf("   ERROR AL TRATAR DE CREAR EL ARCHIVO...  \n");
	  printf(" ==========================================\n");
	  Sleep(2500); system("cls"); return;
    }
    
    do
	 {	 
	  system("cls");
	  printf("\n\n\t==============================\n");
	  printf("\t  Registro de Nuevo Empleado  \n");
	  printf("\t==============================\n");	  
	  printf("\t     CEDULA: "); scanf("%s",empEsc.id);          fflush(stdin);
	  printf("\t     NOMBRE: "); scanf("%s",empEsc.nombre);      fflush(stdin);
	  printf("\t       SEXO: "); scanf("%c",&empEsc.sexo);       fflush(stdin);
	  printf("\t   BILINGUE: "); scanf("%c",&empEsc.bilingue);   fflush(stdin);
	  printf("\t ANTIGUEDAD: "); scanf("%d",&empEsc.antiguedad); fflush(stdin);
	  printf("\t      CARGO: "); scanf("%d",&empEsc.cargo);      fflush(stdin);
	  printf("\t CANT. ASEG: "); scanf("%d",&empEsc.cantFamSeg); fflush(stdin);
	  printf("\t     SUELDO: "); scanf("%f",&empEsc.salario);
	  printf("\t==============================\n");
      fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
      printf("\tRegistro Exitoso... Otro(S/N)\n");
     }while(toupper(getch())!='N');
    fclose(archivo);
    printf("\tArchivo Creado Exitosamente.\n");
    Sleep(2500); system("cls");
  };  
//=============================================================================  
  void crearArchivoPruebas()
  {
  	FILE *archivo;
    struct Empleado empEsc;
        
    archivo = fopen("empleadosv2.dat", "wb");
    if (archivo == NULL) 
	{
      printf("\n\n ==========================================\n");
	  printf("   ERROR AL TRATAR DE CREAR EL ARCHIVO...  \n");
	  printf(" ==========================================\n");
	  Sleep(2500); system("cls"); return;
    }
    //=================================================================================
    strcpy(empEsc.id,"GB745");
	strcpy(empEsc.nombre,"Dahler De Carteret, Tiertza Virginia");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=7;
	empEsc.cargo=2;
	empEsc.cantFamSeg=8;
	empEsc.salario=3115.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SA489");
	strcpy(empEsc.nombre,"Dykins Deakin, Shawnee Susy");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=1652.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NE642");
	strcpy(empEsc.nombre,"Jillions Cavolini, Maxie Frank");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=3752.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PN949");
	strcpy(empEsc.nombre,"Frayn Hastings, Ted Irvin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=3;
	empEsc.cantFamSeg=6;
	empEsc.salario=1268.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MZ551");
	strcpy(empEsc.nombre,"Morey Arrell, Thatcher Carlo");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=4359.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RL314");
	strcpy(empEsc.nombre,"Stuffins Clemas, Reena Tiffani");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=17;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=2762.41;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JM932");
	strcpy(empEsc.nombre,"Gabey Skepper, Eustace Berne");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=4246.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BJ480");
	strcpy(empEsc.nombre,"ORodane Gremane, Rolland Zane");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=2839.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NZ856");
	strcpy(empEsc.nombre,"Brekonridge Gaylard, Will Gare");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=3400.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PX783");
	strcpy(empEsc.nombre,"Thyer Leavens, Fayre Josey");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=4481.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IR649");
	strcpy(empEsc.nombre,"Hazzard Newlove, Michele Holly");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=4033.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SP864");
	strcpy(empEsc.nombre,"Harnett Stapleford, Kale Ruperto");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=30;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=2627.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YX034");
	strcpy(empEsc.nombre,"Pelham Crockley, Odey Patricio");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=3431.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AM973");
	strcpy(empEsc.nombre,"Maskall Theyer, Finlay Perkin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=2363.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QZ657");
	strcpy(empEsc.nombre,"Dunkinson Hiers, Berk Johnathan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=3222.19;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HD432");
	strcpy(empEsc.nombre,"Pleat Marten, Adolf Sholom");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=17;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=1121.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LE125");
	strcpy(empEsc.nombre,"Terrelly Knevett, Osborne Del");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=3536.51;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UZ521");
	strcpy(empEsc.nombre,"Warsap Cabotto, Anny Carlina");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=2;
	empEsc.cantFamSeg=8;
	empEsc.salario=2146.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YM200");
	strcpy(empEsc.nombre,"Decruse Dighton, Melba Reggie");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=2488.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EA206");
	strcpy(empEsc.nombre,"Wenn Harrild, Colin Kahaleel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=2522.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AY879");
	strcpy(empEsc.nombre,"Zavattieri Kitley, Darwin Sully");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=4217.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IF909");
	strcpy(empEsc.nombre,"Sulland Exley, Sansone Birch");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=1401.29;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GI711");
	strcpy(empEsc.nombre,"Pigeon Bernasek, Kass Holly");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=3429.62;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MI005");
	strcpy(empEsc.nombre,"Abrahamian Depport, Emlyn Sonia");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=3315.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QG111");
	strcpy(empEsc.nombre,"Ferrick Verrier, Godfry Sawyere");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=4030.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XD781");
	strcpy(empEsc.nombre,"Hembry Bisson, Salomo Thurston");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=2190.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"US605");
	strcpy(empEsc.nombre,"Pere Codrington, Forester Cale");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=1129.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZJ420");
	strcpy(empEsc.nombre,"Vernazza Josephov, Cchaddie Arie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=8;
	empEsc.cantFamSeg=5;
	empEsc.salario=2298.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TG658");
	strcpy(empEsc.nombre,"Rubinivitz Maple, Merill Thibaud");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=2294.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZH402");
	strcpy(empEsc.nombre,"Duckett Lissett, Ingram Torrey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=3598.62;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WA822");
	strcpy(empEsc.nombre,"McElrath Sandison, Worthy Mordy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=4095.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KJ913");
	strcpy(empEsc.nombre,"Zienkiewicz Gibbetts, Lorne Hallsy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=3737.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OB128");
	strcpy(empEsc.nombre,"Wallsworth Gumly, Manuel Ancell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=3442.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TS234");
	strcpy(empEsc.nombre,"Cawkwell Threadgould, Prentice Tynan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=2889.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BO399");
	strcpy(empEsc.nombre,"Jacson Dunrige, Garvy Huey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=6;
	empEsc.cantFamSeg=1;
	empEsc.salario=2520.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VA348");
	strcpy(empEsc.nombre,"Valero Beavors, Sherline Legra");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=4293.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZJ408");
	strcpy(empEsc.nombre,"Johanchon Waumsley, Hurlee Symon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=2891.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DV241");
	strcpy(empEsc.nombre,"Genn St Leger, Terrel Rafaellle");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=1738.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PX939");
	strcpy(empEsc.nombre,"Zywicki Weekland, Marchall Reggy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=4074.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FV178");
	strcpy(empEsc.nombre,"Siddele Posselwhite, Padraic Onofredo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=3753.74;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LF270");
	strcpy(empEsc.nombre,"Bebb Lyster, Yvon Pierson");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=2156.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EX496");
	strcpy(empEsc.nombre,"Garfath Galliver, Wilbert Ilaire");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=4392.41;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FO866");
	strcpy(empEsc.nombre,"Holcroft Brownett, Jody Reuben");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=1479.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PR790");
	strcpy(empEsc.nombre,"Danilchik Steers, Lombard Haskel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=3038.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MQ653");
	strcpy(empEsc.nombre,"Dive Cowely, Pincus Reggie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=1070.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EV789");
	strcpy(empEsc.nombre,"Grellier Angrick, Clare Alphonso");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=22;
	empEsc.cargo=6;
	empEsc.cantFamSeg=8;
	empEsc.salario=4453.78;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KY144");
	strcpy(empEsc.nombre,"Rofe Egell, Carlie Lazar");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=6;
	empEsc.cantFamSeg=8;
	empEsc.salario=2617.52;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SF412");
	strcpy(empEsc.nombre,"Awton Chicchelli, Rhett Graham");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=6;
	empEsc.cantFamSeg=8;
	empEsc.salario=3926.57;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DH032");
	strcpy(empEsc.nombre,"Rawlin Gremane, Lindie Gusta");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=4336.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CU409");
	strcpy(empEsc.nombre,"Kirkbride Churchyard, Bobby Theodor");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=1990.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UN924");
	strcpy(empEsc.nombre,"Maker Marvel, Araldo Garret");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=1200.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YN960");
	strcpy(empEsc.nombre,"Bottoner Ratt, Elwood Harvey");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=14;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=2536.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SH293");
	strcpy(empEsc.nombre,"Alwood Brotherhead, Esme Letti");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=23;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=2176.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KD103");
	strcpy(empEsc.nombre,"Thornewill Jurzyk, Jamie Fletch");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=2172.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SR785");
	strcpy(empEsc.nombre,"Petrussi Lundy, Pooh Andras");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=3913.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TD149");
	strcpy(empEsc.nombre,"Bortolotti Forcer, Orlando Worthy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=4121.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VC751");
	strcpy(empEsc.nombre,"Limer Beese, Willi Joaquin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=2298.32;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DE472");
	strcpy(empEsc.nombre,"Ellwell Burley, Chauncey Pernell");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=2115.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IJ120");
	strcpy(empEsc.nombre,"Wybern Anderl, Roselia Adelaide");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=4111.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JW313");
	strcpy(empEsc.nombre,"Tidder Boscott, Rudiger Bar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=3822.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DX413");
	strcpy(empEsc.nombre,"Bythell Hellings, Earl Page");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=1178.65;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BP711");
	strcpy(empEsc.nombre,"Worrell Hearnah, Ansell Giordano");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=1;
	empEsc.cantFamSeg=8;
	empEsc.salario=2586.11;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CE565");
	strcpy(empEsc.nombre,"Ruddin Camois, Bessie Nicoline");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=2842.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"II203");
	strcpy(empEsc.nombre,"Scatchar Torrejon, Killie Georas");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=3376.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TX816");
	strcpy(empEsc.nombre,"Crotch Hoyle, Kasper Anatollo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=2458.65;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XX392");
	strcpy(empEsc.nombre,"Coste Krook, Amata Pattie");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=1800.27;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ST835");
	strcpy(empEsc.nombre,"Lemasney Hazelgreave, Theodore Moritz");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=6;
	empEsc.cantFamSeg=1;
	empEsc.salario=2913.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TK923");
	strcpy(empEsc.nombre,"Murcutt Higgen, Timoteo Brion");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=3847.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DU518");
	strcpy(empEsc.nombre,"Chapellow Roger, Bess Ariadne");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=25;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=2427.49;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QO703");
	strcpy(empEsc.nombre,"Vasilischev Pattle, Huntley Mitch");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=4152.47;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AS443");
	strcpy(empEsc.nombre,"Holywell Abrashkin, Paulie Austin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=1421.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FY444");
	strcpy(empEsc.nombre,"Inch Huggon, Blinni Dulcea");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=10;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=4263.41;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ID246");
	strcpy(empEsc.nombre,"Spraging McGreary, Cristionna Aridatha");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=3835.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LY321");
	strcpy(empEsc.nombre,"Druitt Baxstare, Alon Orin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=1021.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QV346");
	strcpy(empEsc.nombre,"Petschel Keeffe, Tamar Lilas");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=3138.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BT394");
	strcpy(empEsc.nombre,"Sloam Serotsky, Bryn Boyd");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=1929.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RH005");
	strcpy(empEsc.nombre,"Skechley Dealtry, Elwin Cordie");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=9;
	empEsc.cargo=8;
	empEsc.cantFamSeg=6;
	empEsc.salario=1478.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ED148");
	strcpy(empEsc.nombre,"Paige Agronski, Sansone Saunder");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=3902.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RG253");
	strcpy(empEsc.nombre,"Walthall Gathwaite, Nikki Hubie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=1126.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AH876");
	strcpy(empEsc.nombre,"Denzey Kenset, Reinwald Pepe");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=27;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=4344.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YZ978");
	strcpy(empEsc.nombre,"Antonietti Gligori, Shaun Keefer");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=3678.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RM721");
	strcpy(empEsc.nombre,"Curnucke Coupe, Malchy Phil");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=3058.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TO737");
	strcpy(empEsc.nombre,"Stucksbury Livesley, Antons Ikey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=4082.54;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GV568");
	strcpy(empEsc.nombre,"Baudin MacShirie, Christian Cly");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=3087.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LY693");
	strcpy(empEsc.nombre,"Matschek Jerg, Thain Neill");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=1372.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WA187");
	strcpy(empEsc.nombre,"Bowfin Jandak, Kennedy Kent");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=2896.49;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DE692");
	strcpy(empEsc.nombre,"Killeen Longman, Nils Bourke");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=14;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=2178.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QR680");
	strcpy(empEsc.nombre,"Maddinon Eaton, Sigfried Nigel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=4296.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SA873");
	strcpy(empEsc.nombre,"Spinetti Goodbar, Rossie Sven");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=1031.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CK230");
	strcpy(empEsc.nombre,"Goatman Pinnock, Clemmie Patrick");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=10;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=1206.44;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JC998");
	strcpy(empEsc.nombre,"Clough Masson, Beverie Dniren");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=2;
	empEsc.cantFamSeg=3;
	empEsc.salario=1569.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AN383");
	strcpy(empEsc.nombre,"Rumin Brunsden, Ozzy Redd");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=1792.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GJ466");
	strcpy(empEsc.nombre,"Francescoccio Hodge, Gradey Guglielmo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=3982.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SU353");
	strcpy(empEsc.nombre,"Genty Milne, Robers Shepard");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=3457.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HB323");
	strcpy(empEsc.nombre,"Shoemark Grzeszczak, Hasheem Brod");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=2800.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MV442");
	strcpy(empEsc.nombre,"Valeri Zienkiewicz, Fonz Lemar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=1749.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NB747");
	strcpy(empEsc.nombre,"Steptowe Goulborn, Jarvis Reidar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=1436.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PO913");
	strcpy(empEsc.nombre,"Kelcher Holdron, Killian Eugen");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=3485.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SX469");
	strcpy(empEsc.nombre,"Wabb Holbarrow, Alphonse Kile");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=2808.16;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CO762");
	strcpy(empEsc.nombre,"Dymocke Howroyd, Wake Kincaid");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=4186.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FT373");
	strcpy(empEsc.nombre,"Lockner MacVaugh, Burr Godart");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=2001.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NL014");
	strcpy(empEsc.nombre,"MacRedmond Frangleton, Lind Udell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=3079.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CF195");
	strcpy(empEsc.nombre,"Hamp MacRannell, Rand Wyndham");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=2542.73;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FR896");
	strcpy(empEsc.nombre,"Isaacson Creedland, Harold Johan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=6;
	empEsc.salario=3406.18;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OG764");
	strcpy(empEsc.nombre,"Lawson Reynard, Anderson Abbot");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=4012.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QO300");
	strcpy(empEsc.nombre,"Logsdale Grissett, Alwyn Rem");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=1310.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WJ192");
	strcpy(empEsc.nombre,"Dank Meriot, Sollie Rice");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=3074.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VK896");
	strcpy(empEsc.nombre,"Burdass Martinek, Haze Paco");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=1960.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DN875");
	strcpy(empEsc.nombre,"Ridsdale Blythe, Meade Edouard");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=1233.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TH441");
	strcpy(empEsc.nombre,"Haldin Hutfield, Clevie Nicky");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=4;
	empEsc.cantFamSeg=3;
	empEsc.salario=3426.58;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EV360");
	strcpy(empEsc.nombre,"Baildon Railton, Benjamin Griz");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=3415.47;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HT349");
	strcpy(empEsc.nombre,"Silveston Baudone, Englebert Otho");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=6;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=4227.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZW943");
	strcpy(empEsc.nombre,"Muttock Abendroth, Henry Lem");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=2804.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FH181");
	strcpy(empEsc.nombre,"Heaven Avieson, Kata Aigneis");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=2102.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HU259");
	strcpy(empEsc.nombre,"Probets Benoix, Jo Halsy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=2454.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XZ281");
	strcpy(empEsc.nombre,"Erdely Coarser, Alasteir Hector");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=8;
	empEsc.cantFamSeg=6;
	empEsc.salario=3571.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RR432");
	strcpy(empEsc.nombre,"Weaving Conroy, Corbie Aymer");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=16;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=2959.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TC402");
	strcpy(empEsc.nombre,"Babin Barnsdall, Broderic Rancell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=2412.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CN924");
	strcpy(empEsc.nombre,"Goodboddy Parminter, Harcourt Osmund");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=1756.42;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VG164");
	strcpy(empEsc.nombre,"Swannie Gatherell, Archie Roland");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=1635.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TZ818");
	strcpy(empEsc.nombre,"Bonner Lilburn, Krispin Reese");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=4390.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QL455");
	strcpy(empEsc.nombre,"Pyatt Daish, Ned Johny");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=1347.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"II706");
	strcpy(empEsc.nombre,"Redmell Kenford, Felic Barnabas");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=30;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=1381.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CS639");
	strcpy(empEsc.nombre,"Yushankin Fussie, Brett Harley");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=2;
	empEsc.cantFamSeg=8;
	empEsc.salario=3269.91;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SZ869");
	strcpy(empEsc.nombre,"Deare Axton, Hamil Leicester");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=2354.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GY308");
	strcpy(empEsc.nombre,"Canas Sillitoe, Sigismondo Rurik");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=1006.5;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KO264");
	strcpy(empEsc.nombre,"Weavill Locker, Neville Damian");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=1241.5;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EA738");
	strcpy(empEsc.nombre,"Dykes Lorrain, Nicky Cedric");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=3695.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZM767");
	strcpy(empEsc.nombre,"Khrishtafovich Purry, Sigismond Pattin");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=2632.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZR768");
	strcpy(empEsc.nombre,"Jansey Settle, Gavin Ximenes");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=3199.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DH153");
	strcpy(empEsc.nombre,"Stratton Dowse, Tom Conn");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=3576.26;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UQ347");
	strcpy(empEsc.nombre,"Winterbottom Meneux, Bertha Agneta");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=3496.26;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KG536");
	strcpy(empEsc.nombre,"Pridham Lared, Pauletta Krystle");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=3265.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AC798");
	strcpy(empEsc.nombre,"Cullivan Lambregts, Obadiah Bronnie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=2083.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TU951");
	strcpy(empEsc.nombre,"Boyd Noury, Moss Oran");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=3282.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GB414");
	strcpy(empEsc.nombre,"Ryall Clewley, Ransom Sigmund");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=1693.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IY434");
	strcpy(empEsc.nombre,"Dengel Crofts, Duffie Hamnet");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=2891.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QW011");
	strcpy(empEsc.nombre,"Babbage Sheehan, Norbie Kelwin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=1027.85;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HD225");
	strcpy(empEsc.nombre,"Dronsfield Doodney, Jude Ogdan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=2985.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GV763");
	strcpy(empEsc.nombre,"Mallinder Stables, Xever Lothario");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=2;
	empEsc.cantFamSeg=8;
	empEsc.salario=3480.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AI749");
	strcpy(empEsc.nombre,"Kilgannon Broom, Hewitt Thadeus");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=2314.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WP369");
	strcpy(empEsc.nombre,"Rouby Bischof, Massimiliano Dougy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=1575.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KF463");
	strcpy(empEsc.nombre,"Wathall Eitter, Richart Stefano");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=1199.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QQ215");
	strcpy(empEsc.nombre,"Spilling Fulop, Alonzo Paquito");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=1403.58;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AT058");
	strcpy(empEsc.nombre,"Penhall Matteuzzi, Curtis Ware");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=16;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=1036.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PG067");
	strcpy(empEsc.nombre,"Kenyam Huelin, Iorgos Abraham");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=21;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=4274.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XT228");
	strcpy(empEsc.nombre,"Taunton. Milstead, Woody Merrel");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=1328.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZL033");
	strcpy(empEsc.nombre,"Dafter Adamson, Tabb Marlon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=1748.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WV864");
	strcpy(empEsc.nombre,"Boog Foxen, Regen Bradan");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=3581.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WC768");
	strcpy(empEsc.nombre,"Mosconi Fender, Yancey Hamish");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=1124.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DH947");
	strcpy(empEsc.nombre,"Dillintone Jerwood, Eva Doti");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=3911.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TS111");
	strcpy(empEsc.nombre,"Gaffer Cuttelar, Esra Dore");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=2138.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NV146");
	strcpy(empEsc.nombre,"Maddocks Scarse, Reinhold Olvan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=2096.24;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RA297");
	strcpy(empEsc.nombre,"Loseke Hatley, Emmery Munmro");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=3255.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VV184");
	strcpy(empEsc.nombre,"Tellenbroker Edlington, Dermot Silvan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=2472.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BB636");
	strcpy(empEsc.nombre,"Davydenko Clapp, Michel Moll");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=3825.32;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XV347");
	strcpy(empEsc.nombre,"Bartosik Tottie, Codie Rodrique");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=2447.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AF918");
	strcpy(empEsc.nombre,"MacFadin Gay, Wesley Elton");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=22;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=2522.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UZ025");
	strcpy(empEsc.nombre,"Lebarree Bastone, Dwayne Lazaro");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=1692.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QS502");
	strcpy(empEsc.nombre,"Claughton Dedney, Guillaume Mauricio");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=4213.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HE233");
	strcpy(empEsc.nombre,"Charter Parade, Layton Leopold");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=3558.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WX934");
	strcpy(empEsc.nombre,"Tatchell Heffernan, Nobie Pip");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=4112.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MK373");
	strcpy(empEsc.nombre,"Izkovicz Kobera, Cy Izak");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=9;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=2596.39;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NI656");
	strcpy(empEsc.nombre,"Losselyong Loveless, Hall Ewen");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=3139.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZX370");
	strcpy(empEsc.nombre,"Garshore Daniells, Xerxes Alleyn");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=1145.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EZ597");
	strcpy(empEsc.nombre,"Gilford Recher, Sinclare Edgardo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=2900.81;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SO417");
	strcpy(empEsc.nombre,"Ritelli Trice, Lotta Tabina");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=24;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=4042.54;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LA696");
	strcpy(empEsc.nombre,"Roggero Falkinder, Moshe Winfred");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=1213.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RQ040");
	strcpy(empEsc.nombre,"Graveston Cartlidge, Leonard Lawrence");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=2099.24;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UQ944");
	strcpy(empEsc.nombre,"Tonbridge Skellon, Ritchie James");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=23;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=1792.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CD223");
	strcpy(empEsc.nombre,"Ebbens Flukes, Paula Enrica");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=1855.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WG403");
	strcpy(empEsc.nombre,"Hopkyns Baylis, Dewey Tadio");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=8;
	empEsc.cantFamSeg=5;
	empEsc.salario=2123.47;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AX172");
	strcpy(empEsc.nombre,"Crosbie Chalke, Jonah Humbert");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=3587.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FS716");
	strcpy(empEsc.nombre,"Hoonahan Skoof, Drake Reggy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=3370.22;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QS498");
	strcpy(empEsc.nombre,"MacCallam Miskimmon, Gerrard Osbourne");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=6;
	empEsc.cantFamSeg=1;
	empEsc.salario=2991.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BQ299");
	strcpy(empEsc.nombre,"Yankin Jouhan, Conney Nat");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=2306.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LX483");
	strcpy(empEsc.nombre,"Lawie Lapham, Stewart Alford");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=1618.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BN946");
	strcpy(empEsc.nombre,"Lamboll Greatrex, Verne Humphrey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=1353.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YV976");
	strcpy(empEsc.nombre,"Apted Copo, Mikkel Valentine");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=6;
	empEsc.cantFamSeg=1;
	empEsc.salario=2372.42;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QW951");
	strcpy(empEsc.nombre,"Fullard Parlour, Feliks Park");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=1706.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FK875");
	strcpy(empEsc.nombre,"Impey Goldster, Janos Elmer");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=4;
	empEsc.cantFamSeg=3;
	empEsc.salario=2569.73;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JB828");
	strcpy(empEsc.nombre,"Lysaght Andreassen, Merill Ewart");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=6;
	empEsc.cantFamSeg=3;
	empEsc.salario=1451.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DY768");
	strcpy(empEsc.nombre,"Glantz Wyson, Nesta Fidelia");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=7;
	empEsc.cantFamSeg=3;
	empEsc.salario=3295.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"US362");
	strcpy(empEsc.nombre,"Cooke Cashmore, Kingsley Herb");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=1986.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TO018");
	strcpy(empEsc.nombre,"Coggen Gouldbourn, Tod Gilberto");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=3404.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DE622");
	strcpy(empEsc.nombre,"Carous Flude, Giacopo Nevins");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=1332.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DX086");
	strcpy(empEsc.nombre,"Hoyt Grimmett, Jereme Hurley");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=1080.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OR826");
	strcpy(empEsc.nombre,"McGerr Trenbay, Maxie Godwin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=3905.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RM897");
	strcpy(empEsc.nombre,"Twigley Baysting, Barry Forest");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=3251.62;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JM675");
	strcpy(empEsc.nombre,"Shand Getley, Cull Hillery");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=2448.27;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DS483");
	strcpy(empEsc.nombre,"Duetschens Rayhill, Samuele Norry");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=4336.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OW642");
	strcpy(empEsc.nombre,"Stanning Studman, Lorry Larissa");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=3923.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GQ109");
	strcpy(empEsc.nombre,"Fine Wilds, Pascale Benedikt");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=1160.27;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OK974");
	strcpy(empEsc.nombre,"Faithfull Instrell, Baird Graig");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=4209.39;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JN244");
	strcpy(empEsc.nombre,"Keywood McPherson, Aldis Vincenz");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=30;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=2352.16;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RW466");
	strcpy(empEsc.nombre,"Venner Butler, Hiram Leonid");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=1;
	empEsc.cantFamSeg=3;
	empEsc.salario=1719.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SH055");
	strcpy(empEsc.nombre,"Codron Harnor, Donall Yves");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=2577.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QD532");
	strcpy(empEsc.nombre,"Golthorpp Elderfield, Doyle Laurence");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=2251.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZJ769");
	strcpy(empEsc.nombre,"Ebbles Readitt, Danny Urbano");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=3839.12;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SU574");
	strcpy(empEsc.nombre,"Champain Endon, Gregor Bastien");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=3225.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RM896");
	strcpy(empEsc.nombre,"Wolvey Deverell, Phillipp Rem");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=3849.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NI841");
	strcpy(empEsc.nombre,"Lethley Pilpovic, Ripley Cross");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=20;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=4362.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UU859");
	strcpy(empEsc.nombre,"Hause Cubbit, Allard Nealson");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=1620.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WM119");
	strcpy(empEsc.nombre,"Bacup Wraggs, Ruthe Tess");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=2305.81;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RN542");
	strcpy(empEsc.nombre,"Piatkowski Jacklin, Sinclair Hartley");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1418.11;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QX038");
	strcpy(empEsc.nombre,"Willshee Caygill, Marion Fields");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=1367.47;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FW333");
	strcpy(empEsc.nombre,"O Byrne Jellico, Woodman Claybourne");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=8;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=2393.74;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WF843");
	strcpy(empEsc.nombre,"Duggleby Gregg, Nigel Sergeant");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=3639.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EB680");
	strcpy(empEsc.nombre,"Arundel Bircher, Berkie Jacky");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=1746.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AB910");
	strcpy(empEsc.nombre,"Jutson Vernazza, Sam Winslow");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=4002.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GY482");
	strcpy(empEsc.nombre,"Gonet Kardos, Orel Kali");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=3351.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JF300");
	strcpy(empEsc.nombre,"Mosedale Torre, Dino Inglis");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=3437.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FX361");
	strcpy(empEsc.nombre,"Cartmail Angell, Corey Rod");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=3244.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZK789");
	strcpy(empEsc.nombre,"Lippiatt Burley, Baryram Regen");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=3917.29;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EO748");
	strcpy(empEsc.nombre,"Jatczak Grimmolby, Isa Saleem");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=2933.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EI108");
	strcpy(empEsc.nombre,"Demoge Gelling, Antonius Stan");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=9;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=2054.73;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CU022");
	strcpy(empEsc.nombre,"Tubbs Yurin, Renaldo Feliks");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=2096.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CX767");
	strcpy(empEsc.nombre,"Fredi Blanden, Isaak Barclay");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=2744.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JA216");
	strcpy(empEsc.nombre,"Clarkson Scammonden, Panchito Chance");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=2446.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WO080");
	strcpy(empEsc.nombre,"Stilly Tidman, Tanny Griffin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=6;
	empEsc.cantFamSeg=1;
	empEsc.salario=3025.54;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MY554");
	strcpy(empEsc.nombre,"Sleightholme Dmitrievski, Mandel Hillel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=3553.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BO809");
	strcpy(empEsc.nombre,"Hast Eltun, Sauncho Doy");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=21;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=1572.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LN376");
	strcpy(empEsc.nombre,"Lambden Riggey, Manolo Quent");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=6;
	empEsc.cantFamSeg=3;
	empEsc.salario=3891.24;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ES219");
	strcpy(empEsc.nombre,"Sillick Zanicchelli, Ferdinanda Rochelle");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=15;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=2666.39;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RS854");
	strcpy(empEsc.nombre,"Inold Willey, Buddy Domenic");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=3005.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YX909");
	strcpy(empEsc.nombre,"Knapper Dedrick, Olivier Stanleigh");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=8;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=1192.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RC755");
	strcpy(empEsc.nombre,"Bosdet Dumphrey, Waylan Gavan");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=3;
	empEsc.cantFamSeg=6;
	empEsc.salario=4179.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UJ546");
	strcpy(empEsc.nombre,"Gilhooly Denk, Blaine Enos");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=1655.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LV531");
	strcpy(empEsc.nombre,"Buckhurst Giraldon, Obie Clayton");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=6;
	empEsc.cantFamSeg=4;
	empEsc.salario=3525.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TF506");
	strcpy(empEsc.nombre,"Eastcott Inskipp, Rick Jimmie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=3207.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SL043");
	strcpy(empEsc.nombre,"Goldine Cockett, Phylis Martina");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=2886.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GF889");
	strcpy(empEsc.nombre,"Drakeford Start, Horacio John");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=2476.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WY411");
	strcpy(empEsc.nombre,"Romushkin Newvell, Darell Bryn");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=4257.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TH395");
	strcpy(empEsc.nombre,"Rapa Hunnam, Jaye Darb");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=1215.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MY721");
	strcpy(empEsc.nombre,"Blay Townend, Reilly Ferdie");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=16;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=3209.81;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WJ640");
	strcpy(empEsc.nombre,"Diggins Goymer, Yuma Stevy");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=3546.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RC155");
	strcpy(empEsc.nombre,"Tunuy Augar, Barrett Mitchell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=3746.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IU563");
	strcpy(empEsc.nombre,"Pury Jerratsch, Victoir Harry");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=3207.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WF833");
	strcpy(empEsc.nombre,"Houlson Breagan, Tremaine Obed");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=2625.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QN943");
	strcpy(empEsc.nombre,"Missington Degnen, Colline Merola");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=1668.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GZ037");
	strcpy(empEsc.nombre,"Pourveer Chaytor, Ludvig Raimund");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=8;
	empEsc.cantFamSeg=1;
	empEsc.salario=2013.61;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XG249");
	strcpy(empEsc.nombre,"Titley Huglin, Sheff Gonzalo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=3072.62;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YN444");
	strcpy(empEsc.nombre,"Livock Ascraft, Janaya Adella");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=1636.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XW115");
	strcpy(empEsc.nombre,"OCorhane Goalley, Felizio Terrell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=1568.98;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HE419");
	strcpy(empEsc.nombre,"Finci Duffit, Ingar Rollo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=8;
	empEsc.cantFamSeg=6;
	empEsc.salario=2889.73;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XL363");
	strcpy(empEsc.nombre,"Maxweell Ferry, Tommy Waylon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=1418.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ID353");
	strcpy(empEsc.nombre,"Cow Mulryan, Virgil Wittie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=2692.21;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PH541");
	strcpy(empEsc.nombre,"Abrahmson Hendrich, Vivi Laural");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=2265.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GL072");
	strcpy(empEsc.nombre,"Ongin Hallor, Sergeant Michale");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=3215.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EU011");
	strcpy(empEsc.nombre,"Reinhard Trimmell, Gan Artie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=1024.54;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XC717");
	strcpy(empEsc.nombre,"Grendon Mault, Skelly Waldon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=2280.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HA520");
	strcpy(empEsc.nombre,"McGavin Sellman, Ignatius Reinold");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=2969.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZX336");
	strcpy(empEsc.nombre,"Lawley Culbert, Helenka Babita");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=2027.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NY051");
	strcpy(empEsc.nombre,"Fasse Sign, Kendell Brenden");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=1599.47;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SA927");
	strcpy(empEsc.nombre,"Champneys Glasscock, Colet Ernie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=1304.85;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WJ008");
	strcpy(empEsc.nombre,"Westrip Kays, Byrann Rollie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=3921.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TK954");
	strcpy(empEsc.nombre,"Zoppo Petrol, Nicola Dolley");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=4055.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UF789");
	strcpy(empEsc.nombre,"Chewter Hutcheon, Elvin Percy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=1322.21;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BX763");
	strcpy(empEsc.nombre,"Simoes Trevena, Malinda Gabbi");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=2750.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VU623");
	strcpy(empEsc.nombre,"Eilhermann Bartoszinski, Ninon Thalia");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=4400.74;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BM436");
	strcpy(empEsc.nombre,"Strangeway Barsham, Valentijn Arlan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=3695.19;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VV324");
	strcpy(empEsc.nombre,"Beathem Doby, Danie Vasili");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=3798.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ON199");
	strcpy(empEsc.nombre,"Scrigmour Massinger, Lucien Reggis");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=1013.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UM976");
	strcpy(empEsc.nombre,"Chapiro Lantuffe, Ernst Hersch");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=25;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=2469.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TR802");
	strcpy(empEsc.nombre,"Sellick Bannon, Jeno Dani");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=2;
	empEsc.cantFamSeg=3;
	empEsc.salario=3587.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DI236");
	strcpy(empEsc.nombre,"Alenichev Brocklesby, Albie Dew");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=3062.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OA762");
	strcpy(empEsc.nombre,"Wakeley Musicka, Reuben Tann");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=4018.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PX690");
	strcpy(empEsc.nombre,"Smythin Sleeman, Somerset Sax");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=30;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=2234.18;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EN022");
	strcpy(empEsc.nombre,"Niset Critch, Otho Ingemar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=3640.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QT157");
	strcpy(empEsc.nombre,"Schindler Coghlin, Adam Jereme");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=1446.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BN102");
	strcpy(empEsc.nombre,"Canfer Lynnett, Edgard Stefan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=4305.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PD975");
	strcpy(empEsc.nombre,"Emanuelov Bruin, Ruthann Annecorinne");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=3145.47;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ED347");
	strcpy(empEsc.nombre,"Musk Yushachkov, Sampson Ashlin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=1595.19;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UG127");
	strcpy(empEsc.nombre,"Garfirth Codron, Kendricks Jasun");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=21;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=2755.61;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BN091");
	strcpy(empEsc.nombre,"Lambert-Ciorwyn Dyment, Hubie Bentlee");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=2778.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GI055");
	strcpy(empEsc.nombre,"Janks Fahrenbacher, Saw Flint");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=2919.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VD956");
	strcpy(empEsc.nombre,"Gerleit Karleman, Benedick Agustin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=4271.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DB910");
	strcpy(empEsc.nombre,"Fortoun Carlill, Abrahan Nils");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=1;
	empEsc.cantFamSeg=3;
	empEsc.salario=2052.73;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UZ737");
	strcpy(empEsc.nombre,"Pavolini Bourton, Delmor Sinclare");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=6;
	empEsc.cantFamSeg=4;
	empEsc.salario=1511.78;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AQ039");
	strcpy(empEsc.nombre,"Downe Womersley, Nevin Tull");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=3236.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VY098");
	strcpy(empEsc.nombre,"Kay Arckoll, Mortie Allistir");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=26;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=2327.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LZ355");
	strcpy(empEsc.nombre,"Fibbens Malia, Emmi Adara");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=1269.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YR449");
	strcpy(empEsc.nombre,"Almak Rodie, Giselbert Waverly");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=30;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=4408.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"US105");
	strcpy(empEsc.nombre,"Wickens Tomovic, Rolf Gabe");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=2402.38;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UW235");
	strcpy(empEsc.nombre,"Jenkyn Scallon, Prentice Etienne");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=4462.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MK700");
	strcpy(empEsc.nombre,"Newall Cadge, Tanner Adriano");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=6;
	empEsc.cantFamSeg=3;
	empEsc.salario=4144.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JH310");
	strcpy(empEsc.nombre,"Martin Ackrill, Byran Kelly");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=3090.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LN809");
	strcpy(empEsc.nombre,"McKeating Wharton, Normand Mayer");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=1854.21;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RC678");
	strcpy(empEsc.nombre,"Sharpous Packer, Lombard Lorry");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=14;
	empEsc.cargo=8;
	empEsc.cantFamSeg=1;
	empEsc.salario=3923.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MR023");
	strcpy(empEsc.nombre,"Somerled OLeary, Ripley Maddie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=1475.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UC456");
	strcpy(empEsc.nombre,"Thorneywork Wilflinger, Mano Bruis");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=1227.61;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZA297");
	strcpy(empEsc.nombre,"Huddles Stainton, Yulma Jimmie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=3010.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RX352");
	strcpy(empEsc.nombre,"Brinsden Clementi, Dimitry Jozef");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=2305.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NK775");
	strcpy(empEsc.nombre,"Quigley Ornils, Christie Alfy");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=3190.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZQ900");
	strcpy(empEsc.nombre,"Ropcke Twede, Sandra Callida");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=1954.33;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QQ039");
	strcpy(empEsc.nombre,"Antonijevic Emeline, Ado Thom");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=30;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=4227.85;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OS719");
	strcpy(empEsc.nombre,"Arnal Wais, Staford Ruggiero");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=1407.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SX955");
	strcpy(empEsc.nombre,"Smidmore Delwater, Oriana Jennica");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=10;
	empEsc.cargo=2;
	empEsc.cantFamSeg=7;
	empEsc.salario=3640.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EN205");
	strcpy(empEsc.nombre,"MacGahey Armor, Gayleen Nonnah");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=10;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=2589.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HG954");
	strcpy(empEsc.nombre,"Friday Syer, Valentine Killy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=1004.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NH785");
	strcpy(empEsc.nombre,"Giggie Floodgate, Jen Netta");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=2116.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OL605");
	strcpy(empEsc.nombre,"Comelini Kienzle, Benjie Terence");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=7;
	empEsc.cantFamSeg=3;
	empEsc.salario=1663.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TV241");
	strcpy(empEsc.nombre,"Whatling Gniewosz, Corney Kelley");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=4432.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UZ154");
	strcpy(empEsc.nombre,"Achrameev Brackstone, Gav Siward");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=1351.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CO988");
	strcpy(empEsc.nombre,"Ettels Sapseed, Spencer Clemente");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=3005.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UB277");
	strcpy(empEsc.nombre,"Lindbergh Demanche, Felice Chrisse");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=1398.44;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FV863");
	strcpy(empEsc.nombre,"Warn Di Baudi, Terri Pavel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=4007.12;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UU746");
	strcpy(empEsc.nombre,"Janiszewski Ashbolt, Scarface Frannie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=4109.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BC066");
	strcpy(empEsc.nombre,"Debenham Bottle, Dalli Gard");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=2692.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YH098");
	strcpy(empEsc.nombre,"Kemmons Alonso, Sara Fleurette");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=8;
	empEsc.cantFamSeg=6;
	empEsc.salario=2476.52;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ME800");
	strcpy(empEsc.nombre,"Brennans Madigan, Olenolin Mitchael");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=2;
	empEsc.cantFamSeg=3;
	empEsc.salario=3930.16;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WC948");
	strcpy(empEsc.nombre,"Latour Peddersen, Louis Jervis");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=1;
	empEsc.cantFamSeg=6;
	empEsc.salario=2954.22;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YW664");
	strcpy(empEsc.nombre,"Mersey Ludy, Laird Aldon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=4259.84;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZJ424");
	strcpy(empEsc.nombre,"Scales Sammars, Peadar Ansell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1490.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YG717");
	strcpy(empEsc.nombre,"Frears Schollar, Sukey Ingrid");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=3970.81;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PO841");
	strcpy(empEsc.nombre,"Greengrass Godden, Timothee Lawrence");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=3697.54;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TS586");
	strcpy(empEsc.nombre,"Cullinan Ulyatt, Dex Sydney");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=1971.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ME758");
	strcpy(empEsc.nombre,"Townrow Hoyt, Selie Nara");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=3928.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZY731");
	strcpy(empEsc.nombre,"Annwyl Grigori, Darleen Breena");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=3240.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YL993");
	strcpy(empEsc.nombre,"Oxteby Kencott, Randie Harvey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=3390.44;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OR234");
	strcpy(empEsc.nombre,"Spight Arunowicz, Doy Shellysheldon");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=8;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=1792.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GR942");
	strcpy(empEsc.nombre,"Karpf Schruurs, Dallas Von");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=10;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=4016.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CL601");
	strcpy(empEsc.nombre,"Attenbrow De Giorgi, Stanley Theodoric");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=8;
	empEsc.cantFamSeg=1;
	empEsc.salario=1298.52;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FR428");
	strcpy(empEsc.nombre,"Island Cassella, Seward Murdoch");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=2027.57;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SE162");
	strcpy(empEsc.nombre,"Jovicic Ardling, Caspar Gifford");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1993.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GN037");
	strcpy(empEsc.nombre,"Aizlewood Reace, Gawen Burtie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=3104.18;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BV116");
	strcpy(empEsc.nombre,"Pollock Selly, Valaria Coralie");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=1087.91;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PV226");
	strcpy(empEsc.nombre,"Sellors Algy, Bud Lindon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=4126.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZZ583");
	strcpy(empEsc.nombre,"Gosling Pettwood, Brandi Ericka");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=2120.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UN651");
	strcpy(empEsc.nombre,"Newbury Sweating, Toby Gray");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=3755.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GI775");
	strcpy(empEsc.nombre,"Pischel Folley, Catharine Lesya");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=27;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=1332.61;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RE519");
	strcpy(empEsc.nombre,"Oller Jerg, Val Godart");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=3590.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HQ928");
	strcpy(empEsc.nombre,"Furmedge Simm, Faulkner Sanson");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=3960.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FX203");
	strcpy(empEsc.nombre,"Rickcord Frankcomb, Morris Sayre");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=3888.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DG432");
	strcpy(empEsc.nombre,"Gout Coulson, Rorke Titus");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=14;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=4132.78;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PD934");
	strcpy(empEsc.nombre,"Hewlings Curnokk, Tiena Aindrea");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=2012.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FU900");
	strcpy(empEsc.nombre,"Albiston Burmaster, Rosco Woodman");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=2431.38;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JI533");
	strcpy(empEsc.nombre,"Haacker Coatts, Lexine Ardyce");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=2220.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GE436");
	strcpy(empEsc.nombre,"Dumbrill Kyberd, Daren Markus");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=1371.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IJ120");
	strcpy(empEsc.nombre,"Remmers Vanyashkin, Allys Sheelah");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=1;
	empEsc.cantFamSeg=6;
	empEsc.salario=1122.78;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZJ058");
	strcpy(empEsc.nombre,"Pasquale Durman, Sloan Tadeo");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=2080.16;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QC484");
	strcpy(empEsc.nombre,"Kett Pridie, Adamo Sandor");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=2904.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ET162");
	strcpy(empEsc.nombre,"Faulconbridge Dalglish, Fidelia Hildagarde");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=4390.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PI386");
	strcpy(empEsc.nombre,"Eilhart Powers, Frannie Bartholomew");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=2105.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UW227");
	strcpy(empEsc.nombre,"Lynas Auchterlonie, Van Mayor");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=10;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=2646.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XE056");
	strcpy(empEsc.nombre,"Goulden Sweetzer, Baron Creigh");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=4280.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KJ566");
	strcpy(empEsc.nombre,"Bentote Overil, Kendricks Park");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=2312.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AG311");
	strcpy(empEsc.nombre,"Melan Goring, Wright Jodi");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=1132.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PM794");
	strcpy(empEsc.nombre,"Eltune Kingswood, Cornie Alex");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=1187.49;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FT990");
	strcpy(empEsc.nombre,"Cornbill Jirek, Worth Marty");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=2938.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WT817");
	strcpy(empEsc.nombre,"Thomazin Ruppert, Rancell Erie");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=29;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=3610.74;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KC990");
	strcpy(empEsc.nombre,"Barlee Parrott, Thom Waldemar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=1817.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VG083");
	strcpy(empEsc.nombre,"Shevlin Matthews, Michele Garrick");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=2539.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KA757");
	strcpy(empEsc.nombre,"OCrowley Cosin, Eric Culver");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=3021.53;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RF421");
	strcpy(empEsc.nombre,"Desquesnes Aikman, Olav Joaquin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=2451.33;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BS147");
	strcpy(empEsc.nombre,"Geroldini Lyosik, Loella Susette");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=1205.12;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MG429");
	strcpy(empEsc.nombre,"Bushe Alcoran, Dalston Waite");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=1592.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DC667");
	strcpy(empEsc.nombre,"Bennike Blockey, Sandro Alphard");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=2027.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZI614");
	strcpy(empEsc.nombre,"McMeeking Dulton, Damien Finlay");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=1250.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZD583");
	strcpy(empEsc.nombre,"Brundale Linner, Giusto Marlow");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=1691.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GV047");
	strcpy(empEsc.nombre,"Cowthard Glidder, Neale Natty");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=2336.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TT692");
	strcpy(empEsc.nombre,"Stanners McInnerny, Hubie Estevan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=3388.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XK555");
	strcpy(empEsc.nombre,"Caze Mancer, Stanly Staford");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=1716.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QL364");
	strcpy(empEsc.nombre,"Jenkin Lung, Abner Nevins");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=3408.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WA772");
	strcpy(empEsc.nombre,"Puttock Fleisch, Pierce Shellysheldon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=2179.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XL163");
	strcpy(empEsc.nombre,"Grgic Milmore, Beatrice Brear");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=4251.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HJ221");
	strcpy(empEsc.nombre,"Whyke Furber, Ignaz Egbert");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=2520.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XD664");
	strcpy(empEsc.nombre,"Baugh Durber, Loren Rodrick");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=1713.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VM172");
	strcpy(empEsc.nombre,"Fanning Janisson, Ellary Barthel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=1482.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TS182");
	strcpy(empEsc.nombre,"Jaggard Balaam, Gearalt Fax");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=3542.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PM167");
	strcpy(empEsc.nombre,"Witt Wetherell, Hoyt Ely");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=3;
	empEsc.cantFamSeg=6;
	empEsc.salario=2722.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QG199");
	strcpy(empEsc.nombre,"Flann Zupo, Estrella Junia");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=2;
	empEsc.cantFamSeg=3;
	empEsc.salario=3625.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KX333");
	strcpy(empEsc.nombre,"Kempshall Howbrook, Cammy Briano");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=3459.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JT963");
	strcpy(empEsc.nombre,"Castanos Gilogly, Ludvig Connor");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=2833.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KQ150");
	strcpy(empEsc.nombre,"Avory Bulfoot, Colin Giordano");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=1;
	empEsc.cantFamSeg=8;
	empEsc.salario=2745.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MW860");
	strcpy(empEsc.nombre,"Pizzey Bartolommeo, Packston Renard");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=2933.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LL251");
	strcpy(empEsc.nombre,"Quantrell Kadd, Gav Jayson");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=6;
	empEsc.cantFamSeg=1;
	empEsc.salario=4412.49;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JN382");
	strcpy(empEsc.nombre,"OLennane Ryland, Derek Derril");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=1348.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FI028");
	strcpy(empEsc.nombre,"Roxbee Pregel, Witty Holt");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=3690.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VJ951");
	strcpy(empEsc.nombre,"Kindon McKerrow, Cordell Rossy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=3789.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LX279");
	strcpy(empEsc.nombre,"Izen Wooster, Jefferey Culley");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=2081.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BI189");
	strcpy(empEsc.nombre,"Parbrook Thompson, Wake Hermon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=8;
	empEsc.cantFamSeg=6;
	empEsc.salario=4356.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NU194");
	strcpy(empEsc.nombre,"Ramel Eastby, Darcy Beaufort");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=3190.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HI988");
	strcpy(empEsc.nombre,"Small Tongs, Toiboid Jermayne");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=7;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=3226.29;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZB453");
	strcpy(empEsc.nombre,"Thornton Struijs, Gilles Evelin");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=4385.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SE139");
	strcpy(empEsc.nombre,"Ellesmere Redman, Pate Hamlin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=3752.91;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OX287");
	strcpy(empEsc.nombre,"Durrington Chessel, Deena Laurena");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=1375.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TW519");
	strcpy(empEsc.nombre,"Gussie Stickins, Fields Alonso");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=1251.26;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HA776");
	strcpy(empEsc.nombre,"Mounsey Bransdon, Moritz Baillie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=2357.38;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZX923");
	strcpy(empEsc.nombre,"Pierpoint Bultitude, Lawrence Lazar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=1720.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CB100");
	strcpy(empEsc.nombre,"Adame Coalburn, Odo Rad");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=2122.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AU416");
	strcpy(empEsc.nombre,"Ledwith Kauble, Gaspard Ward");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=4459.39;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JZ600");
	strcpy(empEsc.nombre,"Speddin Kobus, Jenny Joellyn");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=3625.22;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MK981");
	strcpy(empEsc.nombre,"Roseborough Grocock, Travus Broderick");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=2447.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WX014");
	strcpy(empEsc.nombre,"Vedyashkin Griswood, Hilly Malchy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=2605.11;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SW598");
	strcpy(empEsc.nombre,"Portis Domleo, Carroll Alonso");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=25;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=4146.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EP797");
	strcpy(empEsc.nombre,"Desforges Cathrae, Conroy Goddard");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=2176.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UJ136");
	strcpy(empEsc.nombre,"Laidlow MacPherson, Aristotle Boigie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=1458.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DH665");
	strcpy(empEsc.nombre,"Burling Mineghelli, Jamison Sergent");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=4310.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DS373");
	strcpy(empEsc.nombre,"Tremayne Yackiminie, Butch Ron");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=2002.52;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TU061");
	strcpy(empEsc.nombre,"Pfaffel Siflet, Arty Graehme");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=23;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=2512.51;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DW717");
	strcpy(empEsc.nombre,"Huton Eades, Bern Carroll");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=2240.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VS017");
	strcpy(empEsc.nombre,"Kasparski Lapree, Chane Frank");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=1518.66;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EE126");
	strcpy(empEsc.nombre,"Dillinger Mayger, Karlis Euell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=2423.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JK033");
	strcpy(empEsc.nombre,"Klimas Feldberg, Jeffry Mohandis");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=2939.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BK545");
	strcpy(empEsc.nombre,"Van Rembrandt Rushford, Morton Ambrosio");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=3789.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IM299");
	strcpy(empEsc.nombre,"Pactat Robilart, Ganny Cristiano");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=1437.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DM601");
	strcpy(empEsc.nombre,"Gaudon Wells, Stanislas Konstantin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=3335.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZV427");
	strcpy(empEsc.nombre,"Fowgies Curnokk, Adriano North");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=1;
	empEsc.cantFamSeg=3;
	empEsc.salario=2565.62;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZT388");
	strcpy(empEsc.nombre,"Clayton Gerrett, Terencio Jonah");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1263.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GF577");
	strcpy(empEsc.nombre,"Bartoszewski Courtes, Bent Gardner");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=3563.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RC152");
	strcpy(empEsc.nombre,"Van der Merwe Escolme, Ellyn Dulciana");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=4157.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JQ412");
	strcpy(empEsc.nombre,"Heak Bartles, Wilmar Ase");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=3409.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FH014");
	strcpy(empEsc.nombre,"Brawn Cockson, Karoly Niko");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=5;
	empEsc.salario=1008.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IX421");
	strcpy(empEsc.nombre,"Martineau Trigg, Arabel Bobbye");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=7;
	empEsc.cantFamSeg=3;
	empEsc.salario=2419.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GC094");
	strcpy(empEsc.nombre,"Benne Roizin, Whitney Regen");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=1370.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PM796");
	strcpy(empEsc.nombre,"Reeves De Robertis, Arlan Addison");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=22;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=2184.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GT543");
	strcpy(empEsc.nombre,"Skirling Stentiford, Avram Hamilton");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=2621.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NT653");
	strcpy(empEsc.nombre,"Rubee Stallion, Coreen Daveta");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=2452.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UZ492");
	strcpy(empEsc.nombre,"Scohier Masser, Freddie Oberon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=2294.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MU161");
	strcpy(empEsc.nombre,"Masser Card, Aristotle Erie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=1369.98;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UH447");
	strcpy(empEsc.nombre,"Walczak Pettwood, Baillie Bing");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=3675.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FM272");
	strcpy(empEsc.nombre,"Wimes Moon, Colman Rockwell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=4492.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TY944");
	strcpy(empEsc.nombre,"Highway Johannes, Jade Zilvia");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=3189.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LE792");
	strcpy(empEsc.nombre,"Austen Jacklin, Tybalt Panchito");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=3736.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UR462");
	strcpy(empEsc.nombre,"Degoey Kingaby, Maurene Aubrey");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=3434.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GA183");
	strcpy(empEsc.nombre,"Peeke-Vout Ayliff, Heindrick Nehemiah");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=2335.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JG487");
	strcpy(empEsc.nombre,"Nurny Fenelow, Lorrin Teressa");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=3022.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JI785");
	strcpy(empEsc.nombre,"Betterton Lahrs, Ches Matty");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=20;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=4162.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KQ292");
	strcpy(empEsc.nombre,"Queenborough Pesterfield, Hayyim Tuckie");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=2643.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SH635");
	strcpy(empEsc.nombre,"Bradnum Kittles, Yorgos Merell");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=3864.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XX037");
	strcpy(empEsc.nombre,"Cranshaw Hanratty, Sileas Dasie");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=2160.78;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SE879");
	strcpy(empEsc.nombre,"Cowburn Dixson, Maje Ferdy");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=3854.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PG140");
	strcpy(empEsc.nombre,"McIleen Gillibrand, Bertram Felicio");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=4369.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SA337");
	strcpy(empEsc.nombre,"Ratter Dureden, Corney Andres");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=1;
	empEsc.cantFamSeg=3;
	empEsc.salario=3014.53;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ME993");
	strcpy(empEsc.nombre,"Pepineaux Leisman, Zacharias Nathanial");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=9;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=1830.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AV186");
	strcpy(empEsc.nombre,"Sharer Cruttenden, Kingsley Darrin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=2826.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SF545");
	strcpy(empEsc.nombre,"Thorp Iacapucci, Alaric Bevon");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=27;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=4119.33;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NA287");
	strcpy(empEsc.nombre,"Middlemist McCool, Lawton Lowrance");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=4464.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FT301");
	strcpy(empEsc.nombre,"Grabb Margram, Kenny Georgie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=2;
	empEsc.cantFamSeg=7;
	empEsc.salario=3727.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NJ713");
	strcpy(empEsc.nombre,"Klima Sieve, Pierce Kendricks");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=15;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=3361.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JQ812");
	strcpy(empEsc.nombre,"Brunet Pickerin, Arni Byron");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=2886.98;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VW312");
	strcpy(empEsc.nombre,"Redington Glacken, Verne Garv");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=4335.12;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WT171");
	strcpy(empEsc.nombre,"Lillicrap Rigolle, Base Berke");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=1737.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KK956");
	strcpy(empEsc.nombre,"Abramof Jack, Milty Burgess");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=2082.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HV522");
	strcpy(empEsc.nombre,"Bettington Kitchinghan, Nikos Travers");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=1346.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RA996");
	strcpy(empEsc.nombre,"Ebbotts Puve, Alida Lin");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=3889.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YI542");
	strcpy(empEsc.nombre,"Romanin Ballendine, Pat Maxim");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=27;
	empEsc.cargo=7;
	empEsc.cantFamSeg=3;
	empEsc.salario=3643.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KZ949");
	strcpy(empEsc.nombre,"O'Boyle Pattingson, Lela Ashlan");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=6;
	empEsc.cantFamSeg=8;
	empEsc.salario=1033.22;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LA641");
	strcpy(empEsc.nombre,"Pedgrift Hartgill, Chris Gerry");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=3699.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GV589");
	strcpy(empEsc.nombre,"Leadbeater Bellany, Jourdain Case");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=27;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=2127.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GZ743");
	strcpy(empEsc.nombre,"Coopper Bigglestone, Igor Nehemiah");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=8;
	empEsc.cantFamSeg=5;
	empEsc.salario=4176.38;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CF941");
	strcpy(empEsc.nombre,"Habbon Winspear, Leeland Giselbert");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=3967.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MS484");
	strcpy(empEsc.nombre,"Keming Rotte, Brander Gregory");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=1568.73;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DV850");
	strcpy(empEsc.nombre,"Cullagh Penning, Ive Judon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=3675.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WR140");
	strcpy(empEsc.nombre,"Reck Jime, Geoff Anselm");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=3362.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TL103");
	strcpy(empEsc.nombre,"Mulbery Mowbray, Corty Yorgo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=4379.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TJ717");
	strcpy(empEsc.nombre,"Morkham Gatherell, Basilius Jarad");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=1;
	empEsc.cantFamSeg=6;
	empEsc.salario=1413.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UJ884");
	strcpy(empEsc.nombre,"Kleisel McCurtin, Michael Emilio");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=1153.18;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HM940");
	strcpy(empEsc.nombre,"Kennett Lambie, Kevin Thaine");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=8;
	empEsc.cantFamSeg=5;
	empEsc.salario=1149.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PS913");
	strcpy(empEsc.nombre,"Speedy Lawey, Cam Pamela");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=1235.22;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CJ733");
	strcpy(empEsc.nombre,"Calken Mabey, Noland Jud");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=1895.11;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MM502");
	strcpy(empEsc.nombre,"Swadling Worboy, Lindsey Yuri");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=1201.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IW135");
	strcpy(empEsc.nombre,"Harridge Falconar, Milty Zak");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=1205.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JJ503");
	strcpy(empEsc.nombre,"Pavier Bann, Burnaby Gonzalo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=2429.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZP787");
	strcpy(empEsc.nombre,"Wais Soppett, Mandy Mozelle");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=2597.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XE311");
	strcpy(empEsc.nombre,"Lahive OFergus, Donnie Herc");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=2456.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QQ898");
	strcpy(empEsc.nombre,"Loving Priscott, Hilario Anderson");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=3870.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DF360");
	strcpy(empEsc.nombre,"Sisneros Rummins, Binky Frederick");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=2020.61;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SM262");
	strcpy(empEsc.nombre,"Blade Mcwhinnie, Yankee Zak");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=3364.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZN992");
	strcpy(empEsc.nombre,"Kobieriecki oldey, Shayne Chicky");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=3831.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EA557");
	strcpy(empEsc.nombre,"Aylesbury Cloney, Jacobo Reinaldo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=1085.57;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PX804");
	strcpy(empEsc.nombre,"Prosek Sanders, Giorgi Murdoch");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1874.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PG691");
	strcpy(empEsc.nombre,"Faragan Martynov, Con Janenna");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=3230.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XW011");
	strcpy(empEsc.nombre,"Crumley Ludgrove, Waldon Alejoa");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=3364.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ES303");
	strcpy(empEsc.nombre,"Bambury Dugald, Gretchen Philippine");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=6;
	empEsc.cantFamSeg=3;
	empEsc.salario=2457.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DT989");
	strcpy(empEsc.nombre,"Pourveer Hoffman, Cathi Klarrisa");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=3;
	empEsc.cantFamSeg=6;
	empEsc.salario=3359.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VD999");
	strcpy(empEsc.nombre,"Drewson Bromige, Cornelius Randal");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=3108.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AO755");
	strcpy(empEsc.nombre,"Mc Giffin Doring, Dino Antony");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=2777.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HD643");
	strcpy(empEsc.nombre,"Dundridge Franzetti, Monro Robbert");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=1571.66;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CS672");
	strcpy(empEsc.nombre,"Knighton Tedman, Basilius Benji");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=17;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=1724.51;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RJ519");
	strcpy(empEsc.nombre,"Julien Geraldi, Mayne Gonzales");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=3803.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FL221");
	strcpy(empEsc.nombre,"Hannen MacCahee, Ky Anatollo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=1341.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XS026");
	strcpy(empEsc.nombre,"Flowith Iacobacci, Godfree Patty");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=2589.53;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VN841");
	strcpy(empEsc.nombre,"Apfelmann Glassman, Dew Marietta");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=1950.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MS722");
	strcpy(empEsc.nombre,"Jerrams Parkinson, Bowie Elvin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=4290.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VK108");
	strcpy(empEsc.nombre,"Pollicatt Alldread, Ingrim Shadow");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=3126.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CX824");
	strcpy(empEsc.nombre,"McTrustrie Eastman, Garry Albrecht");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=4485.91;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YL909");
	strcpy(empEsc.nombre,"Pedel Branston, Teador Joaquin");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=30;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=2025.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MC825");
	strcpy(empEsc.nombre,"Kielt Comolli, Baxy Prentice");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=4371.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TR648");
	strcpy(empEsc.nombre,"Achromov Powdrell, Ricki Ernie");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=20;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=3590.33;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RW516");
	strcpy(empEsc.nombre,"Titterell Borlease, Corabelle Isis");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=29;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=1928.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FS040");
	strcpy(empEsc.nombre,"Garlinge Andreichik, Chick Chilton");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=1636.66;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FU438");
	strcpy(empEsc.nombre,"Twiname Giacomuzzo, Augustine Jeffrey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=1995.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"II992");
	strcpy(empEsc.nombre,"Keegan Dearth, Monica Judye");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=8;
	empEsc.cantFamSeg=5;
	empEsc.salario=3020.39;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KG730");
	strcpy(empEsc.nombre,"Knowlson Darnell, Dewain Lek");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=1144.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NC765");
	strcpy(empEsc.nombre,"Ingledow McCaw, Case Leeland");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=2675.81;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FC252");
	strcpy(empEsc.nombre,"Gorgler Ruselin, Klaus Packston");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=7;
	empEsc.cantFamSeg=3;
	empEsc.salario=2142.29;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VL691");
	strcpy(empEsc.nombre,"Chaundy Matthewman, Jdavie Jody");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=2701.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KA577");
	strcpy(empEsc.nombre,"Agneau Tretter, Saxe Irving");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=3778.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TJ598");
	strcpy(empEsc.nombre,"Dufer Kimbury, Meris Felita");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=20;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=3104.53;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RU878");
	strcpy(empEsc.nombre,"Moine Gough, Jonas Thebault");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=4346.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZF293");
	strcpy(empEsc.nombre,"Petracco Greer, Myrah Mirilla");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=2000.52;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QQ506");
	strcpy(empEsc.nombre,"Phythian Metcalf, Averell Winslow");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=2639.29;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RX062");
	strcpy(empEsc.nombre,"Jonczyk Sollner, Brett Meryl");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=4215.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XV474");
	strcpy(empEsc.nombre,"Remington Farquharson, Forrester Kenyon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=3236.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PG246");
	strcpy(empEsc.nombre,"Ruthven Rosenstein, Jerri Enrique");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=3461.61;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EE200");
	strcpy(empEsc.nombre,"Jenkyn Gabbot, Miguel Dunn");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=1159.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MM921");
	strcpy(empEsc.nombre,"Dood Gawler, Michele Reinhold");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=3442.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XE088");
	strcpy(empEsc.nombre,"Caplin Willison, Gage Gerald");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=2905.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WU334");
	strcpy(empEsc.nombre,"Bassett Shutte, Walden Winny");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=2439.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TG712");
	strcpy(empEsc.nombre,"Flacknell Truwert, Inigo Butch");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=24;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=4269.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WA406");
	strcpy(empEsc.nombre,"Organ Gopsell, Guillema Phyllys");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=2906.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HI165");
	strcpy(empEsc.nombre,"OBrian Kirwood, Shea Augusto");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=1597.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RT452");
	strcpy(empEsc.nombre,"Blazi Flintoft, Nickie Raimund");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=7;
	empEsc.cantFamSeg=3;
	empEsc.salario=3489.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UN246");
	strcpy(empEsc.nombre,"McFfaden Feld, Rogerio Pyotr");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=2007.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EO731");
	strcpy(empEsc.nombre,"Follin Lightbourn, Lottie Lesya");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=4004.65;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TL460");
	strcpy(empEsc.nombre,"Avey Father, Bernhard Corey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=3306.74;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GK514");
	strcpy(empEsc.nombre,"Itzcovich Dimbleby, Roxie Dalenna");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=2210.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YW511");
	strcpy(empEsc.nombre,"Sibylla Huniwall, Claudell Henri");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=3762.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XG036");
	strcpy(empEsc.nombre,"Francey Densham, Raoul Constantino");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=25;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=2832.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XX758");
	strcpy(empEsc.nombre,"Kaes Tebbit, Hersh Marve");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=1065.27;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XB672");
	strcpy(empEsc.nombre,"Devonshire Keetley, Drusilla Cherilyn");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=3708.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MW847");
	strcpy(empEsc.nombre,"Tench Greswell, Bryant Dukie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=6;
	empEsc.cantFamSeg=8;
	empEsc.salario=1643.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ON656");
	strcpy(empEsc.nombre,"Milburn Golborne, Batholomew Gill");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=7;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=2998.52;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZM816");
	strcpy(empEsc.nombre,"Twizell Archley, Elroy Isa");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=4387.24;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GC332");
	strcpy(empEsc.nombre,"Stear Brayson, Antons Tomaso");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=6;
	empEsc.cantFamSeg=3;
	empEsc.salario=3960.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JG538");
	strcpy(empEsc.nombre,"Vanichev Eykel, Northrup Rey");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=1153.51;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EL314");
	strcpy(empEsc.nombre,"Arents Whimpenny, Baxter Raimundo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=4380.24;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NB752");
	strcpy(empEsc.nombre,"Theze Kleinhaus, Addie Stern");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=4446.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UH685");
	strcpy(empEsc.nombre,"Patton Bygrove, Nahum Jonas");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=8;
	empEsc.salario=1241.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FZ897");
	strcpy(empEsc.nombre,"Huitt Burthom, Lolita Mary");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=1512.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TU003");
	strcpy(empEsc.nombre,"Maydwell Utterson, Homerus Sigismond");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=2;
	empEsc.cantFamSeg=7;
	empEsc.salario=1417.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LM550");
	strcpy(empEsc.nombre,"Francescuzzi Marzele, Nevins Aguste");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=1455.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HG001");
	strcpy(empEsc.nombre,"Purkess Konerding, Bentley Bryant");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=17;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=1190.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YF558");
	strcpy(empEsc.nombre,"Gerritzen Risborough, Sandy Zedekiah");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=23;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=4355.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BJ808");
	strcpy(empEsc.nombre,"Peddel Borrill, Raddie Laney");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=2510.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XS546");
	strcpy(empEsc.nombre,"Morsey MacMorland, Vitoria Marylou");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=2694.61;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QG460");
	strcpy(empEsc.nombre,"Paler Adicot, Philippe Grayce");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=2249.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CB113");
	strcpy(empEsc.nombre,"Mordin McCane, Rocky Izaak");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=1154.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QN612");
	strcpy(empEsc.nombre,"Gumme Maven, Kennie Son");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=3206.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YV558");
	strcpy(empEsc.nombre,"Mee Kowalik, Graeme Talbot");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=3162.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KU104");
	strcpy(empEsc.nombre,"Higbin Stoneley, Jessy Bee");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=1216.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OE620");
	strcpy(empEsc.nombre,"Felderer Kingcote, Alford Ervin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=2799.38;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WQ211");
	strcpy(empEsc.nombre,"Deaves Cronchey, Reidar Arvy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=3503.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BF575");
	strcpy(empEsc.nombre,"Balderston Willingam, Ilario Ashlin");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=1826.66;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EY129");
	strcpy(empEsc.nombre,"Faulconer Aldcorne, Chip Kurt");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=2102.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SC044");
	strcpy(empEsc.nombre,"Andreia Krop, Munroe Uriah");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=2631.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FK053");
	strcpy(empEsc.nombre,"Edmonson Elsley, Vidovic Duane");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=2760.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FS406");
	strcpy(empEsc.nombre,"Yarrington Hawkswood, Courtnay Von");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=16;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=3640.54;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HI328");
	strcpy(empEsc.nombre,"Galland Farady, Sidney Yardley");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=3772.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EJ860");
	strcpy(empEsc.nombre,"Escott Howerd, Park Johny");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=2790.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KK942");
	strcpy(empEsc.nombre,"Brugman Scottesmoor, Corbin Ryley");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=11;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=3429.22;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KA819");
	strcpy(empEsc.nombre,"Havvock Bonnette, Harper Bat");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=2190.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UK614");
	strcpy(empEsc.nombre,"Ventura Dibnah, Parsifal Ken");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=4449.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YQ236");
	strcpy(empEsc.nombre,"Hakeworth Rivalant, Fax Freeland");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=3729.16;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CH023");
	strcpy(empEsc.nombre,"Jeandin Aspital, Gordon Johnathan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=2;
	empEsc.cantFamSeg=7;
	empEsc.salario=2736.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WD827");
	strcpy(empEsc.nombre,"Hillyatt Brinded, Raddy Ximenez");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=3414.54;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VS536");
	strcpy(empEsc.nombre,"Grewes Demageard, Hermie Darcy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=1;
	empEsc.cantFamSeg=3;
	empEsc.salario=3490.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NV357");
	strcpy(empEsc.nombre,"Pirrone Dickons, Vernon Farrel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=1675.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SR823");
	strcpy(empEsc.nombre,"Walden Norville, Larry Artemis");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=4;
	empEsc.cantFamSeg=3;
	empEsc.salario=1835.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MF988");
	strcpy(empEsc.nombre,"Gronaller Mingard, Brien Brian");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=2041.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZW855");
	strcpy(empEsc.nombre,"Rispin Brokenbrow, Rudolf Asher");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=3033.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GI681");
	strcpy(empEsc.nombre,"Bedle Lorand, Hamid Hasty");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=3869.52;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BT400");
	strcpy(empEsc.nombre,"Rene Velasquez, Alec Ellary");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=1801.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UI630");
	strcpy(empEsc.nombre,"Dudmarsh Pallaske, Nobie Sanford");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=2;
	empEsc.cantFamSeg=8;
	empEsc.salario=2576.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZU608");
	strcpy(empEsc.nombre,"Bellocht Simonard, Rodina Nadeen");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=2927.98;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GS699");
	strcpy(empEsc.nombre,"Jonk Belasco, Tadd Gerrie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=1002.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EP633");
	strcpy(empEsc.nombre,"Mickleburgh Ambrosetti, Cortie Ricardo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=4355.47;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SV173");
	strcpy(empEsc.nombre,"Clynmans Matuszyk, Octavius Linus");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=4254.49;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SD714");
	strcpy(empEsc.nombre,"Stanesby Fearby, Marcos Ernesto");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=1916.32;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ID978");
	strcpy(empEsc.nombre,"Freckleton Milson, Daria Iolande");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=2348.49;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HL157");
	strcpy(empEsc.nombre,"Blumson Gurery, Jock Barty");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=2582.57;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QI224");
	strcpy(empEsc.nombre,"Slimming Butler, Tove Appolonia");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=2378.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WO981");
	strcpy(empEsc.nombre,"Stayte Hackin, Berk Brendan");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=1615.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LR258");
	strcpy(empEsc.nombre,"Skunes Kendle, Northrop Carleton");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=2340.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XV898");
	strcpy(empEsc.nombre,"Skerme McClenaghan, Purcell Fairleigh");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=8;
	empEsc.cantFamSeg=5;
	empEsc.salario=1795.27;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LV067");
	strcpy(empEsc.nombre,"Killigrew Talmadge, Iver Felic");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=3805.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZC614");
	strcpy(empEsc.nombre,"Troake Wegenen, Barron Lane");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=1335.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZT507");
	strcpy(empEsc.nombre,"Godley MacIver, Edd Sholom");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=3200.91;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WT315");
	strcpy(empEsc.nombre,"Marley Petegrew, Daphne Kizzie");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=15;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=1824.12;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TZ624");
	strcpy(empEsc.nombre,"Ales0 Daviddi, Korey Nilson");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=3174.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JX605");
	strcpy(empEsc.nombre,"Delahunty Brundall, Innis Nikki");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=6;
	empEsc.salario=4067.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MC506");
	strcpy(empEsc.nombre,"Bermingham Duckhouse, Tallulah Florance");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=1884.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HV704");
	strcpy(empEsc.nombre,"Poulsum Domenge, Guthry Lyle");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1720.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SC147");
	strcpy(empEsc.nombre,"OBreen Tooke, Harland Wallache");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=3978.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HW414");
	strcpy(empEsc.nombre,"Skala Bark, Galvan Jefferey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=1123.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GO334");
	strcpy(empEsc.nombre,"Addenbrooke Beany, Abrahan Bertrando");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=8;
	empEsc.cantFamSeg=5;
	empEsc.salario=1933.19;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GC927");
	strcpy(empEsc.nombre,"Lippo Gadeaux, Dick Quincey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=1570.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JW292");
	strcpy(empEsc.nombre,"Cavet Filson, Mendy Ivar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=3394.12;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BA514");
	strcpy(empEsc.nombre,"Aymerich Saltsberger, Tab Lewiss");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=3186.65;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WB600");
	strcpy(empEsc.nombre,"Rosten Brussell, Curry Syman");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=2034.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GH451");
	strcpy(empEsc.nombre,"Doldon Joburn, Jeramey Rafaellle");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=2712.85;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FC816");
	strcpy(empEsc.nombre,"Hadwick Bullman, Jaymie Dick");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=1145.32;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QX061");
	strcpy(empEsc.nombre,"Berkelay Gartrell, Ethe Ashbey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=1028.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OG287");
	strcpy(empEsc.nombre,"Pollok Rishman, Trueman Ulberto");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=2830.12;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NN506");
	strcpy(empEsc.nombre,"Bertson Graalman, Emiline Val");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=7;
	empEsc.salario=3556.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IL358");
	strcpy(empEsc.nombre,"Gyngyll Appleford, Bill Chalmers");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=4003.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JQ704");
	strcpy(empEsc.nombre,"Coller Kenninghan, Sullivan Farris");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=16;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=2350.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OU077");
	strcpy(empEsc.nombre,"Cormack Beddis, Rafaello Aldo");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=3247.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OX124");
	strcpy(empEsc.nombre,"Gleder Ruston, Elnar Sumner");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=2746.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LQ075");
	strcpy(empEsc.nombre,"Stolte Coxwell, Parry Tobin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=3865.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AM004");
	strcpy(empEsc.nombre,"Chadburn Duffree, Angie Osborne");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=1349.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YA474");
	strcpy(empEsc.nombre,"Swanborough Clist, Pancho Fleming");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=3050.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VE613");
	strcpy(empEsc.nombre,"Sweetland Neenan, Chadwick Horatius");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=2901.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PO888");
	strcpy(empEsc.nombre,"McGerr Offell, Zachariah Neddy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=1421.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KK706");
	strcpy(empEsc.nombre,"Boddymead Lilley, Mark Claudianus");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=1758.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VJ350");
	strcpy(empEsc.nombre,"Caughey Malafe, Nicholas Morley");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=3664.98;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VK750");
	strcpy(empEsc.nombre,"Hallewell Portman, Gannon Derk");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=3243.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XC035");
	strcpy(empEsc.nombre,"Hawkes McCarney, Georgie Janos");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=4092.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZM183");
	strcpy(empEsc.nombre,"Shotboulte Preene, Bram Codie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=4337.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CI285");
	strcpy(empEsc.nombre,"Cheyne Edelheit, Phil Budd");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=2351.73;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NU885");
	strcpy(empEsc.nombre,"Evison Tunno, Inigo Garrott");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=2034.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RA731");
	strcpy(empEsc.nombre,"Whiley Isakovic, Zeke Jonathan");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=15;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=1951.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NF120");
	strcpy(empEsc.nombre,"Mawhinney Raubenheim, Rolfe Ben");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=2816.42;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DN370");
	strcpy(empEsc.nombre,"Baraclough Cooch, Jakie Frederik");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=4158.29;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PA337");
	strcpy(empEsc.nombre,"Campaigne OMailey, Iggie Nevins");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=3207.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RM564");
	strcpy(empEsc.nombre,"Arnholdt Gunney, Osbourn Nicolas");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=3805.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TH533");
	strcpy(empEsc.nombre,"Bofield Ballefant, Bethanne Babbette");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=4008.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XS127");
	strcpy(empEsc.nombre,"Ivasyushkin Scrivenor, Reeta Winonah");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=4029.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MW266");
	strcpy(empEsc.nombre,"Bonwick Tarbert, Gal Mickie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=4254.58;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DJ036");
	strcpy(empEsc.nombre,"Bruneau Watman, Sheffy Donny");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=3371.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VN903");
	strcpy(empEsc.nombre,"Errichiello Doore, Berkly Garvin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=1801.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ES581");
	strcpy(empEsc.nombre,"Bischof Reany, Edgardo Elwyn");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=3660.11;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OH096");
	strcpy(empEsc.nombre,"Jouhan Lambert-Ciorwyn, Vite Caesar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1208.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GP953");
	strcpy(empEsc.nombre,"Ughelli Cloute, Stevie Barn");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=24;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=1159.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YY992");
	strcpy(empEsc.nombre,"Guilloneau Semeradova, West Thibaud");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=3658.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RV373");
	strcpy(empEsc.nombre,"Huddleston Staten, Nikola Roderick");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=16;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=1329.81;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HT762");
	strcpy(empEsc.nombre,"Cosgreave McGeoch, Arin Raymund");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=1230.84;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SY173");
	strcpy(empEsc.nombre,"Hugueville Pinck, Zaccaria Burg");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=25;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=3219.62;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EE958");
	strcpy(empEsc.nombre,"Annandale Rawlinson, Gibb Staffard");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=6;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1955.5;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RJ578");
	strcpy(empEsc.nombre,"Downe Mullineux, Lefty Skipton");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=2878.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VZ167");
	strcpy(empEsc.nombre,"Palley Macquire, Rowland Diarmid");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=2395.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AC058");
	strcpy(empEsc.nombre,"Ledrane Wannes, Raimundo Clint");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=4283.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WG439");
	strcpy(empEsc.nombre,"Wrigley Aisman, Brandise Ranique");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=2;
	empEsc.cantFamSeg=3;
	empEsc.salario=2251.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VK965");
	strcpy(empEsc.nombre,"Hedger Ruddin, Marys Sidonnie");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=6;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=1229.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PV811");
	strcpy(empEsc.nombre,"Ell Prescote, Bondy Petey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=2669.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KJ004");
	strcpy(empEsc.nombre,"Pottberry Lidell, Chrisy Lucien");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=2214.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YX273");
	strcpy(empEsc.nombre,"Lauthian Dobbson, Augustine Aloisia");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=4;
	empEsc.cantFamSeg=3;
	empEsc.salario=4241.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HU681");
	strcpy(empEsc.nombre,"Meritt Ramplee, Siffre Alister");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=2063.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GD303");
	strcpy(empEsc.nombre,"Bernath Roseby, Godfry Finlay");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=1705.81;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AE340");
	strcpy(empEsc.nombre,"MacLaig Farrer, Orren Lazarus");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=3402.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PI574");
	strcpy(empEsc.nombre,"Kopta Purseglove, Adolpho Bengt");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=2445.26;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MK602");
	strcpy(empEsc.nombre,"Mechan Manilo, Glen Clemmy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=3614.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CL392");
	strcpy(empEsc.nombre,"Crutchley Nowakowski, Gavin Ossie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=3310.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZI108");
	strcpy(empEsc.nombre,"McDarmid Rohlfs, Der Gaylor");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=2;
	empEsc.cantFamSeg=7;
	empEsc.salario=1272.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WX446");
	strcpy(empEsc.nombre,"Seggie Avarne, Salomo Dino");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=3538.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RZ737");
	strcpy(empEsc.nombre,"Bamlet Mathou, Huberto Berke");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=20;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=1094.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EQ304");
	strcpy(empEsc.nombre,"Laycock Thurborn, Clifford Waylen");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=2012.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HS471");
	strcpy(empEsc.nombre,"Commusso Garnul, Boyce Yankee");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=3621.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FO367");
	strcpy(empEsc.nombre,"Stockau Chanter, Izaak Stevy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=2065.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WX245");
	strcpy(empEsc.nombre,"Canner Burgise, Sherwin Ezechiel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=4327.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WM559");
	strcpy(empEsc.nombre,"de Mullett McFfaden, Gearard Leonard");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=2943.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RY171");
	strcpy(empEsc.nombre,"Mauvin McClarence, Merle Arty");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=2128.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XR274");
	strcpy(empEsc.nombre,"Sweetlove Loving, Hamel Kane");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=2183.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BZ669");
	strcpy(empEsc.nombre,"Yegorshin Kerbler, Tris Joseito");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=2764.65;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YR534");
	strcpy(empEsc.nombre,"Levison Hedworth, Alethea Iolande");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=30;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=2825.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QU911");
	strcpy(empEsc.nombre,"Slidders Clitsome, Clayson Wallis");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=23;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=2318.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GZ875");
	strcpy(empEsc.nombre,"Nickoll Mattingley, Dexter Heindrick");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=2;
	empEsc.cantFamSeg=9;
	empEsc.salario=3598.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YP905");
	strcpy(empEsc.nombre,"Fishbourne Taylour, Em Ernst");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=10;
	empEsc.cargo=6;
	empEsc.cantFamSeg=10;
	empEsc.salario=1553.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LI896");
	strcpy(empEsc.nombre,"Semmence Crosbie, Ulric Bram");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=3040.57;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DV064");
	strcpy(empEsc.nombre,"MacIlwrick Johannesson, Ines Madlin");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=2329.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XX345");
	strcpy(empEsc.nombre,"Bortol Plowes, Brannon Guthrie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=3;
	empEsc.salario=3357.22;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XI771");
	strcpy(empEsc.nombre,"Mulvin Sibary, Lauritz Callean");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=1272.67;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RU102");
	strcpy(empEsc.nombre,"MacGinley Iannazzi, Nelson Sheffield");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=2752.26;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WY577");
	strcpy(empEsc.nombre,"Whate Gillaspy, Avis Hilda");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=6;
	empEsc.cantFamSeg=8;
	empEsc.salario=3247.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MP362");
	strcpy(empEsc.nombre,"Gait Bellringer, Massimo Howie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=7;
	empEsc.cantFamSeg=3;
	empEsc.salario=4107.42;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RM422");
	strcpy(empEsc.nombre,"Meese Saphir, Nealy Lewes");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=1544.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PH134");
	strcpy(empEsc.nombre,"Wallman Channing, Janos Shadow");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=3949.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CZ176");
	strcpy(empEsc.nombre,"Collumbell Wheeliker, Darius Windham");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=3257.61;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SF895");
	strcpy(empEsc.nombre,"McDermott-Row Esselen, Dane Lemar");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=1;
	empEsc.cantFamSeg=3;
	empEsc.salario=2068.42;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HM978");
	strcpy(empEsc.nombre,"Pickavance Pieter, Ferdie Eldredge");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=15;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=2662.26;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QL182");
	strcpy(empEsc.nombre,"McConnachie Renshell, Niel Brew");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=2011.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MH323");
	strcpy(empEsc.nombre,"Groome Maris, Yorgos Barris");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=2104.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IZ936");
	strcpy(empEsc.nombre,"Lattimore Toppas, Kiley Calvin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=1;
	empEsc.cantFamSeg=6;
	empEsc.salario=1170.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DH205");
	strcpy(empEsc.nombre,"Grinaugh Lapre, Phillipe Leopold");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=1997.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VM228");
	strcpy(empEsc.nombre,"Spraggon McCullagh, Auberta Maggie");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=13;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=2132.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BC898");
	strcpy(empEsc.nombre,"Mangon McBrearty, Bryanty Arthur");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=3332.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MK950");
	strcpy(empEsc.nombre,"Andrysiak Najafian, Ashlin Jerry");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=2;
	empEsc.cantFamSeg=3;
	empEsc.salario=1590.49;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"YE905");
	strcpy(empEsc.nombre,"Skellon O'Cullen, Imogene Rena");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=2181.18;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WC347");
	strcpy(empEsc.nombre,"Waby Bediss, Swen Prentiss");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=1576.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EA422");
	strcpy(empEsc.nombre,"Rook Vasyutochkin, Bobine Pietra");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=2631.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GY319");
	strcpy(empEsc.nombre,"Brightey Venn, Dehlia Tine");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=22;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=4175.85;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NJ749");
	strcpy(empEsc.nombre,"Bridal Simonato, Bentley Bastien");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=1362.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IV008");
	strcpy(empEsc.nombre,"Heard Grewes, Franciska Ursala");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=2936.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GB032");
	strcpy(empEsc.nombre,"Lowery Goodfield, Tracie Mikel");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=24;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=3383.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GN417");
	strcpy(empEsc.nombre,"Stapleton Pain, Tann Anderson");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=2981.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ME768");
	strcpy(empEsc.nombre,"Newlands Woodrow, Lesley Dukey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=1990.15;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QX668");
	strcpy(empEsc.nombre,"Toovey Klambt, Rodger Worthington");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=3848.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MP658");
	strcpy(empEsc.nombre,"Valti Eldrid, Hy Floyd");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=1500.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QG101");
	strcpy(empEsc.nombre,"Weekes Guilder, Darrin Killie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=1082.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SM795");
	strcpy(empEsc.nombre,"Agney Calway, Mart Dory");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=2907.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZG322");
	strcpy(empEsc.nombre,"Devers Avieson, Garey Shawn");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=4005.78;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UW360");
	strcpy(empEsc.nombre,"Bould Berge, Heidie Ray");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=1054.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZS199");
	strcpy(empEsc.nombre,"Flacknoe Robinett, Tamas Giffer");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=3053.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NM887");
	strcpy(empEsc.nombre,"Cuttles Avrasin, Sigfrid Standford");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=9;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=3401.44;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PE970");
	strcpy(empEsc.nombre,"Joseland Walcar, Hodge Leopold");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=19;
	empEsc.cargo=5;
	empEsc.cantFamSeg=2;
	empEsc.salario=3826.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IG779");
	strcpy(empEsc.nombre,"MacGaffey Whitehair, Rurik Fonzie");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=1940.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OO893");
	strcpy(empEsc.nombre,"Luciani Kulver, Wakefield Aldo");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=10;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=3210.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AO771");
	strcpy(empEsc.nombre,"Courtes Margerrison, Sky Ricki");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=3177.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QY702");
	strcpy(empEsc.nombre,"Unger Oxx, Valle Vidovik");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=3036.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EA213");
	strcpy(empEsc.nombre,"Sweeney Files, Wernher Brnaba");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=3632.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TL154");
	strcpy(empEsc.nombre,"Drewet Smythe, Royal Demetris");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=15;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=2218.22;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HW864");
	strcpy(empEsc.nombre,"Dearsley Acton, Brinn Dorree");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=2184.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QO928");
	strcpy(empEsc.nombre,"Pigden Durker, Pedro Dwayne");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=8;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=2792.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BJ060");
	strcpy(empEsc.nombre,"Gorke Scroxton, Imojean Joelie");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=3561.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SF265");
	strcpy(empEsc.nombre,"Christene Griffitts, Emmerich Farr");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=3539.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QD995");
	strcpy(empEsc.nombre,"Quarton Jervois, Byrle Thacher");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=3729.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VE640");
	strcpy(empEsc.nombre,"Jersh Jurasz, Demetre Godfrey");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=3150.46;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BJ108");
	strcpy(empEsc.nombre,"Langstone Toseland, Imogen Susannah");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=2875.27;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JC271");
	strcpy(empEsc.nombre,"Shermar Runnicles, Kinsley Cristobal");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=8;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=1361.44;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WY141");
	strcpy(empEsc.nombre,"Phillip Gall, Allie Roddie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=4085.51;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OI016");
	strcpy(empEsc.nombre,"Gosson Titterington, Gare Abramo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=1;
	empEsc.cantFamSeg=1;
	empEsc.salario=3049.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RC341");
	strcpy(empEsc.nombre,"Maffioni Feldmesser, Herold Tobiah");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=2537.89;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"II817");
	strcpy(empEsc.nombre,"Jiroudek Ailmer, Raddie Nicolais");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=1388.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WG502");
	strcpy(empEsc.nombre,"Gell Arendsen, Ilario Wright");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=3464.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DZ904");
	strcpy(empEsc.nombre,"Pencost Calvey, Kendrick Fin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=3698.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WK654");
	strcpy(empEsc.nombre,"Whybrow Tomowicz, Lazare Augusto");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=26;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=1186.56;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ES811");
	strcpy(empEsc.nombre,"Seabrocke Veillard, Tiff Kira");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=1;
	empEsc.cantFamSeg=6;
	empEsc.salario=3343.33;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OP562");
	strcpy(empEsc.nombre,"Trawin Gateland, Gusta Emmalyn");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=3654.94;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZI904");
	strcpy(empEsc.nombre,"MacCawley Wellington, Jammie Jannelle");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=3;
	empEsc.cantFamSeg=9;
	empEsc.salario=1476.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FZ274");
	strcpy(empEsc.nombre,"Frogley Galbreath, Lyn Inglebert");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=4040.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UY012");
	strcpy(empEsc.nombre,"Dalyiel Dahmel, Skipp Hamlin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=1355.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EG124");
	strcpy(empEsc.nombre,"Rose Fancet, Frazer Reid");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=3812.84;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WL859");
	strcpy(empEsc.nombre,"Piatti Gurton, Candida Melli");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=4411.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NU465");
	strcpy(empEsc.nombre,"Donizeau Borthe, Gaye Bobbee");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=18;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=1477.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GZ548");
	strcpy(empEsc.nombre,"Chomiszewski Roast, Bancroft Towny");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=6;
	empEsc.cantFamSeg=4;
	empEsc.salario=3410.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZC619");
	strcpy(empEsc.nombre,"Trytsman Glancy, Thorpe Armin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=3308.84;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DQ251");
	strcpy(empEsc.nombre,"Rosenberg Rodgers, Carr Delbert");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=24;
	empEsc.cargo=3;
	empEsc.cantFamSeg=6;
	empEsc.salario=3420.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DO514");
	strcpy(empEsc.nombre,"Gaither Parnby, Lillis Kassandra");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=7;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=1726.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ES882");
	strcpy(empEsc.nombre,"Golden Camps, Si Jonathon");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=29;
	empEsc.cargo=1;
	empEsc.cantFamSeg=9;
	empEsc.salario=3563.53;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JR045");
	strcpy(empEsc.nombre,"Ligertwood Seden, Tammi Ronica");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=8;
	empEsc.cantFamSeg=2;
	empEsc.salario=1081.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IX624");
	strcpy(empEsc.nombre,"Laherty Blackly, Jae Israel");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=9;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=1341.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VZ846");
	strcpy(empEsc.nombre,"Aynold Beau, Mark Garry");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=3;
	empEsc.cantFamSeg=8;
	empEsc.salario=3751.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XJ751");
	strcpy(empEsc.nombre,"Portingale Yanov, Sydney Siward");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=6;
	empEsc.cantFamSeg=5;
	empEsc.salario=1831.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RZ467");
	strcpy(empEsc.nombre,"Mattityahou Kissick, Hamel Oliviero");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=1722.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AA389");
	strcpy(empEsc.nombre,"Mahedy Ross, Llewellyn Forester");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=1042.41;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BJ895");
	strcpy(empEsc.nombre,"Hallgate Bordiss, Woodrow Germaine");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=3164.37;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"MB578");
	strcpy(empEsc.nombre,"Capini Last, Webb Devin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=1;
	empEsc.cantFamSeg=8;
	empEsc.salario=1677.57;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RU251");
	strcpy(empEsc.nombre,"Hayhurst Klimentov, Elvina Lora");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=3049.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CN663");
	strcpy(empEsc.nombre,"Binion Burchmore, Birk Dietrich");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=2;
	empEsc.cantFamSeg=3;
	empEsc.salario=1097.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KI296");
	strcpy(empEsc.nombre,"Edwick Keat, Ardella Blithe");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=2159.49;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FC293");
	strcpy(empEsc.nombre,"Diss Antoinet, Brendin Erny");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=23;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=1999.14;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NR180");
	strcpy(empEsc.nombre,"Staunton Errichelli, Warner Ber");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=8;
	empEsc.cantFamSeg=10;
	empEsc.salario=3004.4;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RQ791");
	strcpy(empEsc.nombre,"Featonby Feehan, Jacinta Anna-maria");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=1307.42;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CW435");
	strcpy(empEsc.nombre,"Weerdenburg Jellyman, Sherri Berny");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=2913.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QX057");
	strcpy(empEsc.nombre,"Pember Gumly, Zorah Eimile");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=2;
	empEsc.cantFamSeg=6;
	empEsc.salario=1593.58;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NC310");
	strcpy(empEsc.nombre,"Szwandt Wilman, Eva Rosmunda");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=1;
	empEsc.cantFamSeg=10;
	empEsc.salario=3820.19;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QX624");
	strcpy(empEsc.nombre,"Blinerman Conyers, Carling Pippo");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=14;
	empEsc.cargo=6;
	empEsc.cantFamSeg=1;
	empEsc.salario=4053.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LM915");
	strcpy(empEsc.nombre,"Probyn Tutill, Quincy Pennie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=5;
	empEsc.cantFamSeg=6;
	empEsc.salario=1371.27;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GM171");
	strcpy(empEsc.nombre,"Bedwell Bortolutti, Myca Chadd");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=1397.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AT766");
	strcpy(empEsc.nombre,"Irving Jacobowicz, Fiorenze Bellina");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=5;
	empEsc.cantFamSeg=9;
	empEsc.salario=2915.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ON026");
	strcpy(empEsc.nombre,"Claridge Ioannou, Dmitri Nealon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=2920.7;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QK785");
	strcpy(empEsc.nombre,"Habershon Ibanez, Lee Annecorinne");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=2412.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NS159");
	strcpy(empEsc.nombre,"Graalmans Geall, Ruthann Mirabel");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=17;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=2375.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QF914");
	strcpy(empEsc.nombre,"Reames Keasey, Wallie Goddart");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=2281.99;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OH174");
	strcpy(empEsc.nombre,"Benneton Gorhardt, Moses Tommy");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=29;
	empEsc.cargo=2;
	empEsc.cantFamSeg=10;
	empEsc.salario=3461.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TS772");
	strcpy(empEsc.nombre,"Urey De Stoop, Erin Constantin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=2218.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OU963");
	strcpy(empEsc.nombre,"Monksfield Lacroux, Marcel Ring");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=2;
	empEsc.cantFamSeg=7;
	empEsc.salario=4166.27;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZZ342");
	strcpy(empEsc.nombre,"Brokenshire Paxton, Abigael Keelia");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=16;
	empEsc.cargo=4;
	empEsc.cantFamSeg=5;
	empEsc.salario=1147.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XU617");
	strcpy(empEsc.nombre,"Fiddymont Figure, Grenville Frazer");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=3759.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TM539");
	strcpy(empEsc.nombre,"Bachs Cobbald, Nikaniki Judye");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=4410.84;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EZ412");
	strcpy(empEsc.nombre,"Duthy Melledy, Diarmid Sandro");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=3285.91;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CL525");
	strcpy(empEsc.nombre,"Slowly Paling, Burgess Findlay");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=5;
	empEsc.cantFamSeg=1;
	empEsc.salario=1449.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TA086");
	strcpy(empEsc.nombre,"Sprules Willishire, Dimitri Maxie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=3;
	empEsc.cantFamSeg=10;
	empEsc.salario=3914.45;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BA721");
	strcpy(empEsc.nombre,"Kemmons Boolsen, Chas Kingston");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=21;
	empEsc.cargo=1;
	empEsc.cantFamSeg=8;
	empEsc.salario=1573.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QY770");
	strcpy(empEsc.nombre,"Bartoli Bosnell, Jacquenetta Katee");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=6;
	empEsc.cantFamSeg=8;
	empEsc.salario=1241.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PA675");
	strcpy(empEsc.nombre,"Lewerenz Dolligon, Zollie Ody");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=10;
	empEsc.cargo=7;
	empEsc.cantFamSeg=10;
	empEsc.salario=3961.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NZ472");
	strcpy(empEsc.nombre,"Capewell Keep, Godfry Torrin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=22;
	empEsc.cargo=7;
	empEsc.cantFamSeg=5;
	empEsc.salario=4107.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZN091");
	strcpy(empEsc.nombre,"Scrivens Haet, Jasmina Clareta");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=5;
	empEsc.salario=4068.84;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PH616");
	strcpy(empEsc.nombre,"Showers Kobel, Avrom Fletcher");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=3980.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EI944");
	strcpy(empEsc.nombre,"Sheridan Shelliday, Rodolfo Davin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=1040.6;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DP919");
	strcpy(empEsc.nombre,"Surman-Wells Flaxman, Adolpho Vladimir");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=27;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=3741.35;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FU285");
	strcpy(empEsc.nombre,"Cayet Cockayne, Dominique Klaus");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=27;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=3993.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NW603");
	strcpy(empEsc.nombre,"Townend Retallack, Jeane Eydie");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=8;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=2187.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HV867");
	strcpy(empEsc.nombre,"Westover Hardern, Libbey Tanhya");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=1;
	empEsc.cantFamSeg=5;
	empEsc.salario=2149.38;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UG888");
	strcpy(empEsc.nombre,"Calles Snelling, Humfried Hayden");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=7;
	empEsc.cargo=1;
	empEsc.cantFamSeg=6;
	empEsc.salario=1026.76;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UR933");
	strcpy(empEsc.nombre,"Logesdale Mackiewicz, Dagny Erroll");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=2275.71;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UH396");
	strcpy(empEsc.nombre,"Dunguy Deaconson, Florencia Cammie");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=3941.21;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RS128");
	strcpy(empEsc.nombre,"Bool Langworthy, Brian Rand");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=4;
	empEsc.cantFamSeg=4;
	empEsc.salario=3689.34;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QL681");
	strcpy(empEsc.nombre,"Fountaine Jowle, Corby Fergus");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=2;
	empEsc.cantFamSeg=7;
	empEsc.salario=2829.58;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"PG046");
	strcpy(empEsc.nombre,"Ryrie Francisco, Kerby Finlay");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=4044.36;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RZ950");
	strcpy(empEsc.nombre,"Bronot Kempstone, Laughton Gino");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=6;
	empEsc.cantFamSeg=1;
	empEsc.salario=1796.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IO209");
	strcpy(empEsc.nombre,"Marciek Kaasman, Nils Gardener");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=1248.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LK715");
	strcpy(empEsc.nombre,"Portriss Burner, Domingo Kendal");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=2269.11;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XI304");
	strcpy(empEsc.nombre,"Earey Spearing, Noble Franklyn");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=2245.97;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EG032");
	strcpy(empEsc.nombre,"Orlton Butner, Alard Martyn");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=2365.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XK131");
	strcpy(empEsc.nombre,"Instone Hopfner, Peta Iormina");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=4462.68;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"JL145");
	strcpy(empEsc.nombre,"Croson Innocent, Ellwood Kingsley");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=1162.31;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XB339");
	strcpy(empEsc.nombre,"Fetterplace Belvard, Huntington Paxon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=3294.26;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"LH219");
	strcpy(empEsc.nombre,"Slimming OMeara, Kahlil Tiebout");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=3039.41;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WR289");
	strcpy(empEsc.nombre,"Spraberry Rubinovitsch, Allan Scot");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=1920.23;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AQ686");
	strcpy(empEsc.nombre,"Botfield Marshland, Giovanni Dallas");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=5;
	empEsc.cantFamSeg=3;
	empEsc.salario=1913.25;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HF652");
	strcpy(empEsc.nombre,"Pinchback Aim, Stephine Veda");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=1877.62;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BI673");
	strcpy(empEsc.nombre,"Shepheard Lawrey, Jessee Ganny");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=3;
	empEsc.cantFamSeg=1;
	empEsc.salario=2179.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UW583");
	strcpy(empEsc.nombre,"Kinchlea Edgehill, Goraud Clevie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=4;
	empEsc.cantFamSeg=3;
	empEsc.salario=1870.69;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OW269");
	strcpy(empEsc.nombre,"Stone Fewings Bowmaker, Antonina Therine");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=30;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=4148.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BR379");
	strcpy(empEsc.nombre,"Ziems Rentelll, Omar Merrick");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=4;
	empEsc.cantFamSeg=10;
	empEsc.salario=4101.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XK359");
	strcpy(empEsc.nombre,"Aylen Eads, Woodie Fritz");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=3;
	empEsc.cantFamSeg=4;
	empEsc.salario=2765.77;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KE804");
	strcpy(empEsc.nombre,"Castanares Hughesdon, Willey Marcel");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=1593.12;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QE288");
	strcpy(empEsc.nombre,"Grimes Hyde-Chambers, Iorgos Jereme");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=4032.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"NH225");
	strcpy(empEsc.nombre,"Scothron Boulder, Morgana Seana");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=3678.19;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FF354");
	strcpy(empEsc.nombre,"Ingray Canner, Maurie Luigi");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=26;
	empEsc.cargo=7;
	empEsc.cantFamSeg=8;
	empEsc.salario=3036.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"DC459");
	strcpy(empEsc.nombre,"Nestle Cinderey, Walsh Justino");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=8;
	empEsc.cargo=8;
	empEsc.cantFamSeg=6;
	empEsc.salario=1350.87;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HO777");
	strcpy(empEsc.nombre,"Shackel Oliff, Robinet Abra");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=5;
	empEsc.cantFamSeg=10;
	empEsc.salario=2432.3;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SB774");
	strcpy(empEsc.nombre,"Danjoie Cathersides, Koenraad Elton");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=13;
	empEsc.cargo=2;
	empEsc.cantFamSeg=5;
	empEsc.salario=3422.43;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZZ607");
	strcpy(empEsc.nombre,"Cottrell Longo, Alan Cullen");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=3612.92;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AF691");
	strcpy(empEsc.nombre,"Cauldwell Lanyon, Wiley Luther");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=3657.88;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EL552");
	strcpy(empEsc.nombre,"Dayce Esbrook, Pierre Gilles");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=26;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=1006.65;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UA767");
	strcpy(empEsc.nombre,"Stode Brabbs, Hagen Hurlee");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=14;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=1222.85;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EF935");
	strcpy(empEsc.nombre,"Skyppe Galliford, Jennine Cherianne");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=1794.17;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IT689");
	strcpy(empEsc.nombre,"Elen Tuffield, Raynor Dru");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=8;
	empEsc.cantFamSeg=8;
	empEsc.salario=3248.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"IG972");
	strcpy(empEsc.nombre,"Erskine Chetter, Brockie Galvin");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=3436.2;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BZ658");
	strcpy(empEsc.nombre,"Netherwood Gaitskell, Clare Stevy");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=15;
	empEsc.cargo=8;
	empEsc.cantFamSeg=7;
	empEsc.salario=3768.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UQ377");
	strcpy(empEsc.nombre,"Carress Kyles, Kin Maximo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=5;
	empEsc.cantFamSeg=8;
	empEsc.salario=2175.96;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SS745");
	strcpy(empEsc.nombre,"Nobriga Ornelas, Artur Gerick");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=9;
	empEsc.cargo=7;
	empEsc.cantFamSeg=4;
	empEsc.salario=1169.95;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KM442");
	strcpy(empEsc.nombre,"Harbin Tomblin, Theodoric Brucie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=2890.63;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ME662");
	strcpy(empEsc.nombre,"Dilnot Ort, Renard Ansell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=17;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=1086.9;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FJ514");
	strcpy(empEsc.nombre,"Witten Kirsz, Fair Isidor");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=5;
	empEsc.cargo=8;
	empEsc.cantFamSeg=3;
	empEsc.salario=1424.13;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"SY247");
	strcpy(empEsc.nombre,"Pierton Culy, Gannon Dolph");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=4;
	empEsc.cantFamSeg=1;
	empEsc.salario=2121.1;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BP625");
	strcpy(empEsc.nombre,"Greathead Barnsdale, Janith Beverly");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=28;
	empEsc.cargo=7;
	empEsc.cantFamSeg=2;
	empEsc.salario=1666.41;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VU287");
	strcpy(empEsc.nombre,"Woodrow Seiter, Gerrie Rodrigo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=7;
	empEsc.cantFamSeg=7;
	empEsc.salario=3108.58;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OE958");
	strcpy(empEsc.nombre,"Canto Mabbott, Paola Diana");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=29;
	empEsc.cargo=4;
	empEsc.cantFamSeg=3;
	empEsc.salario=3612.93;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"EL067");
	strcpy(empEsc.nombre,"Vail Hukins, Ganny Curtice");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=5;
	empEsc.cantFamSeg=4;
	empEsc.salario=4214.59;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"OW419");
	strcpy(empEsc.nombre,"Hairyes Ellerby, Maisie Josee");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=8;
	empEsc.cantFamSeg=1;
	empEsc.salario=1499.19;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BE083");
	strcpy(empEsc.nombre,"Croce Sloam, Harman Ethelred");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=20;
	empEsc.cargo=4;
	empEsc.cantFamSeg=6;
	empEsc.salario=1117.65;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZN756");
	strcpy(empEsc.nombre,"Semens Hover, Cristy Juliet");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=6;
	empEsc.cargo=1;
	empEsc.cantFamSeg=2;
	empEsc.salario=3146.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BZ568");
	strcpy(empEsc.nombre,"Davern Meneer, Marten Linoel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=1;
	empEsc.cantFamSeg=4;
	empEsc.salario=1962.53;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"TD651");
	strcpy(empEsc.nombre,"Meadley Courtier, Pia Brunhilde");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=28;
	empEsc.cargo=2;
	empEsc.cantFamSeg=1;
	empEsc.salario=3537.86;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"GY252");
	strcpy(empEsc.nombre,"Ketch Wane, Cale Deane");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=3;
	empEsc.cantFamSeg=3;
	empEsc.salario=3962.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"KM769");
	strcpy(empEsc.nombre,"Scraney Allery, Fayina Sissie");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=7;
	empEsc.cantFamSeg=1;
	empEsc.salario=3602.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZD853");
	strcpy(empEsc.nombre,"Sorby Wyborn, Roldan Win");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=12;
	empEsc.cargo=5;
	empEsc.cantFamSeg=5;
	empEsc.salario=1158.72;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"RL864");
	strcpy(empEsc.nombre,"Twamley Tailour, Forbes Farly");
	empEsc.sexo='M';
	empEsc.bilingue='S';
	empEsc.antiguedad=21;
	empEsc.cargo=7;
	empEsc.cantFamSeg=6;
	empEsc.salario=2260.91;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AK523");
	strcpy(empEsc.nombre,"Grummitt Russ, Chickie Husain");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=5;
	empEsc.cargo=1;
	empEsc.cantFamSeg=6;
	empEsc.salario=2854.82;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"BT801");
	strcpy(empEsc.nombre,"Brewitt Renzullo, Latia Edie");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=7;
	empEsc.cantFamSeg=9;
	empEsc.salario=2323.8;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"HL949");
	strcpy(empEsc.nombre,"Gossling Lindenfeld, Frasco Jamaal");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=18;
	empEsc.cargo=2;
	empEsc.cantFamSeg=2;
	empEsc.salario=2751.55;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"CR574");
	strcpy(empEsc.nombre,"Bennie Impy, Merrili Pam");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=4;
	empEsc.cantFamSeg=2;
	empEsc.salario=2580.57;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UY300");
	strcpy(empEsc.nombre,"Bailiss Gramer, Haroun Shem");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=11;
	empEsc.cargo=6;
	empEsc.cantFamSeg=2;
	empEsc.salario=3128.73;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AC379");
	strcpy(empEsc.nombre,"Rumford Howatt, Bank Cosmo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=25;
	empEsc.cargo=6;
	empEsc.cantFamSeg=6;
	empEsc.salario=3574.28;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WX988");
	strcpy(empEsc.nombre,"Heathcott Reace, Meg Rene");
	empEsc.sexo='F';
	empEsc.bilingue='N';
	empEsc.antiguedad=23;
	empEsc.cargo=4;
	empEsc.cantFamSeg=9;
	empEsc.salario=2579.78;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VO378");
	strcpy(empEsc.nombre,"Sandercock McArthur, Valentijn Brockie");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=14;
	empEsc.cargo=8;
	empEsc.cantFamSeg=4;
	empEsc.salario=3560.24;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"AS567");
	strcpy(empEsc.nombre,"Minot Marshman, Forester Hershel");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=29;
	empEsc.cargo=6;
	empEsc.cantFamSeg=7;
	empEsc.salario=3200.75;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"VW348");
	strcpy(empEsc.nombre,"Sopp Argont, Burnard Lammond");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=26;
	empEsc.cargo=5;
	empEsc.cantFamSeg=7;
	empEsc.salario=1064.44;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ON614");
	strcpy(empEsc.nombre,"Chamberlaine MacNab, Cesar Silvain");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=9;
	empEsc.cargo=6;
	empEsc.cantFamSeg=9;
	empEsc.salario=2998.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"QX065");
	strcpy(empEsc.nombre,"Luckey Felce, Thorpe Ramon");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=16;
	empEsc.cargo=3;
	empEsc.cantFamSeg=7;
	empEsc.salario=2842.83;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"FA556");
	strcpy(empEsc.nombre,"Stennine Pendock, Shayne Mark");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=12;
	empEsc.cargo=1;
	empEsc.cantFamSeg=7;
	empEsc.salario=2307.64;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"UT965");
	strcpy(empEsc.nombre,"Peascod Driffe, Urbanus Bartolemo");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=27;
	empEsc.cargo=4;
	empEsc.cantFamSeg=8;
	empEsc.salario=1243.38;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"XI064");
	strcpy(empEsc.nombre,"O Dooley Cowerd, Nappy Ivan");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=19;
	empEsc.cargo=3;
	empEsc.cantFamSeg=2;
	empEsc.salario=1010.48;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"WJ554");
	strcpy(empEsc.nombre,"Brumham Ricco, Elroy Parnell");
	empEsc.sexo='M';
	empEsc.bilingue='N';
	empEsc.antiguedad=24;
	empEsc.cargo=2;
	empEsc.cantFamSeg=4;
	empEsc.salario=2270.79;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================
	strcpy(empEsc.id,"ZT400");
	strcpy(empEsc.nombre,"Purton Ditty, Leonanie Barbe");
	empEsc.sexo='F';
	empEsc.bilingue='S';
	empEsc.antiguedad=7;
	empEsc.cargo=8;
	empEsc.cantFamSeg=9;
	empEsc.salario=2170.11;
	fwrite(&empEsc, sizeof(struct Empleado), 1, archivo);
	//=================================================================

    //=================================================================================
    fclose(archivo);
    printf("\tArchivo de Pruebas Pre-definido Creado Exitosamente.\n");
    Sleep(2500); system("cls");
  };  