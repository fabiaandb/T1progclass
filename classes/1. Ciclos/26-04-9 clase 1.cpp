#include <stdio.h>
#include <conio.h>

int main()
{
	int X;
	for(X=1;X<=25;X++)
	{
		printf("%10d %10d %10d\n",X,X*X,X*X*X); // el 10 entre el % y el d es para los espacios
		if(X==7)break;
	}
	
	
	
}