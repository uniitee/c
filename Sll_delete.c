#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the node after a given value
void deleteNodeAfterValue(struct Node** head, int value) {
    struct Node* temp = *head;

    // Traverse the list to find the node with the given value
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If the node is found and it has a next node, delete the next node
    if (temp != NULL && temp->next != NULL) {
        struct Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
        printf("Node deleted after value %d\n", value);
    } else {
        printf("No node found after value %d\n", value);
    }
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original List: ");
    printList(head);

    int value;
    printf("Enter the value after which you want to delete the node: ");
    scanf("%d", &value);

    deleteNodeAfterValue(&head, value);

    printf("Updated List: ");
    printList(head);

    return 0;
}
