#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

int main()
{

    int opp;

    do {
        system("cls");
        printf("*******************************\n");
        printf("* GUIA DE PROBLEMAS N2 FABIAN *\n");
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
        printf(" 9.- Ejercicio9               *\n");
        printf(" 10.- Ejercicio10             *\n");
        printf(" 11.- Ejercicio11             *\n");
        printf(" 12.- Ejercicio12             *\n");
        printf(" 13.- Ejercicio13             *\n");
        printf(" 14.- Ejercicio14             *\n");
        printf(" 15.- Salir                   *\n");
        printf("*******************************\n");
        printf(" OPCION: ");
        scanf("%d",&opp);

        switch(opp)
        {
        case 1:
        {
            system("cls");
            printf("Unidades Decenas y Centenas\n");
            int num,n1,n2,n3;
            printf("Ingrese un numero de 3 cifras: ");scanf("%d",&num);
            n1=num/100;
            n2=num%100;
            n3=num%10;
            printf("\nEl numero tiene %d centenas, %d decenas con %d unidades\n\n",n1,n2=n2-n3,n3);
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            printf("Numero mas Grande y Peque;o\n");
            int num,n1,n2,n3;
            printf("Ingrese un numero de 3 cifras: ");
            scanf("%d",&num);
            n1=num/100;n2=(num%100)/10;n3=num%10;
            
           printf("Combinacion mas Grande: ");
            if (n1 >= n2 && n1 >= n3) {
                if (n2 >= n3) printf("%d%d%d\n", n1, n2, n3);
                else printf("%d%d%d\n", n1, n3, n2);
            } else if (n2 >= n1 && n2 >= n3) {
                if (n1 >= n3) printf("%d%d%d\n", n2, n1, n3);
                else printf("%d%d%d\n", n2, n3, n1);
            } else {
                if (n1 >= n2) printf("%d%d%d\n", n3, n1, n2);
                else printf("%d%d%d\n", n3, n2, n1);
            }
             
           printf("Combinacion mas Peque;a: ");
            if (n1 <= n2 && n1 <= n3) {
                if (n2 <= n3) printf("%d%d%d\n", n1, n2, n3);
                    else printf("%d%d%d\n", n1, n3, n2);
            } else if (n2 <= n1 && n2 <= n3) {
                if (n1 <= n3) printf("%d%d%d\n", n2, n1, n3);
                else printf("%d%d%d\n", n2, n3, n1);
            } else {
                if (n1 <= n2) printf("%d%d%d\n", n3, n1, n2);
                else printf("%d%d%d\n", n3, n2, n1);
            }


             system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            printf("Diferencia Numeros naturales\n");
            int dif,na,nb;
            printf("Ingrse dos numeros naturales: ");
            scanf("%d %d",&na,&nb);
            if (na>nb)
                dif=na-nb;
            else
                dif=nb-na;
            printf("\nLa diferencia es de %d\n",dif);
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            printf("Cuatrantes Plano cartesianos\n");
            int x,y;
            printf("Ingrese los valores X y Y (separadamente): ");
            scanf("%d %d",&x,&y);
            if ((x>0)&&(y>0))
                printf("Esta en el cuadrante I(ambos son positivos)\n");
            else if ((x<0)&&(y>0))
                printf("Esta en el cuadrante II(x es negativo y y positivo)\n");
            else if ((x<0)&&(y<0))
                printf("Esta en el cuadrante III(Ambos son negativo)\n");
            else if ((x>0)&&(y<0))
                printf("Esta en el cuadrante IIII(x es positivo y y negativo)\n");
            else printf("No esta en ningun cuadrante\n");

            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            printf("Distancia de el vector plano cartesiano\n");
            int x,y;
            float dis;
            printf("Ingrese los valores X y Y (separadamente): ");
            scanf("%d %d",&x,&y);
            printf("\nEl modulo del vector es %.2f\n",dis=sqrt(x*x+y*y));
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            printf("Ecuacion Canonica\n");
            int b,m,y,x;
            printf("Ingrese el valor de la pendiente de la recta de el plano cartesiano: ");
            scanf("%d",&m);
            printf("Ingrese los Un punto de la recta (ya sea x o y): ");
            scanf("%d",&x);
            y=sqrt(m*m-x*x);
            b=m*x-y;
            printf("La ecuacion Canonica es: Y= %dX + %d\n",x,b);

            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            printf("Ecuacion cuadratica\n");
            int a,b,c; float cu,res,res2;
            printf("Ingrese los valores de\na: "); scanf("%d",&a);
            printf("b: ");scanf("%d",&b);
            printf("c: ");scanf("%d",&c);
    
            cu=(b*b)-(4*a*c); printf("\n%d\n",cu);

            if (cu>0)
            {
                res=((-1*b)+sqrt(cu))/(2*a);
                res2=((-1*b)-sqrt(cu))/(2*a);
                printf("Hay 2 posibles soluciones, estas son %.2f y %.2f\n",res,res2);
            }
            else if (cu==0)
            {
                res=(-b+cu)/(2*a);
                printf("Hay una solucion, esta es %.2f\n",res);
            }
            else if(cu<0) printf("No hay soluciones\n");

            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            printf("Diferencia Numeros naturales(Sin -)\n");
            int dif,na,nb;
            printf("Ingrse dos numeros naturales: ");
            scanf("%d %d",&na,&nb);
            if (na>nb)
                dif= ~na+1+nb;
            else
                dif= ~nb+1+na;
            printf("\nLa diferencia es de %d\n",dif*-1);

            system("pause");
            break;
        }
        case 9:
        {
            system("cls");
            printf("Todos los divisores\n");
            int x,i;
            printf("Ingrese num: ");
            scanf("%d",&x);
            printf("\nLos divisores de %d son: ",x);
            for(i=1; i<=x; i++)
                if(x%i==0) printf(" %3d ",i);

            printf("\n\n");
            system("pause");
            break;
        }
        case 10:
        {
            system("cls");
            printf("PAR o IMPAR\n");
            int num;
            printf("Ingrese un numero: ");
            scanf("%d",&num);
            if (num%2==0) printf("Su numero es par\n\n");
            else printf("Su numero es impar\n\n");

            system("pause");
            break;
        }
        case 11:
        {
            system("cls");
            printf("Numero capicuo\n");
            int num,no=0,ni=0,re=0;
            printf("Ingrese un numero: ");
            scanf("%d",&num);
            no=num;

            while(num>0)
            {
                re=num%10;
                ni=ni*10+re;
                num=num/10;
            }
            if (ni==no) printf("\nEl numero es capicuo\n");
            else printf("\nEl numero no es capicuo\n");

            system("pause");
            break;
        }
        case 12:
        {
            system("cls");
            printf("SIN PARES\n");
            int n, digito, nuevo = 0, pos = 1;
            printf("Ingrese un numero: ");
            scanf("%d", &n);

            while (n > 0) {
                digito = n % 10;
                if (digito % 2 != 0) {
                    nuevo = nuevo + (digito * pos);
                    pos = pos * 10;
                }
                n = n / 10;
            }
            printf("Resultado: %d\n", nuevo);
            system("pause");
            break;
        }
        case 13:
        {
            system("cls");
            printf("Entero en numeros primos\n");
            int n, divisor = 2,contador = 0;
            printf("Ingrese N: ");
            scanf("%d", &n);

            printf("%d = ", n);
            while (n > 1) {
                while (n % divisor == 0) {
                    contador++;
                    n = n / divisor;
                }
                if (contador > 0) {
                    printf("%d^%d", divisor, contador);
                    if (n > 1) printf(" x ");
                }
                divisor++;
            }

            printf("\n\n");
            system("pause");
            break;
        }
        case 14:
        {
            system("cls");
            printf("NUMERO A BINARIO\n");
            int n, bin=0, pos=1, aux,res;

            printf("Ingrese un numero (0...512): ");
            scanf("%d", &n);

            if (n>=0 && n<=512) { 
                aux = n;

                for (int i=0; i<10; i++) {
                    if (aux > 0) {
                        res = aux % 2;
                        bin = bin + (res * pos);
                        aux = aux / 2;
                        pos = pos * 10;
                    }
                }
                printf("el numero %d en sistema binario es: %d\n", n, bin);
            } else 	printf("ERROR.\n");

            system("pause");
            break;
        }
        case 15:
        {
            system("cls");
            printf("\nbabai");
            break;
        }
        }


    } while (opp!=15);

    Sleep(1000);


    return 0;
}