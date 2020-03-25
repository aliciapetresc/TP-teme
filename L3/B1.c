/*
P1. Sa se scrie un program care citeste de la tastura "N" numere naturale. Pentru fiecare numar se va 
determina forma lui binara, se va calcula inversul binar ,iar mai apoi se va afisa numarul zecimal 
calculat din inversul binar.

nu cred ca am facut bine inversul binar
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, a, k;

	printf("Introduceti un nr intreg: "); 
	scanf("%d", &n);

	printf("%d in binar este: \n", n);
	for (a = 10; a >= 0; a--)
	{
		k = n >> a;
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	printf("Inversul binar este: \n");
	for (a = 10; a >= 0; a--)
	{
		n= k >> a;
		if (n & 1)
			printf("0");
		else
			printf("1");
	}
	printf("\n");

	system("pause");
	return 0;
}

