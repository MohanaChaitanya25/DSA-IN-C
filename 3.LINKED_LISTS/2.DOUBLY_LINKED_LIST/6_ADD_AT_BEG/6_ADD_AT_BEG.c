/// IV.DOUBLY LINKED LIST ///

// 6.ADDING NODE AT BEGIN //

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;

NODE *CreateNode(int data){
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

NODE *Add_At_Beg(NODE *head, int data){
    NODE *temp = CreateNode(data);
    if(head == NULL){    
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
    return head;
}

void Print_Data(NODE *head){
    if(head==NULL)
        printf("Linked List is Empty\n");
        
    NODE *ptr = head;   

    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    NODE *head = NULL;
    head = Add_At_Beg(head,10);

    Print_Data(head);
    head = Add_At_Beg(head,20);
    head = Add_At_Beg(head,30);
    Print_Data(head);
    return 0;
}
