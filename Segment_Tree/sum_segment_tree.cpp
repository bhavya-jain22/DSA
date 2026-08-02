#include<bits/stdc++.h>
using namespace std;

// function declarations --->
vector<int> buildSegmentTree(vector<int>& a);
int segmentUtils(vector<int>& a, vector<int>& tree, int start, int end, int node);
int query(vector<int>& lazy, vector<int>& tree, int& l, int& r, int start, int end, int node);
void pointUpdate(vector<int>& tree, int start, int end, int node, int ind, int val);
void rangeUpdate(vector<int>& lazy, vector<int>& tree, int start, int end, int l, int r, int node, int val);


int main () {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> a(n);
    for(int& x: a) cin >> x;
    vector<int> tree = buildSegmentTree(a);
    vector<int> lazy(4*n, 0);
    
    for(int& x: tree) cout << x << " ";
    cout << endl;


    return 0;
}


// function definitions --->
vector<int> buildSegmentTree(vector<int>& a) {
    int n = a.size();
    vector<int> tree(4*n);
    segmentUtils(a, tree, 0, n-1, 0);
    return tree;
}


int segmentUtils(vector<int>& a, vector<int>& tree, int start, int end, int node) {
    if(start == end) {
        tree[node] = a[start];
        return a[start];
    }

    int mid = start + (end-start)/2;
    tree[node] = segmentUtils(a, tree, start, mid, 2*node+1) +
                 segmentUtils(a, tree, mid+1, end, 2*node+2);

    return tree[node];
}


int query(vector<int>& lazy, vector<int>& tree, const int& l, const int& r, int start, int end, int node) {
    int left = 2*node+1, right = 2*node+2;
    // check for lazy updation
    if(lazy[node]) {
        tree[node] += (end-start+1) * lazy[node];
        if(start!=end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    // complete overlap
    if(l<=start && end<=r) {
        return tree[node];
    }
    // no overlap
    if(r<start || l>end) {
        return 0;
    }
    int mid = start + (end-start)/2;
    return query(lazy, tree, l, r, start, mid, left) +
           query(lazy, tree, l, r, mid+1, end, right);
}


void pointUpdate(vector<int>& tree, int start, int end, int node, int ind, int val) {
    int mid = start + (end-start)/2;
    if(start==end) {
        tree[node] += val;
        return;
    }
    if(ind<=mid) {
        pointUpdate(tree, start, mid, 2*node+1, ind, val);
    }
    else pointUpdate(tree, mid+1, end, 2*node+2, ind, val);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}


void rangeUpdate(vector<int>& lazy, vector<int>& tree, int start, int end, int l, int r, int node, int val) {
    int left = 2*node+1;
    int right = 2*node+2;
    if(lazy[node]) {
        tree[node] += (end-start+1) * lazy[node];
        if(start != end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    // completely overlapping
    if(l<=start && r>=end) {
        tree[node] += (end-start+1) * val;
        if(start != end) {
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }
    // no overlapping
    if(l>end || r<start) {
        return;
    }

    // partial overlapping
    int mid = start + (end-start)/2;
    rangeUpdate(lazy, tree, start, mid, l, r, 2*node+1, val);
    rangeUpdate(lazy, tree, mid+1, end, l, r, 2*node+2, val);
    tree[node] = tree[left] + tree[right];
}

