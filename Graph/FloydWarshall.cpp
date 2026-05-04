#include<bits/stdc++.h>
#include"directed_graph.cpp"
using namespace std;

class FloydWarshall : public D_Graph {
    public:
    vector<vector<int>> dist;

    // create the object
    FloydWarshall(int n) : D_Graph(n) {
        buildDist();
        AllPairShortestDist();
    }

    // copies the data of the object 'g' of class Graph
    // into the suboject of 'f'
    FloydWarshall(const D_Graph& g) : D_Graph(g) {
        buildDist();
        AllPairShortestDist();
    }

    void buildDist() {
        dist.resize(n, vector<int>(n, INT_MAX));
        // distance to itself is 0
        for(int i=0; i<n; i++) dist[i][i] = 0;

        // mark the distances
        for(int u=0; u<n; u++) {
            for(auto& [wt, v]: G[u]) {
                dist[u][v] = wt;
            }
        }
    }

    void AllPairShortestDist() {
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        long long d = dist[i][k] + dist[k][j];
                        if(d < dist[i][j]) dist[i][j] = d;
                    }
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(dist[i][i] < 0) {
                cout << "\nNEGATIVE CYCLE EXISTS !!\n\n";
                return;
            }
        }
    }

    void printDist() {
        for(auto& v: dist) {
            for(auto& x: v) x==INT_MAX? cout << "INF " : cout << x << " ";
            cout << endl;
        }
    }
};

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, edges, u, v, w;
    cin >> n >> edges;
    D_Graph g(n);

    while(edges--) {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    FloydWarshall f(g);
    f.printDist();
}

