/// III.SINGLY LINKED LIST ///

// 2.CREATING SINGLY LINKED LIST //

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *Create_Node(int data){
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
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
    first->next = second;
    return 0;
}
