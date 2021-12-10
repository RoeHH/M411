# Aufgaben mit Pointers

## Block 5

### Aufgabe 2

```c++
#include <stdio.h>
#include <stdlib.h>

//Schreibe die IndexOf Funktion
int IndexOf(int* array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (*array == value) {
            return i;
        }
        array++;
    }
    return -1;
}


int main()
{
    int Werte[] = {10, 12, 45, 56, 98, 23};

    printf("Index = %i\n", IndexOf (Werte, 6, 45));  // gibt 2 zurück
    printf("Index = %i\n", IndexOf (Werte, 6, 0));  // -1
    system("pause");
    return 0;
}
```

### Aufgabe 3

```cpp
#include <stdio.h>
#include <stdlib.h>

char* StringCopy (char *pDestStr, const char *pSourceStr){
    while (*pSourceStr != '\0') 
    {
        *pDestStr = *pSourceStr;
        pDestStr++;
        pSourceStr++;
    }
    *pDestStr = *pSourceStr;
    return pDestStr;    
}

int main(){
    char Text[255];
    StringCopy (Text, "Das ist ein Text");
    printf ("Text = \"%s\"\n", Text);
    system("pause");
    return 0;
}
```