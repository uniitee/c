#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the binary search tree
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
// Function to create a new node
struct Node *createNode(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a value into the binary search tree
struct Node *insert(struct Node *root, int value){
    if (root == NULL){
        return createNode(value);
    }
    if (value < root->data){
        root->left = insert(root->left, value);
    }
    else{
        root->right = insert(root->right, value);
    }
    return root;
}
// Function to find the minimum value node in the tree
struct Node *findMin(struct Node *root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}
// Function to delete a value from the binary search tree
struct Node *deleteNode(struct Node *root, int value){
    if (root == NULL){
        return root; // Value not found
    }
    if (value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data){
        root->right = deleteNode(root->right, value);
    }
    else{
        // Node with only one child or no child
        if (root->left == NULL){
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor
        struct Node *temp = findMin(root->right);
        root->data = temp->data;                           // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}
// Inorder traversal
void inorder(struct Node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// Main function
int main(){
    struct Node *root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 9};
    int n = sizeof(values) / sizeof(values[0]);
    // Insert values into the binary search tree
    for (int i = 0; i < n; i++){
        root = insert(root, values[i]);
    }
    // Display initial tree
    printf("Initial Inorder traversal: ");
    inorder(root);
    printf("\n");
    // Ask user for the number to delete
    int valueToDelete;
    printf("Enter a number to delete: ");
    scanf("%d", &valueToDelete);
    // Delete the specified node
    root = deleteNode(root, valueToDelete);
    printf("Inorder traversal after deleting %d: ", valueToDelete);
    inorder(root);
    printf("\n");
    return 0;
}
