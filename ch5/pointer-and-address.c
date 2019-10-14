#include <stdio.h>
#include <assert.h>


int main(int argc, char *argv[])
{
    int x = 1, y = 2, z[10];
    int *ip;
    ip = &x;
    y = *ip;
    *ip = 0;
    ip = &z[0];

    assert(y == 1);
    assert(x == 0);
    assert(ip == z);

    ip = &y;
    printf("%d\n", *ip);
    ++*ip;
    printf("%d\n", *ip);
    (*ip)++; // calculate from right to left
    printf("%d\n", *ip);
    *ip++; // to next pointer
    printf("%d\n", *ip);
    
    return 0;
}
