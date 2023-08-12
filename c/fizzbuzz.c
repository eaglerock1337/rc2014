#include <stdio.h>
#include <string.h>

int main() {
  for(int i = 1; i <= 100; i++) {
   char text[8] = "";
   text[8] = strcat("", i % 3 == 0 ? "Fizz" : "");
   text[8] = strcat(text, (i % 5 == 0) ? "Buzz" : "");
   text[8] = strlen(text) == 0 ? (char)i + "\n" : text;
   printf("%s\n", text);
  }
}