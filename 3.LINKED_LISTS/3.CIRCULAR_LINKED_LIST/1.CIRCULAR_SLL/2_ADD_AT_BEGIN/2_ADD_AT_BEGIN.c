/// V.CIRCULAR SINGLY LINKED LIST ///

// 2.ADDING NODE AT BEGIN //

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *Create_Node(int data){
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = data;
    ptr->next = ptr;
    return ptr;
}

NODE *Add_At_Beg(NODE *tail, int data){
    NODE *temp = Create_Node(data);

    if(tail == NULL){
        tail = temp;
    }
    else{
        temp->next = tail->next;
        tail->next = temp;      
    }
    return tail;
}

void Print_Data(NODE *tail){
    if(tail==NULL)
        printf("Linked List is Empty\n");
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
    int data = 10;
    NODE *tail = NULL;
    // tail = Add_At_Beg(tail,10);
    // tail = Add_At_Beg(tail,20);
    // tail = Add_At_Beg(tail,30);
    Print_Data(tail);
    return 0;
}
