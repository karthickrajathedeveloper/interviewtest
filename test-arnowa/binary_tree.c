#include <stdio.h>
#include <stdlib.h>

// Define a struct for binary tree nodes
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node with a given value
struct Node *newNode(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Calculate the sum of a binary tree
int sumTree(struct Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->data + sumTree(node->left) + sumTree(node->right);
}

// Print a binary tree in inorder traversal
void printTree(struct Node *node) {
    if (node == NULL) {
        return;
    }
    printTree(node->left);
    printf("%d ", node->data);
    printTree(node->right);
}

// Recursively create all possible binary trees from a given array
void buildTrees(int arr[], int start, int end) {
    if (start > end) {
        return;
    }
    // Try each value in the array as the root of the binary tree
    for (int i = start; i <= end; i++) {
        struct Node *root = newNode(arr[i]);
        // Recursively build left and right subtrees
        buildTrees(arr, start, i - 1);
        buildTrees(arr, i + 1, end);
        // Check if the sum of the right subtree is greater than the sum of the left subtree
        int leftSum = sumTree(root->left);
        int rightSum = sumTree(root->right);
        if (rightSum > leftSum) {
            printTree(root);
            printf("\n");
        }
    }
}

int main() {
    // Define the input array
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Call the buildTrees function to create all possible binary trees
    buildTrees(arr, 0, n - 1);
    return 0;
}
