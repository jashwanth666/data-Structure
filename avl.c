
#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == NULL)
        return -1;
    return node->height;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
}

// Function to perform a right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to balance a node
Node* balanceNode(Node* node) {
    int balance = getHeight(node->left) - getHeight(node->right);

    // Left Heavy Case
    if (balance > 1) {
        // Left-Left Case
        if (getHeight(node->left->left) >= getHeight(node->left->right))
            return rotateRight(node);
        // Left-Right Case
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    // Right Heavy Case
    if (balance < -1) {
        // Right-Right Case
        if (getHeight(node->right->right) >= getHeight(node->right->left))
            return rotateLeft(node);
        // Right-Left Case
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
    // Balanced node
    return node;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

// Function to insert a key into the AVL tree
Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys are not allowed

    updateHeight(root);
    return balanceNode(root);
}

// Function to find the node with the minimum value
Node* findMin(Node* node) {
    if (node->left == NULL)
        return node;
    return findMin(node->left);
}

// Function to delete a key from the AVL tree
Node* delete(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    updateHeight(root);
    return balanceNode(root);
}

// Function to search for a key in the AVL tree
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Function to display the AVL tree in-order
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display In-order\n");
        printf("5. Exit\n");
        int choice, key;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key %d found!\n", key);
                else
                    printf("Key %d not found.\n", key);
                break;
            case 4:
                printf("In-order traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}