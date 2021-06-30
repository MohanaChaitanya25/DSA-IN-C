/// III.SINGLY LINKED LIST ///

// 12.REVERSING SINGLY LINKED LIST //

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

NODE *Reverse(NODE *head)
{
    NODE *prev = NULL;
    NODE *next = NULL;
    
    while(head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}


int main()
{
    NODE *head = NULL;
    head = Add_At_End(head,10);
    head = Add_At_End(head,20);
    head = Add_At_End(head,30);
    head = Add_At_End(head,40);
    
    Print_Data(head);
    head = Reverse(head);
    Print_Data(head);
    return 0;
}
