// AIM: To implement Binary tree and display the contents using non-recursive preorder, postorder and inorder traversal techniques.

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for implementing non-recursive traversal
struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

// Function to create a new node in the binary tree
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

// Stack operations
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Function for non-recursive inorder traversal
void inorderTraversal(struct Node* root) {
    struct Stack* stack = createStack(100);
    struct Node* current = root;

    while (!isEmpty(stack) || current != NULL) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = pop(stack);
        printf("%d ", current->data);

        // Visit the right subtree
        current = current->right;
    }
}

// Function for non-recursive preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(stack);
        printf("%d ", node->data);

        // Push right and then left child to stack
        if (node->right)
            push(stack, node->right);
        if (node->left)
            push(stack, node->left);
    }
}

// Function for non-recursive postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack1 = createStack(100);
    struct Stack* stack2 = createStack(100);

    // Push root to the first stack
    push(stack1, root);

    // Process nodes and store them in the second stack
    while (!isEmpty(stack1)) {
        struct Node* node = pop(stack1);
        push(stack2, node);

        // Push left and right children of the popped node to the first stack
        if (node->left)
            push(stack1, node->left);
        if (node->right)
            push(stack1, node->right);
    }

    // Print all nodes in the second stack
    while (!isEmpty(stack2)) {
        struct Node* node = pop(stack2);
        printf("%d ", node->data);
    }
}

// Main function to test the traversals
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
