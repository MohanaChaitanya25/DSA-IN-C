/// VI.CIRCULAR DOUBLY LINKED LIST ///

// 4.ADDING NODE AFTER POS //

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

NODE *Add_After_End(NODE *tail,int data, int pos){
    NODE *temp = Create_Node(data);
    NODE *ptr = tail->next;
    if(tail == NULL){
        printf("List is Empty!\n");
    }
    else{
        while(pos != 1){
            ptr = ptr->next;
            pos--;
        }
        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next = temp;
        ptr->next->prev = temp;

        if(ptr == tail){
            tail =  tail->next;
        }   
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
    Print_Data(tail);
    tail = Add_After_End(tail,20,1);
    Print_Data(tail);
    tail = Add_After_End(tail,30,1);
    Print_Data(tail);
    return 0;
}