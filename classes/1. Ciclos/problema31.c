#include<stdio.h>
#include<conio.h>
int main()
{
  int X;  
  for(X=1;X<=25;X++)
    {
     printf("%10d %10d %10d\n",X,X*X,X*X*X);    
	 if(X==7)break;
	}
  printf("-----------------------\n");     
  
 return 0;
}

