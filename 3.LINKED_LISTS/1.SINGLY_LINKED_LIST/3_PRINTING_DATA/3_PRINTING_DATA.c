/// III.SINGLY nextED LIST ///

// 3.PRINTING DATA //

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

void Print_Data(struct node *head)
{
    if(head==NULL)
        printf("Linked List is Empty\n");
        
    NODE *ptr = head;   

    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

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

    Print_Data(head);
    return 0;
}
