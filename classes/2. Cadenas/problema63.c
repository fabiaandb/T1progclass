#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int main()
{   
 char cad1[50],inv[50];
 int pos,i,cont;
 
  printf("INGRESE CADENA: ");
  scanf("%99[^\n]",cad1);
  
  //LLEVAMOS LA CADENA A MAYUSCULA
  for(i=0;i<strlen(cad1);i++)
     cad1[i]=tolower(cad1[i]);
  
  // inversa  
   pos=strlen(cad1)-1;
   for(i=0;i<strlen(cad1);i++)
   {
   	  inv[pos]=cad1[i];   	  
   	  pos--;
   } 
   printf("INVERSA >> %s\n\n",inv);
   
   //PALINDROME
   if(strcmp(cad1,inv)==0)
     printf("%s es PALINDROME\n",cad1);
   else
    printf("%s NO es PALINDROME\n",cad1);
   
   // cuantas palabras tiene la frase
   cont=0;
   for(i=0;i<strlen(cad1);i++)
     if(cad1[i]==' ')cont++;
   printf("Cant. Palabras: %d\n",(cont+1));   
   
   /*
      A) SU INVERSA.  // CASA >> ASAC
      B) DETERMINE SI ES PALINDROME.
      C) CUANTAS PALABRAS TIENE
   */
 return 0;
}
