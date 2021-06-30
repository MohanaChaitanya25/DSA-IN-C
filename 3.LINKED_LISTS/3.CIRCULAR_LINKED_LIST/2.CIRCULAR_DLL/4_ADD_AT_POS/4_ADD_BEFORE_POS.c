/// VI.CIRCULAR DOUBLY LINKED LIST ///

// 4.ADDING NODE BEFORE POS //

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

NODE *Add_Before_End(NODE *tail,int data, int pos){
    NODE *temp = Create_Node(data);
    NODE *ptr = tail->next;
    if(tail == NULL){
        tail = temp;
    }
    else if(pos==1){
        // ADD AT BEG
        temp->next = ptr;
        temp->prev = tail;
        tail->next = temp;
        ptr->prev = temp;
    }

    else{
        while(pos != 2){
            ptr = ptr->next;
            pos--;
        }
        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next = temp;
        ptr->next->prev = temp;
 
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
    tail = Add_At_End(tail,40);
    Print_Data(tail);
    tail = Add_Before_End(tail,50,1);
    Print_Data(tail);
    tail = Add_Before_End(tail,60,1);
    Print_Data(tail);
    return 0;
}