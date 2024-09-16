// WAP to implement doubley linked list, showing operations like creation, display, insertion, deletion and searching.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
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
        newNode->prev = temp;
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
            printf("%d ", temp->data); // Remove the arrow
            temp = temp->next;
            if (temp != NULL) {
                printf("-> ");
            }
        }
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
    newNode->prev = NULL;
    newNode->next = NULL;
    if (pos == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1; i++) {
        if (temp->next != NULL) {
            temp = temp->next;
        } else {
            printf("Position not found\n");
            return;
        }
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void deleteNode(){
    struct Node *temp;
    int pos, i;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Enter the position: ");
    scanf("%d", &pos);
    temp = head;
    if(pos == 1){
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            head = NULL;
        }
        free(temp);
        return;
    }
    for(i = 1; i < pos; i++){
        if(temp->next != NULL){
            temp = temp->next;
        } else {
            printf("Position not found\n");
            return;
        }
    }
    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
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
        printf("4. DeleteNode\n");
        printf("5. Search\n");
        printf("6. Exit\n");
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
                deleteNode();
                break;
            case 5:
                search();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}