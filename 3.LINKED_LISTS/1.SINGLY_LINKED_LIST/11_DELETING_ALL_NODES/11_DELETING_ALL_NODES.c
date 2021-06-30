/// III.SINGLY LINKED LIST ///

// 11.DELETING ALL NODES //

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *Create_Data(int data){
    NODE *ptr =(NODE *)malloc(sizeof(NODE));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

NODE *Add_At_End(NODE *head,int data)
{
    NODE *temp = Create_Data(data);

    if(head==NULL){
        head = temp;
    }
    else{
        NODE *ptr = head;  

        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = temp;
    }
    return head;
}


NODE *Del_List(NODE *head){
    if(head == NULL){
        printf("Linked List is already empty!\n");
    }
    else {
        NODE *ptr = head;
        while(ptr != NULL){
            ptr = ptr->next;
            free(head);
            head = ptr;
        }
    }
    return head;
}


void Print_data(NODE *head)
{
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
    head= Add_At_End(head,10);
    head= Add_At_End(head,20);
    head = Add_At_End(head,30);
    Print_data(head);

    head = Del_List(head);

    Print_data(head);
    return 0;
}