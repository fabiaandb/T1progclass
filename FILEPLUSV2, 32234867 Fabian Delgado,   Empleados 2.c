#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#define LIM 190
struct Empleado 
{
    char id[8];							//  8 BYTES
    char nombre[50];					// 50 BYTES
    char sexo,bilingue;					//  1 BYTES
    int antiguedad,cargo,cantFamSeg;	// 12 BYTES
    float salario;						//  8 BYTES
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
  crearArchivoPruebas();
  mostrarArchivo();
  //mostrarMujeresBilingue();    
  return 0;
}
//=============================================================================  
 
//=============================================================================  
  void mostrarArchivo()
  {
  	FILE *archivo;
    struct Empleado empLeer;
    int opp, num;
    char idleido[6];
    
      
    if (archivo == NULL) 
	   {
        printf("\n\n ==========================================\n");
	    printf("   ERROR AL TRATAR DE ABRIR EL ARCHIVO...  \n");
	    printf(" ==========================================\n");
	    Sleep(2500); system("cls"); return;
       }
    else
       {    
       	do{
		archivo = fopen("empleadosv2.dat", "rb"); 
       	system("cls");
	    printf("\v\t==================================================\n");
	    printf("\tI     SUELDOS DE LOS EMPLEADOS REGISTRADOS       I\n");
	    printf("\tI                FABIAN DELGADO                  I\n");
	    printf("\t==================================================\n");
	    printf("\tI 1- Consultar plantel de empleados              I\n");
	    printf("\tI 2- Buscar por codigo                           I\n");
	    printf("\tI 3- Salir                                       I\n\t");
	    scanf("%d",&opp);
	    system("cls");
	    if(opp==1)
		{
		    num=1;
			do {
				 printf("\t%5d) %8s %25s \n",(num++),empLeer.id,empLeer.nombre);	
			 } while (fread(&empLeer, sizeof(struct Empleado), 1, archivo) == 1);
		 	getch();
		 	num=1;
		}
		if(opp==2)
		{
			num=1;
		 int cbil=0, ccar=200, cseg=150,cant; float sueldofin, sueldo, csex; 
	    printf("\tI * INTRODUZCA UN CODIGO DE EMPLEADO [5c]: "); scanf("%s",idleido);
		
		system("cls");
		
	    do 
		 {
			if(stricmp(idleido,empLeer.id)== 0)
			{
			sueldo=empLeer.salario;
			if(empLeer.sexo=='M') csex=sueldo*0.18; else csex=sueldo*0.25;
			if(empLeer.bilingue='S') cbil=1000;
			cseg= cseg*empLeer.cantFamSeg;	
			ccar=ccar*empLeer.cargo;
			cant=((empLeer.antiguedad/3)*0.05)*sueldo;
			sueldofin=sueldo+csex+cbil+ccar+cant-cseg;
		  	printf("\v\v\t\aEMPLEADO=%s\n\tAPELLIDO,NOMBRE= %25s\n",empLeer.id,empLeer.nombre); Sleep(300);
			printf("\v\tBono de Sexo= %f\n\tBono de Bilingues= %d\n\tBono de antiguedad= %d\n\tBono de cargo= %d\n\tReduccion por seguro= %d\n\tSUELDOFINAL= %.2f dls",
			csex,cbil,cant,ccar,cseg,sueldofin);	
			}
		  num++;
	     } while (fread(&empLeer, sizeof(struct Empleado), 1, archivo)==1);
		 	    printf("\n\n-------------------------------------------------\n");
	    printf(" Pulse una tecla para continuar...                \n"); getch();
	    num=1;
	}
	}while(opp!=3);
	

       }
       	    fclose(archivo);
  };  
  //=============================================================================  
  void crearArchivo()
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
    //=================================================================================
    fclose(archivo); system("cls");
  };  