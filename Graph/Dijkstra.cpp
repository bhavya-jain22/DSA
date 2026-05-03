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
        G[v].push_back({w, u});
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

    vector<int> Dijkstra(int src) {
        vector<int> dist(n, INT_MAX);
        priority_queue<
            // {dist, node}
            pair<int, int>, 
            vector<pair<int, int>>,
            greater<>
        >pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if(d>dist[node]) continue;

            for(auto [wt, v]: G[node]) {
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
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

    vector<int> dist = g.Dijkstra(0);

    cout << "Dist: ";
    for(int& x: dist) cout << x << " ";
    cout << endl;
}