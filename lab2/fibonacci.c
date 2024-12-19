#include <stdio.h>

int fibbo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibbo(n - 1) + fibbo(n - 2);
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Fibbo of n term is: %d", fibbo(n));
    return 0;
}