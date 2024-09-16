//  WAP to count the number of times an item is present in a linked list

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
        for(i=1; i<pos-1; i++){
            if(temp != NULL){
                temp = temp->next;
            }
        }
        if(temp != NULL){
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else{
            printf("Position not found\n");
        }
    }
}

void count(){
    struct Node *temp;
    int item, count = 0;
    printf("Enter the item to be counted: ");
    scanf("%d", &item);
    temp = head;
    while(temp != NULL){
        if(temp->data == item){
            count++;
        }
        temp = temp->next;
    }
    printf("The item %d is present %d times in the list\n", item, count);
}

int main(){
    int ch;
    while(1){
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert();
                    break;
            case 4: count();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}