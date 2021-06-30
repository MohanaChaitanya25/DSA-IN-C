/// IV.DOUBLY LINKED LIST ///

// 8.CREATING ENTIRE DOUBLY LINKED LIST //

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next; 
};

typedef struct node NODE;

NODE *CreateNode(NODE *head, int data){
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

NODE *Add_At_End(NODE *head, int data){
    NODE *temp = CreateNode(head, data);
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

NODE *CreateList(NODE *head){
    int n, data, i;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    if(n == 0)
        return head;

    printf("Enter the element for the node 1 : ");
    scanf("%d", &data);

    head = Add_At_End(head, data);

    for(i=1; i<n; i++){
        printf("Enter the element for the node %d : ", i+1);
        scanf("%d", &data);
        head = Add_At_End(head, data);
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
    head = CreateList(head);

    Print_Data(head);
    return 0;
}
