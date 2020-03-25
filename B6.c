
/*
P6. Sa se realizeze un program care realizeaza suma a doua
numere intr-o metoda separate de metoda main, iar aceea
metoda returneaza un pointer.
*/

#include <stdio.h>
#include <stdlib.h>

int suma(int x, int y)
{
	int *suma;
	suma = (int*)malloc(sizeof(int));
	*suma = x + y;
	return *suma;
}

int main()
{
	int x, y;

	printf("dati o valoare lui x: "); scanf("%d", &x);
	printf("dati o valoare lui y: "); scanf("%d", &y);
	printf("suma numerelor este %d\n", suma(x, y));
	system("pause");
	return 0;
}
