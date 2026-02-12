#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&s, int val) {
    if(s.empty()) {
        s.push(val);
        return;
    }
    int top_val = s.top();
    s.pop();
    insert(s, val);
    s.push(top_val);
}

void reverse_stack(stack<int>&s) {
    if(s.empty()) return;
    int val = s.top();
    s.pop();
    reverse_stack(s);
    insert(s, val);
}

int main () {

    stack<int> s, temp;
    for(int i=1; i<=5; i++) {
        s.push(i);
        temp.push(i);
    }
    // s.push(2);
    // s.push(3);
    cout << "Original Stack: ";
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    
    cout << "\nReversed stack: ";
    reverse_stack(s);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

return 0;
}