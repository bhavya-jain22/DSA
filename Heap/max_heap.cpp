#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
    
    

    private:
    
    vector<int> heap;
    

    
    public:
    
    MaxHeap() {

    }

    //inserting elements in the heap
    void push(int val) {
        heap.push_back(val);
        int node = heap.size()-1;
        int parent = -1;
        
        while(node > 0) {
            parent = (node-1)/2;
            if(heap[node] > heap[parent]) {
                swap(heap[node], heap[parent]);
                node = parent;
            }
            else return;
        }    
    }

    //extracting the max from the heap (top element)
    void pop() { 
        if(heap.empty()) return;
        
        //place the last element at top
        int n = heap.size();
        heap[0] = heap[n-1];
        heap.pop_back();
        --n;

        //now, correct the heap
        int node = 0, left, right, largest=0;
        
        while(true) {
            left = node*2 + 1;
            right = node*2 + 2;

            if(left < n && heap[left] > heap[largest]) largest = left;
            if(right < n && heap[right] > heap[largest]) largest = right;

            if(largest != node) {
                swap(heap[largest], heap[node]);
                node = largest;
            }
            else return;
        }
    }

    void display() {
        cout << "Heap array: ";
        for(int& x: heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    
    MaxHeap heap_1;

    int n, ele;
    cout << "Enter the number of element: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> ele;
        heap_1.push(ele);
    }    

    heap_1.display();
    //extract max
    heap_1.pop();
    heap_1.display();

    return 0;
}