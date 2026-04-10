#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

typedef struct queue {
    int* arr;
    int front, rear, size;
}queue;

queue* createQueue (int n) {
    queue* q = (queue*) malloc(sizeof(queue));
    q->arr = (int*) malloc (n*sizeof(int));
    q->front = q->rear = -1;
    q->size = n;
    return q;
}

int isEmpty(queue* q) {
    return q->front == -1;
}

void enqueue (queue* q, int x) {
    if(q->rear == (q->size)-1) return;
    if(isEmpty(q)) q->front = 0;
    q->rear++;
    q->arr[q->rear] = x;
}

int dequeue (queue* q) {
    if(isEmpty(q)) return -1;
    int val = q->arr[q->front];
    if(q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else q->front++;
    return val;
}

void addEdge (node* graph[], int src, int dest) {
    node* temp = (node*) malloc (sizeof(node));
    temp->data = dest;
    temp->next = graph[src];
    graph[src] = temp;
}

void bfs(node* graph[], int src, int n) {
    int* vis = (int*) malloc(sizeof(int)*n);
    for(int i=0; i<n; i++) vis[i] = 0;
    queue *q = createQueue(n);
    enqueue(q, src);
    vis[src] = 1;

    printf("BFS: ");
    while(!isEmpty(q)) {
        int x = dequeue(q);
        printf("%d ", x);
        node* traverse = graph[x];
        while(traverse) {
            if (!vis[traverse->data]) {
                //remember to set vis(array) = 1 here
                vis[traverse->data] = 1;
                enqueue(q, traverse->data);                
            }
            traverse = traverse->next;
        }
    }
    printf("\n");
}

int main () {
    int n = 10;
    node* graph[n];
    for(int i=0; i<n; i++) graph[i] = NULL;
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);


    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 1, 4);
    // addEdge(graph, 2, 5);
    
    bfs(graph, 0, n);
return 0;
}


void bbfs (node* graph[], int src, int n) {
    
}