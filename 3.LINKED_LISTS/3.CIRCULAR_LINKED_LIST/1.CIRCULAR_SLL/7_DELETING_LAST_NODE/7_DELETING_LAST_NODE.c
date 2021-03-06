/// V.CIRCULAR SINGLY LINKED LIST ///

// 7.DELETING LAST NODE //

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

NODE *Del_Last_Node(NODE *tail){
    if(tail == NULL){
        printf("List is already empty\n");
    }
        
    else if(tail->next == tail){
        free(tail);
        tail = NULL;
    }
    else{
        NODE *ptr = tail->next;
        while(ptr->next != tail){
            ptr = ptr->next;
        }
        ptr->next = tail->next;
        free(tail);
        tail = ptr;
        ptr = NULL;
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

int main()
{
    NODE *tail = NULL;
    tail = Add_At_End(tail,10);
    tail = Add_At_End(tail,20);
    tail = Add_At_End(tail,30);
    // tail = Add_At_End(tail,40);

    Print_Data(tail);

    tail = Del_Last_Node(tail);
    Print_Data(tail);

    tail = Del_Last_Node(tail);
    Print_Data(tail);
    return 0;
}
