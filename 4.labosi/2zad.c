#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, char data) {
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

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    char ime_prezime[] = "LukaAracic";
    int i;
    for (i = 0; ime_prezime[i] != '\0'; i++) {
        root = insertNode(root, ime_prezime[i]);
    }

    printf("Stablo: %s\n", ime_prezime);
    printf("Preorder obilazak: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder obilazak: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder obilazak: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
