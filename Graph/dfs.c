#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int data;
    struct node* next;
}node;

void addEdge(node* graph[], int src, int dest) {
    node* temp = (node*) malloc (sizeof(node));
    temp->data = dest;
    temp->next = graph[src];
    graph[src] = temp;
}

void dfsHelper(node* graph[], int src, int vis[]) {
    vis[src] = 1;
    // print src (not trav->data)
    printf("%d ", src);
    node* trav = graph[src];
    while (trav) {
        if(!vis[trav->data]) {
            dfsHelper(graph, trav->data, vis);
        }
        trav = trav->next;
    }
}

void dfs (node* graph[], int src, int n) {
    //remember to make this visited array in dfs function
    int vis[n];
    for(int i=0; i<n; i++) vis[i] = 0;
    printf("DFS: ");
    // use separate function dfs helper
    dfsHelper(graph, src, vis);
    printf("\n");
}

int main () {
    int n = 10;
    node* graph[n];
    //remember to initialize graph to NULL
    for(int i=0; i<n; i++) {
        graph[i] = NULL;
    }
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);
    dfs(graph, 0, n);
    return 0;
}