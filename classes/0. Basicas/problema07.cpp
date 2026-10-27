
#include<stdio.h>
#include<conio.h>
int main()
{
  int A=79;
  int B=10;
  int coc,res;
  
  coc=A/B;
  res=A%B;
  printf("COCIENTE  >> %d\n",coc);
  printf("   RESTO  >> %d\n",res);
  
  if(coc>res)
   {
   	printf("# MAS GRANDE %d \n",(10*coc+res));
   	printf("# MAS PEQUE  %d \n",(10*res+coc));
   }
  else
   {
   	printf("# MAS GRANDE %d \n",(10*res+coc));
   	printf("# MAS PEQUE  %d \n",(10*coc+res));
   }
  
  return 0;
}







