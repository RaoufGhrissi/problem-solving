// problem link : https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1#
//Initial Template for C
#include <stdio.h>
#include <stdlib.h>

// A linked list (LL) node to store a queue entry
struct QNode {
	int key;
	struct QNode* next;
};

// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue {
	struct QNode *front, *rear;
};

// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty queue
struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

// The function to add a key k to q
void push(struct Queue* q, int k);

// Function to remove a key from given queue q
void pop(struct Queue* q);

// Driver Program to test anove functions
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
	struct Queue* q = createQueue();
	int Q;
    scanf("%d",&Q);
    while(Q--){
    int QueryType=0;
    scanf("%d",&QueryType);
    if(QueryType==1)
    {
        int a;
        scanf("%d",&a);
        push(q, a);
    }else if(QueryType==2){
        if(q->front!=NULL)
        printf("%d ", q->front->key);
        else
        printf("-1 ");
        pop(q);
        }
    }
	printf("\n");
}
return 0;
}

// } Driver Code Ends


//User function Template for C


// The function to add a key k to q
void push(struct Queue* q, int k)
{
    struct QNode* nodeToInsert = newNode(k);

    if (q->rear == NULL)
    {
        q->rear = nodeToInsert;
        q->front = nodeToInsert;
        return;
    }

    q->rear->next = nodeToInsert;
    q->rear = nodeToInsert;
}

// Function to remove a key from given queue q
void pop(struct Queue* q)
{
    if (q == NULL || q->front == NULL)
        return;

    struct QNode *oldFront = q->front;
    q->front = oldFront->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(oldFront);
}
