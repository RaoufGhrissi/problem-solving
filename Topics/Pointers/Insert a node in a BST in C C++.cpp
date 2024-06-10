// problem link: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1#
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 1000000

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNewNode(int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert_node(struct Node *tree, int val) {

    if (tree == NULL) {
        return createNewNode(val);
    }

    if (val < tree->data) {
        tree->left = insert_node(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert_node(tree->right, val);
    }

    return tree;
}

struct Node *convert_str_to_num(char str[]) {
    char *token = strtok(str, " ");

    struct Node *root = NULL;

    while (token != NULL) {
        int num = atoi(token);
        if (num != 0) {
            root = insert_node(root, num);
        }
        token = strtok(NULL, " ");
    }

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


 // } Driver Code Ends
// User function Template for C

void insert_key(struct Node *root, int key) {
    if (root == NULL)
    {
        struct Node *node = createNewNode(key);
        root = node;
        return;
    }

    if (root->data == key)
        return;
    else if (root->data < key)
    {
        if (root->right != NULL)
            insert_key(root->right, key);
        else
        {
            struct Node *node = createNewNode(key);
            root->right = node;
        }
    }
    else
    {
        if (root->left != NULL)
            insert_key(root->left, key);
        else
        {
            struct Node *node = createNewNode(key);
            root->left = node;
        }
    }
}

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        while ((getchar()) != '\n')
            ;
        char str[N];
        scanf("%[^\n]s", str);

        struct Node *root = NULL;

        root = convert_str_to_num(str);

        int key;
        scanf("%d", &key);

        insert_key(root, key);

        inorder(root);
        printf("\n");
    }

    return 0;
}
  // } Driver Code Ends
