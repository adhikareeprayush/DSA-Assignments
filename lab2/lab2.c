#include <stdio.h>
#define MAX 5

struct CircularQueue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};

typedef struct CircularQueue CQ;

void enqueue(CQ *Q, int element)
{
    if (Q->FRONT == (Q->REAR + 1) % MAX)
    {
        printf("Queue is Full");
    }
    else
    {
        Q->DATA[Q->REAR] = element;
        Q->REAR = (Q->REAR + 1) % MAX;
        printf("Element was Enqueued");
    }
}

int dequeue(CQ *Q)
{
    int element = -1;
    if (Q->FRONT == Q->REAR)
    {
        printf("Queue is Empty");
    }
    else
    {
        element = Q->DATA[Q->FRONT];
        Q->FRONT = (Q->FRONT + 1) % MAX;
    }
}

int main()
{
    int choice, data;
    CQ Q = {0, 0};
    do
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.EXIT\n");
        printf("Choice? ");
        scanf("%d", choice);
        switch (choice)
        {
        case 1:
        {
            int element;
            printf("Enter the element: ");
            scanf("%d", element);
            enqueue(&Q, element);
            break;
        }
        case 2:
        {
            int data = dequeue(&Q);
            if (data != -1)
            {
                printf("%d", dequeue(&Q));
            }
            break;
        }
        case 3:
            printf("Bye!\n");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 3);

    return 0;
}