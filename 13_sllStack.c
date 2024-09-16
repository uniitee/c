// WAP to implement stack using singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(){
    struct Node *newNode;
    int data;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop(){
    struct Node *temp;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        temp = top;
        top = top->next;
        printf("Popped element is %d\n", temp->data);
        free(temp);
    }
}

void display(){
    struct Node *temp;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        temp = top;
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}