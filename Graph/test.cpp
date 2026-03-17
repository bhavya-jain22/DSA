#include"graph.cpp"

int main () {
    int n;
    cout << "Enter the value of the maximum node: ";
    cin >> n;
    Graph A(n);

    A.addEdge(0, 1);
    A.addEdge(0, 3);
    A.addEdge(1, 2);
    A.addEdge(1, 4);
    // A.addEdge(3, 2);

    A.printGraph();

    A.bfs(0);
    A.bfs(1);
    A.bfs(2);
    A.bfs(3);
    A.bfs(4);
    cout << endl;

    A.rec_dfs(0);
    A.rec_dfs(1);
    cout << endl;
    
    return 0;
}
