/// III.SINGLY LINKED LIST ///

// 4.TOTAL NODES //

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

void Total_Nodes(NODE *head)
{
    int count = 0;
    if(head == NULL)
        printf("Linked List is Empty\n");

    NODE *ptr = head;
    
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    
    printf("Total Nodes : %d\n",count);
}

int main()
{
    NODE *head = Create_Node(10);
    NODE *first = Create_Node(20);
    NODE *second = Create_Node(30);
    
    head->next = first;
    first->next = second;

    Total_Nodes(head);
    return 0;
}
