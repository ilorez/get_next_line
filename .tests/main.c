
#include "../get_next_line.h"

int main()
{
  printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
  int fd = open("./.tests/test.txt", O_RDONLY);
  char *line;
  free(NULL);
  line = get_next_line(fd);
  while (line)
  {
    printf("===============================================================\n");
    printf("line:[%s]", line);
    printf("===============================================================\n");
    free(line);
    line = get_next_line(fd);
  }
  return 0;
}

/*char *ft_strdup(char *s)
{
  char *p = malloc(strlen(s) + 1);
  if (p == NULL)
    return NULL;
  strcpy(p, s);
  return p;
}

void update_pointer(char **p)
{
  *p = "world";
}


int main()
{
  static char *p;
  p = ft_strdup("hello");
  printf("%s\n", p);
  update_pointer(&p);
  printf("%s\n", p);


}
*/
/* example 1;
int example1() {
    int i = 0;
    while (i < 5) {
        static int j = 0;
        j++;
        printf("j = %d\n", j);
        i++;
    }
    return 0;
}

// example 2 using another function;
int f2() {
    static int x = 0;
    x++;
    return x;
}

int example2() {
    printf("%d\n", f2());
    printf("%d\n", f2());
    printf("%d\n", f2());
    return 0;
}

// example 3 using recursion;
int f3() {
    static int x = 0;
    x++;
    return x;
}

int example3(int n) {
    if (n > 0) {
        printf("%d\n", f3());
        example3(n - 1);
    }
    return 0;
}


int main() {
    example1();
    example2();
    example3(5);
    return 0;
}
*/

