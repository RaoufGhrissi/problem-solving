// problem link: https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1#
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

struct Node *insert(struct Node *tree, int val) {

    if (tree == NULL) {
        return createNewNode(val);
    }

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

struct Node *convert_str_to_num(char str[]) {
    char *token = strtok(str, " ");

    struct Node *root = NULL;

    char c[2] = {'N'};
    while (token != NULL) {
        if (strcmp(c, token) != 0) {
            int num = atoi(token);
            root = insert(root, num);
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

struct Node* getMin(struct Node* root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;

    // case 1
    if (key<root->data)
        root->left = deleteNode(root->left, key);

    else if (key>root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;

        else if (root->left == NULL)
        {
            struct Node* newRoot = root->right;
            free(root);
            return newRoot;
        }
        else if (root->right == NULL)
        {
            struct Node* newRoot = root->left;
            free(root);
            return newRoot;
        }

        struct Node* mi = getMin(root->right);

        root->data = mi->data;

        root->right = deleteNode(root->right, mi->data);

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

        int x;
        scanf("%d", &x);

        struct Node *root = NULL;

        root = convert_str_to_num(str);

        root = deleteNode(root, x);

        inorder(root);

        printf("\n");
    }

    return 0;
}
  // } Driver Code Ends
