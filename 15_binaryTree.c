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
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}
// Preorder traversal
void preorder(struct Node *root){
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder traversal
void postorder(struct Node *root){
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
// Inorder traversal
void inorder(struct Node *root){
    if (root != NULL)
    {
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
    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }
    // Display traversals
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}