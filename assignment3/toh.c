#include <stdio.h>

void toh(int n, char src, char dst, char temp)
{
    if (n == 1)
    {
        printf("Move disk 1 src %c dst %c\n", src, dst);
        return;
    }
    toh(n - 1, src, temp, dst);
    printf("Move disk %d src %c dst %c\n", n, src, dst);
    toh(n - 1, temp, dst, src);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    toh(n, 'A', 'C', 'B');
    return 0;
}