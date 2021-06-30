/// V.CIRCULAR SINGLY LINKED LIST ///

// 4.ADD NODE AFTER POSITION //

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

NODE *Add_After_Pos(NODE *tail, int data, int pos){
    NODE *temp = Create_Node(data);
    NODE *ptr = tail->next;

    if(tail == NULL){
        printf("List is Empty!\n");
    }
    
    else{
        while(pos > 1){
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next = temp;

        if(ptr == tail){
            tail = tail->next;
        }
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
    NODE *tail = NULL;
    tail = Add_At_End(tail,10);
    tail = Add_At_End(tail,20);
    tail = Add_At_End(tail,30);
    tail = Add_At_End(tail,40);

    tail = Add_After_Pos(tail,50,4);
    tail = Add_After_Pos(tail,60,5);
    tail = Add_After_Pos(tail,70,6);
    Print_Data(tail);
    return 0;
}
