#include <stdio.h>
#include <stdlib.h>
int main()
{
	int Laenge  = 0;
	int Breite    = 0;
	int Flaeche   = 0;
	int *pLaenge = &Laenge;
	int *pBreite  = &Breite;
	int *pFlaeche = &Flaeche;
	// Eingabe von L�nge und Breite......
	printf("Enter L&B: ");
	scanf_s("%d", &Laenge);
	scanf_s("%d", &Breite);
	// Verarbeitung der Eingabe, Berechnung der Fl�che......
	*pFlaeche = *pLaenge * *pBreite;
	// Ausgabe von L�nge, Breite und Fl�che......
	printf("Inhalt von pLaenge = %p \n", *pLaenge);
	printf("Inhalt von pBreite = %p \n", *pBreite);
	printf("Inhalt von pFlaeche = %p \n", *pFlaeche);
	system("pause");
	return 0;
}