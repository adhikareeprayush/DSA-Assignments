#include <stdio.h>
#include <stdlib.h>

// Basic Linked List Structure
struct LinkedList {
    int data; // for storing numbers
    struct LinkedList *next; // for storing the address of the next node
};

typedef struct LinkedList LL;

int main() {
    LL *first, *last; // pointer to the first node & last node
    first = last = NULL; // initially the list is empty


    LL *firstElement = (LL *)malloc(sizeof(LL)); // creating the first element
    firstElement->data = 10;
    firstElement->next = NULL;
    first = last = firstElement; // setting the first and last pointers to the first element

    printf("First Element: %d\n", firstElement->data);

    return 0;
}