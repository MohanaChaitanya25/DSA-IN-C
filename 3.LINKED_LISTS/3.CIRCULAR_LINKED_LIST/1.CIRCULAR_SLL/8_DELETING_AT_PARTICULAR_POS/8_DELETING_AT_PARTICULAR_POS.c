/// V.CIRCULAR SINGLY LINKED LIST ///

// 8.DELETE AT PARTICULAR POSITION //

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

NODE *Del_Pos(NODE *tail, int pos){
    NODE *ptr = tail->next;
    if(tail == NULL){
        printf("List is already empty\n");
    }
        
    else if(tail->next == tail){
        free(tail);
        tail = NULL;
    }

    else if(pos == 1){
        tail->next = ptr->next;
        free(ptr);
    }

    else{   
        while(pos != 2){
            ptr = ptr->next;
            pos--;
        }

        NODE *ptr1 = ptr->next;
        ptr->next = ptr1->next;

        if(ptr1 == tail){
            tail = ptr;
        }
        free(ptr1);
        ptr = NULL;
        ptr1 = NULL;      
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

    tail = Del_Pos(tail,3);
    Print_Data(tail);

    tail = Del_Pos(tail,1);
    Print_Data(tail);

    // tail = Del_Pos(tail,1);
    // Print_Data(tail);
    
    return 0;
}
