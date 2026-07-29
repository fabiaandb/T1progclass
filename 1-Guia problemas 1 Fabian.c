#include<stdio.h> //si
#include<conio.h> //si?
#include<stdlib.h> //talvez
#include<time.h> //puede?
#include<windows.h> //bonito?
#include <math.h>

//hecho por Fadb
int main()
{
	int op,opp; char oplo;
	do{
	system("cls");
  	printf("*******************************\n");
  	printf("* GUIA DE PROBLEMAS N1 FABIAN *\n");
  	printf("*******************************\n");
  	printf(" ENTRADA Y SALIDA             *\n");
  	printf(" 1.- Ejercicio1               *\n");
  	printf(" 2.- Ejercicio2               *\n");
  	printf(" 3.- Ejercicio3               *\n");
  	printf(" 4.- Ejercicio4               *\n");
  	printf(" 5.- Ejercicio5               *\n");
  	printf(" 6.- Ejercicio6               *\n");
  	printf(" 7.- Ejercicio7               *\n");
  	printf(" 8.- Ejercicio8               *\n");
  	printf("*******************************\n");
  	printf(" CONDICIONALES                *\n");
  	printf(" 9.- Ejercicio1               *\n");
  	printf(" 10.- Ejercicio2              *\n");
  	printf(" 11.- Ejercicio3              *\n");
  	printf(" 12.- Ejercicio4              *\n");
  	printf(" 13.- Ejercicio5              *\n");
  	printf(" 14.- Ejercicio6              *\n");
  	printf(" 15.- Ejercicio7              *\n");
  	printf(" 16.- Ejercicio8              *\n");
  	printf(" 17.- Salir                   *\n");
 	printf("*******************************\n");
  	printf(" OPCION: "); scanf("%d",&opp);
  	//67 para funcion oculta (calculadora)
    
	int op;	
	switch(opp)	
	{
		 case 1:
			{
				do{
	
  system("cls");
  printf("*******************************\n");
  printf("*     TERRENOS ACUATICOS      *\n");
  printf("*******************************\n");
  printf(" 1.- Triangulo                *\n");
  printf(" 2.- Cuadrado                 *\n");
  printf(" 3.- Rombo                    *\n");
  printf(" 4.- Rectangulo               *\n");
  printf(" 5.- Romboide                 *\n");
  printf(" 6.- Poligono regular         *\n");
  printf(" 7.- Circunferencia           *\n");
  printf(" 8.- Circulo                  *\n");
  printf(" 9.- Salir                    *\n");
  printf("*******************************\n");
  printf(" OPCION: "); scanf("%d",&op);
  
  system("cls");
  
  int B,H,metros,D,d,P,a,r;float A,L,money;
  switch(op) {
  	case 1:
  		printf("1. TRIANGULO\n\n");
		printf("Diga cuanto Terreno quiere comprar (ingrese ancho y largo separadamente): "); scanf("%d %d",&B,&H); A=(B*H)/2;
		printf ("\nEl area total es de %.2f y serian %.2f dls (valuado en 35dlsXm2)",A,money=A*35); printf("\n\n");system("pause");
		break;
	case 2:
		printf("2. CUADRADO\n\n");
		printf("cuantos metros cuadrados quiere comprar: ");scanf("%f",&A); A=A*A;
		printf ("\nEl area total es de %.2f y serian %.2f dls (valuado en 35dlsXm2)",A,money=A*35); printf("\n\n");system("pause");
		break;
	case 3:
		printf("3. ROMBO\n\n");
		printf(" introduzca el tamano de la superficie del Diagonal mayor y el menor (separados)");scanf("%d %d",&D,&d);A=D*d/2;
		printf("El area del terreno es %.2fmtrs2 y sale en %.2fdls",A,money=A*35); printf("\n\n");system("pause");
		break;
  	case 4:
  		printf("4. RECTANGULO\n\n");
  		printf("Diga cuanto Terreno quiere comprar (ingrese ancho y largo separadamente):  "); scanf("%d %d",&B,&H);A=B*H;
		printf ("\nEl area total es de %.2f y serian %.2f dls (valuado en 35dlsXm2)",A,money=A*35); printf("\n\n");system("pause");
		break;
	case 5:
		printf("5. ROMBOIDE\n\n");
		printf("Diga cuanto Terreno quiere comprar (ingrese ancho y largo separadamente):  "); scanf("%d %d",&B,&H);A=B*H;
		printf ("\nEl area total es de %.2f y serian %.2f dls (valuado en 35dlsXm2)",A,money=A*35); printf("\n\n");system("pause");
		break;
	case 6:
		printf("6. POLIGONO REGULAR\n\n");
		printf(" Ingrese el Perimetro y Apotema que desea comprar (separados):  ");scanf("%d %d",&P,&a);A=(P*a)/2;
		printf ("\nEl area total es de %.2f y serian %.2f dls (valuado en 35dlsXm2)",A,money=A*35); printf("\n\n");system("pause");	
		break;
	case 7:
		printf("7. CIRCUNFERENCIA\n\n");
		printf("Ingrese el radio de la circunferencia:  ");scanf("%d",&r); L=2*3.14*r;
		printf ("\nEl radio total es de %.2f y serian %.2f dls (valuado en 35dlsXm2)",L,money=L*35); printf("\n\n");system("pause");
		break;
	case 8:
		printf("8. CIRCULO\n\n");
		printf("Ingrese el radio de la circunferencia:  ");scanf("%d",&r); A=3.14*(r*r);
		printf ("\nEl radio total es de %.2f y serian %.2f dls (valuado en 35dlsXm2)",A,money=A*35); printf("\n\n");system("pause");
		break;
	case 9:
		printf("babai\n\n");
		
		
		break;		
	default:
		printf("no si talvez quien sabe yo no");		
  }     	 	
       
   }while(op!=9);
   
  		
		 break;	}
		
		 case 2:{
		 	system("cls");
		 	printf("FACTURA RESTORANTE GIOVANNI GIORGIO\n");
		 	float mn, iva=0.13;
				int mp;
				printf("Ingrese el monto de pago (IVA de 13%): ");
				scanf("%d",&mp);
				mn= mp*iva +mp;
				printf("\nFACTURA\n1.Precio: %3d\n2.IVA: %3.2f \n3.Pago total: %3.2f\n\n",mp,iva=iva*mp,mn);
			system("pause");
		 	
			break;
		 }
				
				
		 case 3:{
		 	    system("cls");
		 		int sol,num,pn, numc;
		 		printf("POTENCIACION\n");
				printf ("intro num: ");scanf("%d",&num);
				printf("\nintro tipo de potencia (2 u 3): "); scanf("%d",&pn);
	
				if (pn==2) sol=num*num; 
				else sol=num*num*num;

				printf("\nel resultado es: %d\n\n",sol);
				system("pause");
		 	
			break;
		 }
				
		 case 4:{
		 	    system("cls");
		 	    printf("VALOR DE LA HIPOTENUSA\n");
		 		int a,b;
				float c;
				printf("Para calcular la hipotenusa ingrese el primer y segundo num (separados): "); scanf("%d %d",&a,&b);c=sqrt((a*a)+(b*b));
				printf("\nLa hipotenusa es: %.2f\n\n",c);
		 		system("pause");
			break;
		 }
				
		case 5:{
			system("cls");
			int nf,n,s1,s2;
			printf("DOS DIGITOS\n");
			printf("ingrese un numero de 2 digitos: ");scanf("%d",&n); s1=n/10;s2=n%10; nf=s1+s2;
			printf("la suma de los dos digitos es %d\n\n",nf);
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			printf("Unidades Decenas y Centenas\n");
			int num,n1,n2,n3;
			printf("Ingrese un numero de 3 cifras: "); scanf("%d",&num); n1=num/100;n2=num%100;n3=num%10;
			printf("\nEl numero tiene %d centenas, %d decenas con %d unidades\n\n",n1,n2=n2-n3,n3);
			system("pause");
			break;	
			}
		case 7:
		{
			system("cls");
			printf("HORA MERIDIANA\n");
			int hour,minu;
			char forma;
			printf("Introduzca la hora separada por espacio (luego ponga si es a/p u m para formato 24hrs): ");scanf("%d %d %c",&hour,&minu,&forma);
			
			switch (forma)	{
				case 'a':
					printf("\nLa hora en formato militar es %d %d\n\n",hour,minu);	
				break;
				
				case 'A':
					printf("\nLa hora en formato militar es %d %d\n\n",hour,minu);
				break;
					
				case 'p': 
					printf("\nLa hora en formato militar es %d %d\n\n",hour=hour+12,minu);
				break;
				
				case 'P': 
					printf("\nLa hora en formato militar es %d %d\n\n",hour=hour+12,minu);
				break;
			
				case 'm':
					if (hour<12) 
						printf("\nLa hora en formato meridiano es %d %dam\n\n",hour,minu);
					else
						printf("\nLa hora en formato meridiano es %d %dpm\n\n",hour=hour-12,minu);	
				break;	
				default:
					printf("formato no aceptado");
					break;
			}
			printf("\n\n");system("pause");
			break;		
		}
		case 8:
			{
				system("cls");
				printf("TRANSFORMACION DE HORAS A MINUTOS\n");
			int minr,h,min;
				printf("ingrese la hora y los min (separados): ");scanf("%d %d",&h,&min);
				if (min!=0)
				minr=(60*h)+min;
				else
				minr=60*h;
				printf("\n%dh y %dmin son %d minutos",h,min,minr);
				printf("\n\n");system("pause");
			break;	
			}
		case 9:
		{
			system("cls");
			printf("NUMERO DE LA SEMANA\n"); int day;
			printf("Indique que numero de la semana es (en numero): "); scanf("%d",&day);
			switch (day)
			{
			case 1: 
				printf("\nhoy es Domingo\n\n");
				break;
				
			case 2: 
			printf("\nHoy es Lunes\n\n");
				break;
			case 3: 
			printf("\nHoy es Martes\n\n");
			 break;
			case 4: 
			printf("\nHoy es Miercoles\n\n");
			break;
			case 5:
			 printf("\nHoy es Jueves\n\n");
			  break;
			case 6: 
			printf("\nHoy es Viernes\n\n"); 
			break;
			case 7: 
			printf("\nHoy es Sabado\n\n");
			break;
			}
			system("pause");
			break;
			}		
			
		case 10:
			{
				system("cls");
				printf("NUMERO NEGATIVO Y POSITIVO\n"); int num;
				printf("Ingrese un numero: "); scanf("%d",&num); 
				if (num<0)
					printf("\nEl numero es Negativo\n\n");
				if(num==0)
					printf("\nEl numero es nulo\n\n");
				else
					printf("\nEl numero es positivo\n\n");
				
				system("pause");
				break;
			}
		case 11:
		{
			system("cls");
			printf("NUMERO MAYOR y MENOR\n"); int num1,num2;
			printf("Ingrese 2 numeros: "); scanf("%d %d", &num1,&num2);
			if (num1>num2)
			printf("\nEl numero mayor es %d",num1);
			else
			printf("\nEl numero mayor es %d",num2);
			printf("\n\n");system("pause");
			break;
			
			}
		case 12:
		{
			system("cls");
			printf("NUMERO PAR\n");int num;
			printf("Ingrese un numero: "); scanf("%d",&num);
			if ((num%2==0) && (num!=0))
				printf("\nel numero es par");
			else
			if ((num%2!=0)&&(num!=0))
				printf("\nEl numero es impar");
			else
				printf("\nEl numero es nulo");	
			printf("\n\n");system("pause");
			break;
			
			
			}	
		case 13:
		{
			system("cls"); //arreglar
			printf ("NUMEROS CRECIENTES\n");int x,y,z;
			printf("Ingrese 3 numeros (separados): "); scanf("%d %d %d",&x,&y,&z);
			
			if ((x>y) && (y>z)) //xyz
				printf("%d %d %d",z,y,x);
			if ((y>z) && (z>x)) //yzx
				printf("%d %d %d",x,z,y);
			if ((z>x) && (x>y)) //zxy
				printf("%d %d %d",y,x,z);
				
			printf("\n\n");system("pause");
			
			
			break;
			}		
		case 14:
		{
		system("cls");
		printf("SUELDO MENSUAL\n\n");
		int hijos; float ge,pr,sueldo; char genre, pro;
		
		printf("Ingrese su genero(m si es mujer, h si es hombre): "); 
		scanf("%s",&genre);
		if (genre=='m') 
			ge=100*0.20; 
		else 
			ge=100*0.40;
		
		printf("\nIngrese cuantos hijos tiene: ");
		scanf("%d",&hijos); 
		hijos=(hijos*0.05)*100;
		
		printf("\nEs un trabajador profesional?(y/n): "); 
		scanf("%s",&pro);  
		if (pro=='y') 
		pr=100*0.40;
		else
		pr=0;
		
		sueldo=ge+hijos+pr+100;
		
		printf("\n\nEl monto total del sueldo es: %.2f",sueldo);
		
		printf("\n\n");system("pause");
		break;
		}
		
		case 15:
		{
		system("cls");
		printf("MENOR DESCOMPOSICION DE 2 NUMEROS\n");
		
		int nf,s1,s2,n;
		printf("ingrese un numero de 2 digitos: ");scanf("%d",&n); s1=n/10;s2=n%10;
		
		if (s1<s2)
			printf("\nLa descomposicion mas peque;a es: %d%d",s1,s2);
		else
			printf("\nLa descomposicion mas peque;a es: %d%d",s2,s1);
			printf("\n\n");system("pause");
			break;	
		}
		
		case 16:
		{
			
		do{
			system("cls");
  			printf("*******************************\n");
  			printf("*     METODO DE PAGO          *\n");
  			printf("*******************************\n");
 			printf(" 1.- Devito                   *\n");
		  	printf(" 2.- Efectivo                 *\n");
		  	printf(" 3.- TDC                      *\n");
  			printf(" 4.- Cripto                   *\n");
  			printf(" 5.- Salir                    *\n");
  			printf("*******************************\n");
  			printf(" OPCION: "); scanf("%d",&op);
  
 	 		system("cls");
  
  
  			switch(op) {
  			case 1:{
  								float mn, iva=0.13;
  					printf("DEVITO\n\n");
  					printf("FACTURA RESTORANTE GIOVANNI GIORGIO\n");
	
					int mp;
					printf("Ingrese el monto de pago (IVA de 13%): ");
					scanf("%d",&mp);
					mn= mp*iva +mp;
					printf("\nFACTURA\n1.Precio: %d\n2.IVA: %.2f \n3.Pago total: %.2f",mp,iva=iva*mp,mn);
					printf("\n\n");system("pause");
					break;
				  }
				case 2:{
								float mn, iva=0.10;
  					printf("EFECTIVO\n\n");
  					printf("FACTURA RESTORANTE GIOVANNI GIORGIO\n");
	
					int mp;
					printf("Ingrese el monto de pago (IVA de 10%): ");
					scanf("%d",&mp);
					mn= mp*iva +mp;
					printf("\nFACTURA\n1.Precio: %d\n2.IVA: %.2f \n3.Pago total: %.2f",mp,iva=iva*mp,mn);
					printf("\n\n");system("pause");
					break;
				  }
				case 3:{
								float mn, iva=0.21;
  					printf("TDC\n\n");
  					printf("FACTURA RESTORANTE GIOVANNI GIORGIO");
	
					int mp;
					printf("Ingrese el monto de pago (IVA de 21%): ");scanf("%d",&mp);
					mn= mp*iva +mp;
					printf("\nFACTURA\n1.Precio: %d\n2.IVA: %.2f \n3.Pago total: %.2f",mp,iva=iva*mp,mn);
					printf("\n\n");system("pause");
					break;
				  }
				case 4:{
								float mn, iva=0.03;
  					printf("CRIPTO MONEDA\n\n");
  					printf("FACTURA RESTORANTE GIOVANNI GIORGIO\n");
	
					int mp;
					printf("Ingrese el monto de pago (IVA de 3%): ");
					scanf("%d",&mp);
					mn= mp*iva +mp;
					printf("\nFACTURA\n1.Precio: %d\n2.IVA: %.2f \n3.Pago total: %.2f",mp,iva=iva*mp,mn);
					printf("\n\n");system("pause");
					break;
				  }
				  case 5:{
				  	printf("babai\n\n");
					break;}		
					default:
					printf("no si talvez quien sabe yo no");
			}
			
		}while(op!=5);
		
			break;}	
		case 67:
		{
	
			int num1,num2,result;
			do{
				system("cls");printf("CALCULADORA\n\n");
				printf("introduzca 2 numeros(incluya + - * /)\n");
			scanf("%d %c %d",&num1,&oplo,&num2); 
		
			switch (oplo) {
    			case '+':
        				result = num1 + num2; 
        				printf("El resultado es: %d\n", result);
        			break;
    			case '-':
       				 result = num1 - num2;
       				 printf("El resultado es: %d\n", result);
        		break;
   				 case '*':
        			result = num1 * num2;
        			printf("El resultado es: %d\n", result);
       			 break;
    			case '/':
       				 if (num2 != 0) {
           			 result = num1 / num2;
           			 printf("El resultado es: %d\n", result);
       				 } else {
           			 printf("No es posible esta operacion\n");
       				 }
       			 break;

   				 default:
       			 printf("Operador no reconocido\n");
		}
			printf("\n\nescriba 67 para salir, escriba cualquier otro para regresar: ");scanf("%d",&op);
				
			}while (op!=67);
			
		}
		
		case 17:{
				printf("babai\n\n");
				break;
			}
			
	}
	
	}while (opp!=17);
	
	
   
	Sleep(2000);
	return 0;
}