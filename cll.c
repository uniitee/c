// creation of cll with tail node

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void create(){
    struct Node *newNode;
    int data;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else{
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void display(){
    struct Node *temp;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        temp = head;
        do{
            printf("%d -> ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("\n");
    }
}

void insert(){
    struct Node *newNode, *temp;
    int pos, data, i;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &data);
    printf("Enter the position: ");
    scanf("%d", &pos);
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else if(pos == 1){
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    else{
        temp = head;
        for(i = 1; i < pos - 1; i++){
            temp = temp->next;
            if(temp == head){
                printf("Invalid position\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if(temp == tail){
            tail = newNode;
            tail->next = head;
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}