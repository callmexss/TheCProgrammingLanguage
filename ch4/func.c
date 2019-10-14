#include <stdio.h>

#include "func.h"

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main(int argc, char *argv[])
{
    char c;
    while ((c = getch()) == ' ')
        ;

    ungetch('+');
    c = getch();
    printf("%c\n", c);
    return 0;
}
