/// V.CIRCULAR SINGLY LINKED LIST ///

// 5.CREATING COMPLETE CIRCULAR SINGLY LINKED LIST //

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

NODE *Create_list(NODE *tail){
    int i, n, data;
    printf("Enter the number of nodes of the linked list: ");
    scanf("%d", &n);

    // if(n==0)
    //     return tail;
    
    for (size_t i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &data);
        tail = Add_At_End(tail, data);
    }

    return tail;
}

void Print_Data(NODE *tail){
    if(tail == NULL){
        printf("Linked List is Empty\n");
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
    tail = Create_list(tail);
    Print_Data(tail);
    return 0;
}
