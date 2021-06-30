/// IV.DOUBLY LINKED LIST ///

// 12.REVERSING DOUBLY LINKED LIST //

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next; 
};

typedef struct node NODE;

NODE *CreateNode(NODE *head, int data){
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

NODE *Add_At_End(NODE *head, int data){
    NODE *temp = CreateNode(head, data);
    NODE *ptr = head;

    if(head == NULL){
        head = temp;
    }
    
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
    return head;
}

NODE *Reverse_Dll(NODE *head){
    NODE *ptr = head;
    NODE *ptr1 = head->next;

    ptr->next = NULL;
    ptr->prev = ptr1;

    while(ptr1 != NULL){
        ptr1->prev = ptr1->next;
        ptr1->next = ptr;
        ptr = ptr1;
        ptr1 = ptr1->prev;
    }
    head = ptr;
    return head;
}

void Print_Data(NODE *head){
    if(head==NULL)
        printf("Linked List is Empty");
        
    NODE *ptr = head;
    
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    NODE *head = NULL;
    head = Add_At_End(head,10);
    head = Add_At_End(head,20);
    head = Add_At_End(head,30);
    head = Add_At_End(head,40);
    head = Add_At_End(head,50);

    Print_Data(head);
    head = Reverse_Dll(head);
    Print_Data(head);
    return 0;
}