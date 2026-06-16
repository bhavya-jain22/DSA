#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    private:
    int n;
    vector<int> heap;

    public:
    MinHeap() {
        n = 0;
    }

    void push(int val) {
        heap.push_back(val);
        n++;
        if(n==1) return;
        int node = n-1, parent = (n-1)/2;

        while(node>0) {
            parent = (node-1)/2;
            if(heap[node] < heap[parent]) {
                swap(heap[node], heap[parent]);
                node = parent;
            }
            else return;
        }        
    }

    int pop() {
        heap[0] = heap[n-1];
        heap.pop_back();
        n--;

        int l=0, r=0, mn=0, p=0;

        while(true) {
            l = 2*p + 1;
            r = 2*p + 2;

            if(l<n && heap[l] < heap[mn]) mn = l;
            if(r<n && heap[r] < heap[mn]) mn = r;

            if(mn != p) {
                swap(heap[mn], heap[p]);
                p = mn;
            }
            else return heap[0];
        }
    }

    int top() {
        return heap[0];
    }

    void display() {
        for(auto& x: heap) cout << x << " ";
        cout << endl;
    }
};

int main () {
    MinHeap h = MinHeap();
    int arr[] = {9, 4, 24, 1, 7};
    for(auto& x: arr) h.push(x);
    h.display();
}