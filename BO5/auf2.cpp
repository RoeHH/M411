#include <stdio.h>
#include <stdlib.h>

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

