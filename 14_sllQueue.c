//  WAP to implement Queue, using Linked List. Implement insertion, deletion and display operations.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL;

void insert(){
    struct Node *newNode, *temp;
    int data;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL){
        front = newNode;
    }
    else{
        temp = front;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(){
    struct Node *temp;
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display(){
    struct Node *temp;
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        temp = front;
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("1. Insert\n");
        printf("2. DeleteNode\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                deleteNode();
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