#include <stdio.h>

int fact(int n, int a)
{
    if (n == 0)
    {
        return a;
    }
    return fact(n - 1, a * n);
}

int main()
{
    int n;
    printf("Enter the number (n): ");
    scanf("%d", &n);
    printf("%d is the factorial of %d", fact(n, 1), n);
    return 0;
}