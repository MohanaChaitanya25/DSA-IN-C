/// V.CIRCULAR SINGLY LINKED LIST ///

// 9.TOTAL NODES //

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

NODE *Add_At_End(NODE *tail, int data){
    NODE *temp = Create_Node(data);

    if(tail == NULL){
        tail = temp;
    }
    else{
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    return tail;
}


void Print_Data(NODE *tail){
    if(tail == NULL){
        printf("List is empty!\n");
    }
    else{
        NODE *ptr = tail->next;
        do{
            printf("%d ",ptr->data);
            ptr = ptr->next;
        } while (ptr != tail->next);
        printf("\n");
    }
}

void Total_Nodes(NODE *tail){
    if(tail==NULL){
        printf("List is empty!\n");
    }
    else{
        int c=0;
        NODE *ptr = tail->next;
        do
        {
            ptr = ptr->next;
            c++;
        } while (ptr != tail->next);
        printf("Total Nodes : %d\n",c);
    }
    
}

int main()
{
    NODE *tail = NULL;
    tail = Add_At_End(tail,10);
    tail = Add_At_End(tail,20);
    tail = Add_At_End(tail,30);
    tail = Add_At_End(tail,40);

    Print_Data(tail);

    Total_Nodes(tail);
    return 0;
}