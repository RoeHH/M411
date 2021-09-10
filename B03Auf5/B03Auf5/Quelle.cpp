#include <stdio.h>
#include <stdlib.h>
int main() {
	// 01.
	int Zahl = 345;
	int Wert;
	// 02.
	int *pZeig1, *pZeig2;
	// 03.
	pZeig1 = &Zahl;
	// 04.
	pZeig2 = &Wert;
	// 05.
	*pZeig2 = 45;
	// 06.
	pZeig2 = pZeig1;
	// 07.
	*pZeig2 = 100;
	// 08.
	printf("Zahl: %d \n", Zahl);
	printf("Zahl p: %p \n\n", &Zahl);
	// 09.
	printf("pZeig1: %p \n", pZeig1);
	printf("pZeig1 v: %d \n\n", *pZeig1);
	// 10.
	printf("Wert: %d \n", Wert);
	printf("Wert p: %p \n\n", &Wert);
	// 11.
	printf("pZeig2: %p \n", pZeig2);
	printf("pZeig2 v: %d \n\n", *pZeig2);
	system("pause");
	return 0;
}