#include <stdio.h>


void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}


void swap2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int main(int argc, char *argv[])
{
    int a = 1, b = 2;
    swap2(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
    
    return 0;
}
