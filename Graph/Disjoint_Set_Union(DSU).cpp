#include<bits/stdc++.h>
#include"undirected_graph.cpp"

using namespace std;

class Disjoint_Set {
    private:
    int n;
    vector<int>size;
    vector<int>parent;

    public:
    Disjoint_Set(int n) {
        this->n = n;
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
        print_parent();
        print_size();
    }

    void print_parent() {
        cout << "Parent: ";
        for(const int& x: parent) cout << x << " ";
        cout << "\n";
    }

    void print_size() {
        cout << "Size: ";
        for(const int& x: size) cout << x << " ";
        cout << "\n";
    }

    // finds the ultimate parent (origin) or representative element
    int find(int i) {
        if(i>n) return -1; // out of bound
        if(i==parent[i]) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }

    void Union (int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv]; 
        }
    }
};


int main() {
    int n, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> edges;
    cout << "\n---BEFORE---\n";
    Disjoint_Set d1(n);
    Graph g(n);
    cout << endl;
    
    int u, v, w;
    while(edges--) {
        cout << "Enter (u, v, w): ";
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
        d1.Union(u, v);
    }

    // cout << "Enter the vertices to check if they belong to the same origin or not: ";
    // cin >> u >> v;
    // if(d1.find(u) == d1.find(v)) cout << "Yes! They belong to the same origin\n";
    // else cout << "No, They belong to different origin\n";

    cout << "\n---AFTER---\n";
    d1.print_parent();
    d1.print_size();

    return 0;
}