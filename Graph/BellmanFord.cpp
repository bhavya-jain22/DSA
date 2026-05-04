#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int n;
    vector<vector<pair<int, int>>> G;

    Graph(int n) {
        this->n = n;
        G.resize(n);
    }

    void addEdge(int u, int v, int w) {
        G[u].push_back({w, v});
        // G[v].push_back({w, u});
    }

    void printGraph() {
        cout << "\n---GRAPH---\n";
        for(int i=0; i<n; i++) {
            cout << i << "-> ";
            for(int j=0; j<G[i].size(); j++) {
                cout << "(" << G[i][j].second << "," << G[i][j].first << ")\t";
            }
            cout << endl;
        }
    }

    vector<int> BellmanFord(int src) {
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        bool updated = false;
        // relax edges (n-1) times
        for(int i=0; i<n-1; i++) {
            updated = false;
            for(int u=0; u<n; u++) {
                for(auto& [wt, v]: G[u]) {
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                        updated = true;
                    }
                }
            }
            if(!updated) return dist;
        }

        // neg cycle detection ->>
        for(int u=0; u<n; u++) {
            for(auto& [wt, v]: G[u]) {
                if(dist[u] != INT_MAX && dist[u]+wt < dist[v]) {
                    return vector<int>();
                }
            }
        }
        return dist;
    }
};


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, edges, u, v, w;
    cin >> n >> edges;
    Graph g(n);
    while(edges--) {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    vector<int> dist = g.BellmanFord(0);
    if(dist.empty()) {
        cout << "Negative cycle exists\n";
    }
    else {
        cout << "Dist: ";
        for(int& x: dist) x==INT_MAX? cout << "INF " : cout << x << " ";
        cout << endl;
    }
}