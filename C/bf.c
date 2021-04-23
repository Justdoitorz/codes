#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#ifndef bzero(ptr size)
//#define bzero(ptr, size)    memset(ptr, 0, size)
//#endif // bzero

char* brain_luck(char* pc, char* in)
{
  unsigned char *dp = malloc(1024);
  memset(dp, 0, 1024);

  char *t = malloc(1024);
  memset(t, 0, 1024);

  char *o = t;
  while (*pc) {
    switch (*pc) {
      case '>':
        dp++;
        break;
      case '<':
        dp--;
        break;
      case '+':
        (*dp)++;
        break;
      case '-':
        (*dp)--;
        break;
      case '.':
        *o++ = *dp;
        break;
      case ',':
        *dp = *in;
        in++;
        break;
      case '[':
        if (*dp == 0) {
          int x = 1;
          do {
            pc++;
            if (*pc == '[')
              x++;
            if (*pc == ']')
              x--;
          } while(x);
        }
        break;
      case ']':
        if (*dp != 0) {
          int x = 1;
          do {
            pc--;
            if (*pc == ']')
              x++;
            if (*pc == '[')
              x--;
          } while(x);
        }
        break;
    }
    pc++;
  }

  return t;
}


void dotest(char* code, char* input, char* expected)
{
  char* actual = brain_luck(code, input);

  printf("actual = %s\n", actual);
  //cr_assert_str_eq(expected, actual, "Expected \"%s\", but got \"%s\"", expected, actual);

  free(actual);
}

int main()
{
  // copy the input to the output
  dotest(",+[-.,+]", "codewars", "codewars");
  dotest(",[.[-],]", "test123", "test123");
  dotest(",[>,]<[.<]", "i like to code", "edoc ot ekil i");
  return 0;
}
