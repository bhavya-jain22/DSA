#include<bits/stdc++.h>
using namespace std;

class Graph {
    protected:

        int n;
        vector<vector<pair<int, int>>> G;

    public:

        Graph (int n) {
            this->n = n+1;
            G.resize(n+1);
        }
    
        void addEdge (int u, int v, int w) {
            G[u].push_back({w, v});
            G[v].push_back({w, u});
        }

        void printGraph() {
            for(int i=0; i<n; i++) {
                cout << i << " -> ";
                for(auto& [wt, v]: G[i]) cout << "(" << v << "," << wt<< ")\t ";
                cout << endl;
            }
        }


        void bfs(int src) {
            // bfs gives us a path that contains minimum number of nodes
            // ATTENTION! --> it doesn't give us the shortest path,
            // suppose there exists two path between 's' and 'd', 
            // one of them has a distance of 20km but has only *1 node* in between
            // and another one has a distance of 5km and has *3 nodes* in between
            // still the bfs traversal technique will give us the *first path(with minimum number of nodes, irrespective of the weight(distance))*
            vector<int>visited(n, 0);
            queue<int> q;
            q.push(src);
            int u;
            cout << "\nUsing BFS, You can go from the source("<<src<< ") to these nodes/vertices: ";
            while(!q.empty()) {
                u = q.front();
                cout << u << " ";
                //visited[x] = 1 represents that the 'x' node is being processed(in queue)
                visited[u] = 1;
                for(auto& [wt, v]: G[u]) {
                    if(visited[v] == 0) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
                q.pop();
                //visited[x] = 2 represents that the 'x' node is processed(popped out of queue)
                visited[u] = 2;
            }
            cout << endl;
        }


        void dfs(int src) {
            // DFS just give me any one path
            cout << "\nUsing DFS, You can go from sourse(" << src << ") to these nodes/vertices: ";
            vector<int> visited(n, 0);
            dfs_helper(visited, src);
            cout << endl;
        }

        void dfs_helper(vector<int>& visited, int src) {
            // visited[x] = 1, represents that the 'x' node is being processed(pushed into the stack)
            visited[src] = 1;
            cout << src << " ";
            for(auto& [wt, v]: G[src]) {
                if(visited[v] == 0) dfs_helper(visited, v);
            }
            // visited[x] = 2, represents that the 'x' node has been processed
            // (poped out of the stack (here returning from the stack(because of recursion)))
            visited[src] = 2;
        }
};
