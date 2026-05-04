#include<bits/stdc++.h>
using namespace std;

class D_Graph {
    private:

    void dfs_utils(vector<bool>& vis, int u) {
        vis[u] = true;
        cout << u << " ";
        for(auto& [wt, v]: G[u]) {
            if(!vis[v]) {
                dfs_utils(vis, v);
            }
        }
    }

    public:
    int n;
    vector<vector<pair<int, int>>> G;

    D_Graph(int n) {
        this->n = n;
        G.resize(n);
    }

    void addEdge(int u, int v, int w) {
        G[u].push_back({w, v});
    }

    void printGraph() {
        for(int u=0; u<n; u++) {
            cout << u << "-> ";
            for(auto& [wt, v]: G[u]) {
                cout << "(" << v << "," << wt<< ")\t";
            }
            cout << endl;
        }
    }

    void dfs(int u) {
        cout << "\n\nDFS: ";
        vector<bool> vis(n, false);
        dfs_utils(vis, u);
        cout << endl;
    }

    void bfs(int u) {
        cout << "\n\nBFS: ";
        vector<bool>vis(n, false);
        queue<int> q;

        q.push(u);
        vis[u] = true;

        while(!q.empty()) {
            u = q.front();
            q.pop();

            cout << u << " ";

            for(auto& [wt, v]: G[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};