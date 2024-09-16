//WAP to increment the data part of each node in a linked list by 10. and display the modified list.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(){
    struct Node *newNode, *temp;
    int data;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(){
    struct Node *temp;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        temp = head;
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void increment(){
    struct Node *temp;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        temp = head;
        while(temp != NULL){
            temp->data += 10;
            temp = temp->next;
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Increment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insert();
                    break;
            case 2: display();
                    break;
            case 3: increment();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}