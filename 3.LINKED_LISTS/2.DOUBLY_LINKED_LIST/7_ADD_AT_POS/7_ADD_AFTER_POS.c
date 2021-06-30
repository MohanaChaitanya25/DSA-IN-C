/// IV.DOUBLY LINKED LIST ///

// 7.ADD NODE AFTER POSITION //

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


NODE *Add_After_Pos(NODE *head, int data, int pos){
    NODE *temp = CreateNode(data);
    NODE *ptr = head;
    NODE *ptr1 = NULL;

    while(pos > 1){
        ptr = ptr->next;
        pos--;
    }

    if(ptr->next == NULL){
        // ADD_AT_END
        ptr->next = temp;
        temp->prev = ptr;
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
    head = Add_At_End(head,10);
    head = Add_At_End(head,20);
    head = Add_At_End(head,30);
    head = Add_At_End(head,40);

    Print_Data(head);

    head = Add_After_Pos(head,50,4);
    Print_Data(head);
    return 0;
}