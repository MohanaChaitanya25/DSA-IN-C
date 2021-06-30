/// III.SINGLY LINKED LIST ///

// 14.ADDING NEW NODE AFTER A GIVEN NODE //

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *Create_Node(int data){
    NODE *ptr = (NODE *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

NODE *Add_At_End(NODE *head, int data){
    NODE *temp = Create_Node(data);
    NODE *ptr = head;
    if(head==NULL){
        head = temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}


NODE *Insert_After_Node(NODE *head, int newdata, int data){
    NODE *temp = Create_Node(newdata);
    NODE *ptr = head;

    if(head == NULL || head->data > data){
        temp->next = head;
        head = temp;
    }
    else{
        ptr = head;
        while(ptr->next!=NULL && ptr->data != data){
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}


void Print_Data(NODE *head){
    NODE *ptr = head;
    if(ptr==NULL){
        printf("Linked List is Empty!\n");
    }
    else{
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    NODE *head = NULL;
    head = Add_At_End(head,10);
    head = Add_At_End(head,20);
    head = Add_At_End(head,30);
    head = Add_At_End(head,40);

    head = Insert_After_Node(head,100,20);

    Print_Data(head);
    return 0;
}
