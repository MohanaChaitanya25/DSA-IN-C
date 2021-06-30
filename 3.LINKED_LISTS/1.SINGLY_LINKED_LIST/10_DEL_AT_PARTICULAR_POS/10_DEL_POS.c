/// IV.SINGLY LINKED LIST ///

// 10.DELETE AT PARTICULAR POSITION //

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

NODE *Del_Pos(NODE *head, int pos){
    NODE *curr = head;
    NODE *prev = head;

    if(head == NULL){
        printf("Linked List is already empty!\n");
    }
    else if(pos == 1){
        head = head->next;
        free(curr);
        curr = NULL;
    }

    else{
        while(pos != 1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        free(curr);
        curr = NULL;
        prev->next = NULL;
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
    head= Add_At_End(head,10);
    // head= Add_At_End(head,20);
    // head = Add_At_End(head,30);
    Print_Data(head);

    head = Del_Pos(head,1);
    // Print_data(head);
    // head = Del_Pos(head,2);
    // Print_data(head);
    // head = Del_Pos(head,1);

    Print_Data(head);
    return 0;
}