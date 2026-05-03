#include<bits/stdc++.h>
using namespace std;

class W_Graph {
    protected:
    //(weight, dest)
    vector<vector<pair<int, int>>>G;
    int n;
    
    public:

    W_Graph(int n) {
        this->n = n;
        G.resize(n);
    }

    void addEdge(int u, int v, int w) {
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }

    void printGraph() {
        cout << "\n---GRAPH---\n";
        for(int i=0; i<G.size(); i++) {
            // source
            cout << i << "-> ";
            for(int j=0; j<G[i].size(); j++) {
                // (dest, weight)
                cout << "(" << G[i][j].second << ", " << G[i][j].first << ")\t";
            }
            cout << endl;
        }
    }
};

class DSU : public W_Graph{
    private:
    vector<int>parent, size;

    public:

    DSU(int n): W_Graph(n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int x) {
        if(x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(size[px] <= size[py]) {
            parent[py] = px;
            size[px] += size[py];
        }
        else {
            parent[px] = py;
            size[py] += size[px];
        }
    }

    W_Graph Kruskals() {
        // (w, u, v)
        int MSTweight = 0;
        set<pair<int, pair<int, int>>> edges;
        int w, u, v;
        W_Graph g(n);

        for(int i=0; i<G.size(); i++) {
            u = i;
            for(int j=0; j<G[i].size(); j++) {
                w = G[i][j].first, v = G[i][j].second;
                if(u<v) edges.insert({w, {u, v}});
            }
        }

        // sort(edges.begin(), edges.end());

        int required_edge = n-1;
        auto it = edges.begin();
        while(required_edge && it!=edges.end()) {
            w = it->first;
            u = (it->second).first;
            v = (it->second).second;
            // doesn't make cycle
            if(find(u) != find(v)) {
                MSTweight += w;
                Union(u, v);
                g.addEdge(u, v, w);
                required_edge--;
            }
            advance(it, 1);
        }
        cout << "\nMST Weight: " << MSTweight << "\n";
        return g;
    }
};


int main () {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n, edges, u, v, w;
    cout << "Enter the number of vertices & edges: ";
    cin >> n >> edges;

    DSU d(n);

    while(edges--) {
        cout << "Enter (u, v, w): ";
        cin >> u >> v >> w;
        d.addEdge(u, v, w);
    }

    d.printGraph();

    W_Graph g = d.Kruskals();
    g.printGraph();
    
}