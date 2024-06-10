// problem link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    vector<int> v1;
    vector<int> v2;
    
    void dfs(Node* root, vector<int> &v, int n1, int n2)
    {
        v.push_back(root->data);
    
        if (root->data == n1)
        {
            v1=v;
        }
        else if (root->data == n2)
        {
            v2=v;
        }
        
        if (root->right != NULL)
            dfs(root->right, v, n1, n2);
        
        if (root->left != NULL)
            dfs(root->left, v, n1, n2);
        
        auto it = find(v.begin(), v.end(), root->data);
        v.erase(it,it+1);
        return;
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        vector<int> v;
        dfs(root,v,n1,n2);
        
        int s = min(v1.size(),v2.size());
            
        if (v1[s-1] == v2[s-1])
        {
            root->data = v1[s-1];
            return root;
        }
        
        for (int i=1 ; i<s; i++)
        {
            if (v1[i]!=v2[i])
            {
                root->data = v1[i-1];
                return root;
            }
        }
        
        return new Node;
    }
};

// { Driver Code Starts.

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}
  // } Driver Code Ends