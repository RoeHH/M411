#include <stdio.h>
#include <stdlib.h>

// a function named trim that removes spaces from the beginning and end of a string
char* trim(char* p) {
    while (*p == ' ') p++;
    while (*p != '\0') p++;
    while (*p == ' ') p--;
    p++;
    *p = '\0';
    return p;
}

int main() {
    char Text[255] = "       Das ist ein Text              ";
    Text = trim(Text);
    printf("Text = \"%s\"\n", Text);
    system("pause");
    return 0;
}