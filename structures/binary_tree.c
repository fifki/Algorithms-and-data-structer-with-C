#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void destroyBST(Node* root) {
    if (root != NULL) {
        destroyBST(root->left);
        destroyBST(root->right);
        free(root);
    }
}

int main(void) {
    char command[100];
    int value, index;
    Node* root = NULL;

    fscanf(stdin, "%99s", command);
    while (strcmp(command, "bye") != 0) {
        if (strcmp(command, "element") == 0) {
            fscanf(stdin, "%99s", command);
            value = strtol(command, NULL, 10);
            Node* foundNode = search(root, value);
            if (foundNode != NULL) {
                printf("Element %d found in the BST.\n", value);
            } else {
                printf("Element %d not found in the BST.\n", value);
            }
        }
        else if (strcmp(command, "replace") == 0) {
            fscanf(stdin, "%99s", command);
            index = strtol(command, NULL, 10);
            fscanf(stdin, "%99s", command);
            value = strtol(command, NULL, 10);
            // Replace operation is not supported in a BST
            printf("Replace operation is not supported in a BST.\n");
        }
        else if (strcmp(command, "insert") == 0) {
            fscanf(stdin, "%99s", command);
            value = strtol(command, NULL, 10);
            root = insert(root, value);
            printf("Element %d inserted into the BST.\n", value);
        }
        else if (strcmp(command, "delete") == 0) {
            fscanf(stdin, "%99s", command);
            value = strtol(command, NULL, 10);
            root = deleteNode(root, value);
            printf("Element %d deleted from the BST.\n", value);
        }
        else if (strcmp(command, "size") == 0) {
            // BST size is not directly supported
            printf("BST size: Not implemented.\n");
        }
        else if (strcmp(command, "print") == 0) {
            printf("Inorder traversal of the BST: ");
            inorderTraversal(root);
            printf("\n");
        }
        else if (strcmp(command, "destroy") == 0) {
            // Free memory allocated for the binary search tree
            destroyBST(root);
            printf("BST destroyed.\n");
        }
        fscanf(stdin, "%99s", command);
    }

    // Free memory allocated for the binary search tree
    destroyBST(root);
    return 0;
}/*
insert 10
insert 20
insert 30
element 20
delete 20
print
destroy
*/
