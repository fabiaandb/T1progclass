#include<stdio.h>
#include<conio.h>
int main()
{
  int X;  
  // C=C+1 <=> c++  <=>  C+=1   
  // C=C-1 <=> c--  <=>  C-=1   
  for(X=1;X<=5;X++)
     printf("%5d %5d %5d\n",X,X*X,X*X*X);    
  printf("-----------------------\n");     
  for(X=5;X>0;X--)
     printf("%5d\n",X);    
  printf("-----------------------\n");     
  for(X=1;X<=5;X=X+2)
     printf("%5d\n",X);    
  printf("-----------------------\n");     
 return 0;
}

