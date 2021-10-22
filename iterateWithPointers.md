```c
  char Text[100];
  Text = "hulululu";
  char* pText = Text;
  while(*pText != '\0') pText++;
  //while(*pText++ != '\0');
  TextLen = pText - Text;
```
