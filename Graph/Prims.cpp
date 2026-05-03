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

    pair<int, Graph> Prims() {
        int mstWeight = 0;
        Graph mst(n);

        vector<bool> vis(n, false);
        priority_queue<
            // {wt, parent, node}
            tuple<int, int, int>,
            vector<tuple<int, int, int>>, 
            greater<>
        > pq;

        pq.push({0, -1, 0});

        while(!pq.empty()) {
            auto [wt, parent, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;
            vis[node] = true;

            if(parent != -1) {
                mstWeight += wt;
                mst.addEdge(parent, node, wt);
            }


            for(auto [w, v]: G[node]) {
                if(!vis[v]) pq.push({w, node, v});
            }
        }
        return {mstWeight, mst};
    }
};


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, edges, u, v, w;
    // cout << "Enter the number of vertices & edges: ";
    cin >> n >> edges;

    Graph g(n);

    while(edges--) {
        // cout << "Enter (u, v, w): ";
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.printGraph();

    auto [wt, mst] = g.Prims();

    cout << "\nMST Weight: " << wt << endl;
    mst.printGraph();

}

