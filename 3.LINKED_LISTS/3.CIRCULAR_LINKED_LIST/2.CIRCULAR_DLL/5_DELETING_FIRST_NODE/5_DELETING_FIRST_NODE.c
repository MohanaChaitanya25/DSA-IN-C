/// VI.CIRCULAR DOUBLY LINKED LIST ///

// 5.DELETING FIRST NODE //

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;

NODE *Create_Node(int data){
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = data;
    ptr->prev = ptr;
    ptr->next = ptr;
    return ptr;
}

NODE *Del_First_Node(NODE *tail){
    NODE *ptr = tail->next;

    if(tail == NULL){
        printf("List is already empty\n");
    }
    else if(tail->next == tail){
        free(tail);
        tail = NULL;
    }
    else{
        tail->next = ptr->next;
        ptr->next->prev = tail;
        free(ptr);
        ptr = NULL;
    }
    return tail;
}

NODE *Add_At_End(NODE *tail,int data){
    NODE *temp = Create_Node(data);
    if(tail == NULL){
        tail = temp;
    }
    else{
        NODE *ptr = tail->next;

        temp->next = ptr;
        temp->prev = tail;
        tail->next = temp;
        ptr->prev = temp;
        tail = temp;
    }
    return tail;
}

void Print_Data(NODE *tail){
    if(tail==NULL)
        printf("List is empty!");
    else{
        NODE *ptr = tail->next;
        do{
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }while(ptr != tail->next);
    }
    printf("\n"); 
}

int main()
{
    NODE *tail = Create_Node(10);
    tail = Add_At_End(tail,20);
    tail = Add_At_End(tail,30);
    // tail = Add_At_End(tail,40);
    Print_Data(tail);

    tail = Del_First_Node(tail);
    Print_Data(tail);
    tail = Del_First_Node(tail);
    Print_Data(tail);
    tail = Del_First_Node(tail);
    Print_Data(tail);
    return 0;
}