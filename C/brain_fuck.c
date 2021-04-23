#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// 'result' must contain at least one character - '\0'
char* brain_luck(char* code, char* input)
{
  char buf[1024] = {0}, *begin = code;
  int offset[256] = {0}, top = 0, pass = 0;
  char* result = NULL;
  int idx = 0, i = 0, o = 0;
  // place your code here
  int len = strlen(input);
  result = calloc(len + 1, 1);
  //printf("Here\n");
  while (*code && i <= len+1) {
      switch(*code) {
      case '>': if(!pass) ++idx;
          break;
      case '<': if(!pass) --idx;
          break;
      case '+': if(!pass) buf[idx]++;
          break;
      case '-': if(!pass) buf[idx]--;
          break;
      case '.':
          if(!pass) {
               result[o++] = buf[idx];
               //printf("result = %c, %d\n", result[o-1] , result[o-1]);
          }

          break;
      case ',':
          if(!pass) {
                buf[idx] = input[i], i++;
          }
          break;
      case '[':
          if(!pass) {
              if (buf[idx]) {
                  offset[top++] = (int)(code-begin);
              } else {
                  pass++;
              }
          } else {
              pass++;
          }
          break;
      case ']':
          if (!pass) {
              top--;
              code = begin + offset[top] - 1;
          } else {
              pass--;
          }
          break;
      }


      ++code;
      //printf("offset = %d\n", code-begin);
  }
  return result;
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
  return 0;
}
