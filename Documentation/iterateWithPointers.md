# Länge eines Strings bestimmen

```c++
  char Text[100];
  Text = "hulululu";
  char* pText = Text;
  while(*pText != '\0') pText++;
  //while(*pText++ != '\0');
  TextLen = pText - Text;
```

# Lehrzeichen entfernen am Anfang des Strings

```c++
  char Text[100] = "bananespliutischSoooFEIEIEIEN";
  printf("In: <%s>\n",Text);
  for(char* pText = Text; *pText != '\0'; pText++){
    if(*pText >= 'a' && *pText <= 'z')
      *pText -= 'k' - 'K';
  }
  printf("Out: <%s>\n",Text);
  system("pause");
  /*
    In: <bananespliutischSoooFEIEIEIEN>
    Out: <BANANESPLIUTISCHSOOOFEIEIEIEN>
  */
```


# String to Upper

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text_input[50];

  printf("Enter string to be uppercase: ");

  for (char* pt = fgets(text_input, sizeof(text_input), stdin); *pt != '\0' && *pt != 0x0a;) (*pt >= 'a' && *pt <= 'z') ? (*pt++ -= 0x20) : *pt++;

  printf("Uppercase String: %s", text_input);

  //system("pause");
  return 0;
}
```