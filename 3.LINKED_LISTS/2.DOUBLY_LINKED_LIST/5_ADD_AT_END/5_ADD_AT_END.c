/// IV.DOUBLY LINKED LIST ///

// 5.ADDING NODE AT END //

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

NODE *Add_At_End(NODE *head, int data){
    NODE *temp = CreateNode(data);

    if(head == NULL){
        head = temp;
    }
    
    else{
        NODE *ptr = head;
        
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->prev = ptr;
    }
    return head;
}

void Print_Data(struct node *head){
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
    Print_Data(head);
    head = Add_At_End(head,20);
    head = Add_At_End(head,30);
    Print_Data(head);
    return 0;
}
