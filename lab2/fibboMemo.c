#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

long long int fibbo(int n, long long int memo[])
{
    if (memo[n] != -1)
    {
        return memo[n];
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    memo[n] = fibbo(n - 1, memo) + fibbo(n - 2, memo);
    return memo[n];
}

int main()
{
    int n, choice;
    long long int result;
    long long int memo[MAX];

    for (int i = 0; i < MAX; i++)
    {
        memo[i] = -1;
    }

    do
    {
        printf("Enter your choice (1 to compute Fibonacci, 2 to exit): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the nth term: ");
            scanf("%d", &n);

            if (n <= 0 || n >= MAX)
            {
                printf("Please enter a positive integer less than %d.\n", MAX);
                break;
            }

            result = fibbo(n, memo);
            printf("The %dth Fibonacci number is: %lld\n", n, result);
            break;

        case 2:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}
