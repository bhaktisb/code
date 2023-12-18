#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the mirror image of a binary tree
void mirrorImage(struct Node* root) {
    if (root == NULL) {
        return;
    } else {
        struct Node* temp;

        // Swap left and right children
        mirrorImage(root->left);
        mirrorImage(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

// Function to calculate the height of a binary tree
int treeHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

// Function to display leaf nodes
void displayLeafNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return;
    }
    if (root->left != NULL) {
        displayLeafNodes(root->left);
    }
    if (root->right != NULL) {
        displayLeafNodes(root->right);
    }
}

// Function to count the number of nodes in a binary tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return (countNodes(root->left) + countNodes(root->right) + 1);
    }
}

// Function to deallocate memory of the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Mirror Image\n");
        printf("6. Height of Tree\n");
        printf("7. Display Leaf Nodes\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Mirror Image of the Tree\n");
                mirrorImage(root);
                break;
            case 6:
                printf("Height of the Tree: %d\n", treeHeight(root));
                break;
            case 7:
                printf("Leaf Nodes: ");
                displayLeafNodes(root);
                printf("\n");
                break;
            case 8:
                printf("Number of Nodes: %d\n", countNodes(root));
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 9);

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;
}
