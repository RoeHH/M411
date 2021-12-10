# B04

## Aufgabe 5
![](a5.png)

Nr. | Anweisungssequenz | Rückgabewert der AnweisungssequenzFehlerbeschreibung
--- | --- | ---
01 | Feld | 13'500
02 | Feld[0] | 87
03 | &Feld[9] | 13'500 + 9 *4Byte
04 | Feld[0] + Feld | 87 * 4Byte  + 13'500 = 13'848 Out of array
05 | Feld[2] + 5 | -28
06 | Feld[10] | Error
07 | &Feld[0] | 13'500
08 | &Feld[2 + 5] | ..
09 | 13500[2] | wtf bsoffe?
10 | Feld[8-3] + Feld[3] | 55 + (-30)

## Aufgabe 6 
Schreiben Sie ein Programm mit welchem Sie einen String «Text»über die Tastatur eingeben, danach mit Hilfe von Pointern die Länge des Strings bestimmenund das Resultat (Stringlänge) ausgeben.
```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Text[100];

    printf("Input:");
    gets_s(Text);

    char* pText = Text;

    while (*pText != '\0')
    {
        pText++;
    }

    for (--pText; pText >= Text; pText--)
    {
        printf("%c", *pText);
    }

    system("pause");
}
```

## Aufgabe 09 Leerzeichen am Anfang eines Strings entfernen
Schreiben Sie ein Programm mit welchem Sie einen String «Text» über die Tastatur eingeben. Entfernen Sie danach mit Hilfe von Pointern alle Leerzeichen am Anfang des Strings. Geben Sie am Schluss den bearbeiteten String aus. \
Vorher: "      Hallo" \
Nachher: "Hallo     "
```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Text[100];

    printf("Input:");
    gets_s(Text);

    char* pText = Text;
    int nummberOfSpaces = 0;

    while (*pText == ' ')
    {
        *pText = NULL;
        nummberOfSpaces++;
        pText++;
    }

    for (--pText; pText >= Text; pText--)
    {
        printf("%c", *pText);
    }

    system("pause");
}
```