/// III.SINGLY LINKED LIST ///

// 6.ADD AT BEGIN //

// METHOD #2 //

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
    NODE *ptr = head;
    
    if(head == NULL){
        head = temp;
    }

    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

void Add_At_Beg_2(NODE **head,int data)
{
        NODE *temp = Create_Data(data);
    
        temp->next = *head;
        *head = temp;
}

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

int main()
{
    NODE *head = NULL;

    head = Add_At_End(head,10);
    head = Add_At_End(head,20);
    head = Add_At_End(head,30);
    head = Add_At_End(head,40);

    Add_At_Beg_2(&head,50);
    
    Print_Data(head);
    return 0;
}
