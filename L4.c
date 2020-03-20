// P3: Sa se realizeze un program care interschimba 2 valori folosind un pointer ca variabila auxiliara.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, *n;
	//allocam memorie
	n = (int *)malloc(sizeof(int));
	printf("Dati o valoare variabilei a: "); scanf("%d", &a);
	printf("Dati o valoare variabilei b: "); scanf("%d", &b);
	//interschimbarea
	*n = a;
	a = b;
	b = *n;
	printf("a devine %d ; b devine %d\n", a, b);
	system("pause"); 
	return 0;
}
