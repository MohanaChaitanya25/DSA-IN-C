// /// III.SINGLY LINKED LIST ///

// // 9.DELETING LAST NODE //

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

NODE *Del_Last_Node(NODE *head){
    if(head == NULL){
        printf("Linked List is already empty!\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }

    // METHOD - 1
    else{
        NODE *ptr = head;
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }

    // METHOD - 2
    /*else{
        NODE *curr = head;
        NODE *prev = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        free(curr);
        curr = NULL;
        prev->next = NULL;
    }*/
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

    head = Del_Last_Node(head);
    Print_data(head);
    head = Del_Last_Node(head);
    Print_data(head);
    head = Del_Last_Node(head);

    Print_data(head);
    return 0;
}