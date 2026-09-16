
#include <stdio.h>

int main(int argc, char *argv[]) {
  // This is your first C program my friend
  
  printf("You passed %d argument(s).\n", argc - 1);
  printf("Hello from <Aygul Ismayilova>! \n");
  for (int i = 1; i < argc; ++i) {
    printf("  arg[%d] = %s\n", i, argv[i]);
  }
  return 0;
}
