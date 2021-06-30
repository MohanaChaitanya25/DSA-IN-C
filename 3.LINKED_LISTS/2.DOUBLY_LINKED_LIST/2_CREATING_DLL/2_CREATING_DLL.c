/// IV.DOUBLY LINKED LIST ///

// 2.CREATING DOUBLY LINKED LIST //

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;

NODE *Create_Node(int data){
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

int main()
{
    NODE *head = Create_Node(10);
    NODE *first = Create_Node(20);
    NODE *second = Create_Node(30);

    head->next = first;
    first->prev = head;

    first->next = second;
    second->prev = first;

    return 0;
}
