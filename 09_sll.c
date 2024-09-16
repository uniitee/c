// WAP to implement Linear linked list, showing operations like creation, display, insertion, deletion and searching.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(){
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
    }
    else if(pos == 1){
        newNode->next = head;
        head = newNode;
    }
    else{
        temp = head;
        for(i = 0; i < pos - 2; i++){
            temp = temp->next;
            if(temp == NULL){
                printf("Invalid position\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(){
    struct Node *temp, *prev;
    int pos, i;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        printf("Enter the position: ");
        scanf("%d", &pos);
        temp = head;
        if(pos == 1){
            head = temp->next;
            free(temp);
        }
        else{
            for(i = 0; i < pos - 1; i++){
                prev = temp;
                temp = temp->next;
                if(temp == NULL){
                    printf("Invalid position\n");
                    return;
                }
            }
            prev->next = temp->next;
            free(temp);
        }
    }
}

void search(){
    struct Node *temp;
    int data, pos = 0;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        printf("Enter the data to be searched: ");
        scanf("%d", &data);
        temp = head;
        while(temp != NULL){
            pos++;
            if(temp->data == data){
                printf("Element found at position %d\n", pos);
                return;
            }
            temp = temp->next;
        }
        printf("Element not found\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert();
                    break;
            case 4: deleteNode();
                    break;
            case 5: search();
                    break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}