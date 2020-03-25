/*
P4: Sa se realizeze un program care imi transforma un numar
zecimal intr-un numar binar, cifrele binare vor fi insiruite intr-
un sir de elemente folosind pointer-ul.

* am incercat sa o fac, dar nu am reusit sa pun lucrurile cap la cap,
am lasat doar lista simplu inlantuita
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

	typedef struct binar
	{
		int n;
		struct binar *urm;
	}nod;

	nod *adaugare(nod *prim, int k)
	{
		nod *p, *q;
		p = (nod *)malloc(sizeof(nod));
		p->n = k;
		p->urm = NULL;
		if (p == NULL || p->n == NULL)
		{
			printf("Eroare la alocarea memoriei!\n");
			exit(0);
		}

		if (prim == NULL) 
			return p;
		else {
			q = prim;
			while (q->urm != NULL)
				q = q->urm;
			p->urm = q->urm;
			q->urm = p;
			return prim;
		}
	}

	void afisare(nod *prim)
	{
		nod *q;
		q = prim;

		while (q!=NULL)
		{
			printf("%d ", q->n);
			q = q->urm;
		}
	}

	int main()
	{
		int n;
		nod *prim;
		prim = NULL;

		return 0;
	}


	

	system("pause");
	return 0;
}

