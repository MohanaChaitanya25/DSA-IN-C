/// III.SINGLY LINKED LIST ///

// 7.ADD NODE BEFORE POSITION //

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

NODE *Add_Before_Pos(NODE *head, int data, int pos){
    NODE *temp = Create_Data(data);

    if(pos == 1){
        temp->next = head;
        head = temp;
    }
    else{
        NODE *ptr = head;

        while(pos > 2){
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}

void Print_data(NODE *head)
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
    head= Add_At_End(head,10);
    head= Add_At_End(head,20);
    head = Add_At_End(head,30);
    Print_data(head);

    head = Add_Before_Pos(head,40,3);
    Print_data(head);

    return 0;
}