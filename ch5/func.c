#include <stdio.h>
#include <ctype.h>
#include "func.h"

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return bufp > 0 ? buf[bufp--] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == 'c')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(int argc, char *argv[])
{
    int n, array[SIZE];
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("%d\n", array[n]);

    return 0;
}
