/// IV.DOUBLY LINKED LIST ///

// 10.DELETE LAST NODE //

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

NODE *Del_Last_Node(NODE *head){
    NODE *ptr = head;

    if(head == NULL){
        printf("List is already Empty");
    }
    else if(head->next == NULL){
        head = head->next;
        free(ptr);
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        NODE *ptr1 = ptr->prev;
        ptr1->next = NULL;
        free(ptr);
        ptr = NULL;
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
    head = Add_At_End(head,10);
    // head = Add_At_End(head,20);
    // head = Add_At_End(head,30);
    // head = Add_At_End(head,40);
    // head = Add_At_End(head,50);

    Print_Data(head);
    head = Del_Last_Node(head);
    Print_Data(head);
    return 0;
}
