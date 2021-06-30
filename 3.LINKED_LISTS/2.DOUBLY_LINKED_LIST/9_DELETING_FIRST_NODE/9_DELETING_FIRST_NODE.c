/// IV.DOUBLY LINKED LIST ///

// 9.DELETE FIRST NODE //

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

NODE *Del_First_Node(NODE *head){
    NODE *ptr = head;

    if(head == NULL){
        printf("List is already Empty");
    }
    else if(head->next == NULL){
        head = head->next;
        free(ptr);
    }

    else{
        /// METHOD- 1 ///
        head = head->next;
        free(ptr);
        ptr = NULL;
        head->prev = NULL;

        /// METHOD-2 ///
        // head = head->next;
        // free(head->prev);
        // head->prev = NULL;
    }
    return head;
}

void Print_Data(NODE *head)
{
    if(head==NULL)
        printf("Linked List is Empty\n");
        
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
    // head = Add_At_End(head,20);
    // head = Add_At_End(head,30);
    // head = Add_At_End(head,40);
    // head = Add_At_End(head,50);

    Print_Data(head);
    // head = Del_First_Node(head);
    head = Del_First_Node(head);
    Print_Data(head);
    return 0;
}
