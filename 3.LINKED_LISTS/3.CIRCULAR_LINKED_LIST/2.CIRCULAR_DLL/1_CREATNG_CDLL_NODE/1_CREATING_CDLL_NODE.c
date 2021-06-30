/// VI.CIRCULAR DOUBLY LINKED LIST ///

// 1.CREATING NODE //

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
    ptr->next = ptr;
    return ptr;
}

int main(){
    int data = 45;
    NODE *tail = Create_Node(data);

    printf("%d\n", tail->data);
    return 0;
}