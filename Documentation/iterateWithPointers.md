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
