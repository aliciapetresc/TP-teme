/* P8.Sa se calculeze patratul unui numar natural N introdus de la tastatura folosind doar operatiile de tip bit wise.

n par   => n= 2*x   => n^2= 4*x^2       => patrat(n)= 4*patrat(n/2)
n impar => n= 2*x+1 => n^2= 4*x^2+4*x+1 => patrat(n)= 4*patrat(floor(n/2))+4*floor(n/2)+1

*/

#include <stdio.h>
#include <stdlib.h>

int patrat(int n)
{
	if (n == 0)
		return 0;

	if (n < 0) 
		n = -n;

	// floor(n/2) cu shiftare la dreapta
	int x = n >> 1;

	// n -impar
	if (n & 1)
		return ((patrat(x) << 2) + (x << 2) + 1);
	else // n-par
		return (patrat(x) << 2);
}

int main()
{
	int n;
	printf("Dati un numar: "); scanf("%d", &n);
	printf("Patratul numarului este %d \n", patrat(n));
	system("pause");
	return 0;
}