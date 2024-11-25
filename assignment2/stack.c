#include <stdio.h>
#include <stdbool.h>
#define MAX 5

// stack definition
struct Stack
{
    int Top;
    int Data[MAX];
};

// functions
void push(struct Stack *S, int x)
{
    if (S->Top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        S->Top++;
        S->Data[S->Top] = x;
    }
}

int pop(struct Stack *S)
{
    if (S->Top == -1)
        return -1;
    S->Top--;
    return S->Data[S->Top + 1];
}

int peek(struct Stack *S)
{
    if (S->Top == -1)
        return -1;
    return S->Data[S->Top];
}

bool isEmpty(struct Stack *S)
{
    return S->Top == -1;
}

bool isFull(struct Stack *S)
{
    return S->Top == MAX - 1;
}

int printStack(struct Stack *S)
{
    if (S->Top == -1)
    {
        printf("Stack is empty\n");
    }
    for (int i = S->Top; i >= 0; i--)
    {
        printf("%d\n", S->Data[i]);
    }
}

int main()
{
    struct Stack S;
    S.Top = -1;
    int x;
    int choice = 0;
    while (choice != 5)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &x);
            push(&S, x);
            break;
        case 2:
        {
            int popped = pop(&S);
            if (popped != -1)
            {
                printf("Popped element: %d\n", popped);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        }
        case 3:
        {
            int picked = pop(&S);
            if (picked != -1)
            {
                printf("picked element: %d\n", picked);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        }
        break;
        case 4:
            printStack(&S);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}