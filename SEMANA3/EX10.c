#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int F1(unsigned int n);

int main()
{
    int x;

    scanf("%d", &x);
    x = F1(x);
    printf("%d\n", x);

    return 0;
}

int F1(unsigned int n)
{

    if (n == 0)
        return n;

    int i, j, k;

    for (i = j = 1; i < n; i++, j++)
        for (k = 0; k < n; k++, j++);

    return j;
}

