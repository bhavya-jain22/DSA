#include<bits/stdc++.h>
using namespace std;

// funtion declaration --->
vector<int> build_segment_tree(vector<int>& a);
void segment_utils(vector<int>& a, vector<int>& tree, int start, int end, int node);
template<typename T> void printVector(const vector<T>& a);
int query(vector<int>& lazy, vector<int>& tree, int& l, int& r, int start, int end, int node);
void pointUpdate(vector<int>& tree, int start, int end, int node, int ind, int val);
void rangeUpdate(vector<int>& lazy, vector<int>& tree, int l, int r, int start, int end, int node, int val);

int main () {

    int n;
    // cout << "Enter the number of element: ";
    // cin >> n;
    vector<int> a = {8, 2, 5, 1, 4, 5, 3, 9, 6, 10};
    n = a.size();

    // vector<int> a(n);
    // for(int& x: a) cin >> x;
    
    vector<int> tree = build_segment_tree(a);
    vector<int> lazy(4*n, 0);
    printVector(a);
    printVector(tree);

    int l, r;

    cout << "Enter query(l, r): ";
    cin >> l >> r;
    cout << l<<"-"<<r<<": " << query(lazy, tree, l, r, 0, n-1, 0) << endl;

    cout << "Enter query(l, r): ";
    cin >> l >> r;
    cout << l<<"-"<<r<<": " << query(lazy, tree, l, r, 0, n-1, 0) << endl;
    return 0;
}


// function definitions --->

vector<int> build_segment_tree(vector<int>& a) {
    int n = a.size();
    vector<int> tree(n*4, 0);
    segment_utils(a, tree, 0, n-1, 0);
    return tree;
}

void segment_utils(vector<int>& a, vector<int>& tree, int start, int end, int node) {
    // leaf node
    if(start == end) {
        tree[node] = a[start];
        return;
    }

    int mid = start + (end-start)/2, left = 2*node+1, right = 2*node+2;
    segment_utils(a, tree, start, mid, left);
    segment_utils(a, tree, mid+1, end, right);

    tree[node] = max(tree[left], tree[right]);
}


template <typename T> void printVector(const vector<T>& a) {
    for(const T& x: a) {
        cout << x << " ";
    }
    cout << endl;
}

int query(vector<int>& lazy, vector<int>& tree, const int& l, const int& r, int start, int end, int node) {
    int left = 2*node+1, right = 2*node+2;
    if(lazy[node]) {
        tree[node] += lazy[node];
        if(start!=end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    // complete overlapping
    if(l<=start && r>=end) {
        return tree[node];
    }
    // no overlapping
    if(r<start || l>end) {
        return INT_MIN;
    }
    // partial overlapping
    int mid = start + (end-start)/2;
    return max(query(lazy, tree, l, r, start, mid, left),
               query(lazy, tree, l, r, mid+1, end, right));
}


void pointUpdate(vector<int>& tree, int start, int end, int node, int ind, int val) {
    if(start == end) {
        tree[node] += val;
        return;
    }

    int mid = start + (end-start)/2;
    if(ind<=mid) {
        pointUpdate(tree, start, mid, 2*node+1, ind, val);
    }
    else pointUpdate(tree, mid+1, end, 2*node+2, ind, val);

    tree[node] = max(tree[2*node+1], tree[2*node+2]);
}


void rangeUpdate(vector<int>& lazy, vector<int>& tree, int l, int r, int start, int end, int node, int val) {
    int left = 2*node+1, right = 2*node+2;
    if(lazy[node]) {
        tree[node] += lazy[node];
        if(start!=end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    // completely overlapping
    if(l<=start && end<=r) {
        tree[node] += val;
        if(start!=end) {
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }
    
    // no overlapping
    if(l>end || r<start) return;

    // partial overlapping
    int mid = start + (end-start)/2;
    rangeUpdate(lazy, tree, l, r, start, mid, left, val);
    rangeUpdate(lazy, tree, l, r, mid+1, end, right, val);
    tree[node] = max(tree[left], tree[right]);
}