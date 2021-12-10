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

// rick roll
// https://www.youtube.com/watch?v=dQw4w9WgXcQ
