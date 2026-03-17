#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:

        int n;
        vector<vector<int>> G;

    public:

        Graph (int n) {
            this->n = n;
            G.resize(n);
        }
    
        void addEdge (int a, int b) {
            G[a].push_back(b);
            G[b].push_back(a);
        }

        void printGraph() {
            for(int i=0; i<n; i++) {
                cout << i << " -> ";
                for(int d: G[i]) cout << d << " ";
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
            int s;
            cout << "\nUsing BFS, You can go from the source("<<src<< ") to these nodes/vertices: ";
            while(!q.empty()) {
                s = q.front();
                cout << s << " ";
                //visited[x] = 1 represents that the 'x' node is being processed(in queue)
                visited[s] = 1;
                for(int d: G[s]) {
                    if(visited[d] == 0) {
                        visited[d] = 1;
                        q.push(d);
                    }
                }
                q.pop();
                //visited[x] = 2 represents that the 'x' node is processed(popped out of queue)
                visited[s] = 2;
            }
            cout << endl;
        }


        void rec_dfs(int src) {
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
            for(int d: G[src]) {
                if(visited[d] == 0) dfs_helper(visited, d);
            }
            // visited[x] = 2, represents that the 'x' node has been processed
            // (poped out of the stack (here returning from the stack(because of recursion)))
            visited[src] = 2;
        }


        void dfs(int src) {
            stack<int> st;
            st.push(src);
            vector<int>visited(n, 0);
            visited[src] = 1;
            while(!st.empty()) {
                int s = st.top();
                for(int d: G[s]) {
                    st.push(d);
                    visited[d] = 1;
                }
            }
        }
};
