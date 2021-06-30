/// IV.DOUBLY LINKED LIST ///

// 7.ADD NODE BEFORE POSITION //

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
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    return ptr;
}

NODE *AddToEmpty(NODE *head, int data){
    NODE *temp = CreateNode(data);
    head = temp;
    return head;
}

NODE *Add_At_End(NODE *head, int data){
    NODE *temp = CreateNode(data);
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

NODE *Add_BeforePos(NODE *head, int data, int pos){
    NODE *temp = CreateNode(data);
    NODE *ptr = head;

    while(pos > 2){
        ptr = ptr->next;
        pos--;
    }

    if(pos==1){
        temp->next = head;
        head->prev = temp; 
        head = temp;
    }
    else{
        NODE *ptr1 = ptr->next;
        ptr->next = temp;
        ptr1->prev = temp;
        temp->prev = ptr;
        temp->next = ptr1;
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
    head = AddToEmpty(head,10);
    head = Add_At_End(head,20);
    head = Add_At_End(head,30);
    head = Add_At_End(head,40);

    Print_Data(head);

    head = Add_BeforePos(head,50,1);
    Print_Data(head);
    return 0;
}
