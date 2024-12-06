#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

// Structure to represent a student
struct student
{
    int roll;
    char name[20];
    float marks;
};

// Stack definition
struct Stack
{
    int Top;
    struct student Data[MAX];
};

// Function to push a student onto the stack
void push(struct Stack *S, struct student x)
{
    if (S->Top == MAX - 1)
    {
        printf("Stack is full. Cannot push more elements.\n");
    }
    else
    {
        S->Top++;
        S->Data[S->Top] = x;
        printf("Pushed: Roll=%d, Name=%s, Marks=%.2f\n", x.roll, x.name, x.marks);
    }
}

// Function to pop a student from the stack
struct student pop(struct Stack *S)
{
    struct student emptyStudent = {-1, "", -1.0}; // Default empty student
    if (S->Top == -1)
    {
        printf("Stack is empty. Cannot pop.\n");
        return emptyStudent;
    }
    return S->Data[S->Top--];
}

// Function to peek the top student on the stack
struct student peek(struct Stack *S)
{
    struct student emptyStudent = {-1, "", -1.0}; // Default empty student
    if (S->Top == -1)
    {
        printf("Stack is empty. Nothing to peek.\n");
        return emptyStudent;
    }
    return S->Data[S->Top];
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *S)
{
    return S->Top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack *S)
{
    return S->Top == MAX - 1;
}

// Function to print the stack
void printStack(struct Stack *S)
{
    if (S->Top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int i = S->Top; i >= 0; i--)
        {
            printf("Roll=%d, Name=%s, Marks=%.2f\n", S->Data[i].roll, S->Data[i].name, S->Data[i].marks);
        }
    }
}

// Main function to demonstrate stack operations
int main()
{
    struct Stack S;
    S.Top = -1; // Initialize stack
    int choice = 0;

    while (choice != 5)
    {
        printf("\nMenu:\n");
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
        {
            struct student newStudent;
            printf("Enter roll number: ");
            scanf("%d", &newStudent.roll);
            printf("Enter name: ");
            scanf(" %[^\n]s", newStudent.name); // Input with spaces
            printf("Enter marks: ");
            scanf("%f", &newStudent.marks);

            push(&S, newStudent);
            break;
        }
        case 2:
        {
            struct student popped = pop(&S);
            if (popped.roll != -1)
            {
                printf("Popped: Roll=%d, Name=%s, Marks=%.2f\n", popped.roll, popped.name, popped.marks);
            }
            break;
        }
        case 3:
        {
            struct student top = peek(&S);
            if (top.roll != -1)
            {
                printf("Top element: Roll=%d, Name=%s, Marks=%.2f\n", top.roll, top.name, top.marks);
            }
            break;
        }
        case 4:
            printStack(&S);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}
