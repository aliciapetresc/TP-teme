
#include <stdio.h>
#include <stdlib.h>

#define MAX_BASE10_SIZE 65535
#define MAX_BASE10_DIGITS 5
#define MAX_BASE2_DIGITS 16 // Avem nevoie de max 16 biti pt a reprezenta valoarea 65535 (2^16 - 1 = 65535)

int Base10_Stack[MAX_BASE10_DIGITS];
int Base10_Top = -1;
int Base2_Stack[MAX_BASE2_DIGITS];
int Base2_Top = -1;

void Push_Base10(int x)
{
	if (Base10_Top == MAX_BASE10_DIGITS - 1)
	{
		printf("Error: stack overflow\n");
		return;
	}
	Base10_Stack[++Base10_Top] = x;
}

void Pop_Base10()
{
	if (Base10_Top == -1)
	{
		printf("Error: No element to pop\n");
		return;
	}
	Base10_Top--;
}

int Peek_Base10()
{
	return Base10_Stack[Base10_Top];
}

int IsEmpty_Base10()
{
	if (Base10_Top == -1)
	{
		return 1;
	}
	return 0;
}

void Push_Base2(int x)
{
	if (Base2_Top == MAX_BASE2_DIGITS - 1)
	{
		printf("Error: stack overflow\n");
		return;
	}
	Base2_Stack[++Base2_Top] = x;
}

void Pop_Base2()
{
	if (Base2_Top == -1)
	{
		printf("Error: No element to pop\n");
		return;
	}
	Base2_Top--;
}

int Peek_Base2()
{
	return Base2_Stack[Base2_Top];
}

int IsEmpty_Base2()
{
	if (Base2_Top == -1)
	{
		return 1;
	}
	return 0;
}

int main() {
	// a) Citirea conditionata
	unsigned int n;
	printf("Dati un numar: "); scanf("%u", &n);

	// Daca n e mai mare decat valoare maxima
	while (n > MAX_BASE10_SIZE) 
	{
		printf("\n%u depaseste valoarea maxima, introdu un alt numar: ", n);
		scanf("%u", &n);
	}

	// b) + c) Transformare din zecimal in binar + Adaugarea fiecarui bit in stiva
	unsigned int nr = n;
	while (nr != 0) 
	{
		int c = nr % 2;
		Push_Base2(c);
		nr = nr / 2;	
	}
	
	// d) Adaugarea fiecarei cifre in stiva
	nr = n;
	while (nr != 0) 
	{
		int c = nr % 10;
		Push_Base10(c);
		nr = nr / 10;
	}

	// Pentru ca tranformarea in cifre la b) si d) se face de la coada la cap, putem sa citim din nou, si sa comparam cu valoarea din stiva care este invers fata de valorea pe care o citim
	nr = n;
	while (nr != 0) 
	{
		int c = nr % 2;

		if (Peek_Base2() != c) {
			printf("Numarul nu este palindrom in reprezentarea binara.\n");
			return 0;
		}
		Pop_Base2();
		nr = nr / 2;
	}

	nr = n;
	while (nr != 0) 
	{
		int c = nr % 10;

		if (Peek_Base10() != c) 
		{
			printf("Numarul nu este palindrom in reprezentarea zecimala.\n");
			return 0;
		}

		Pop_Base10();

		nr = nr / 10;
	}

	printf("Numarul este palindrom in ambele reprezentari.");
	system("pause");

	return 0;
}
