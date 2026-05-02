#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
string s;

void generate(int prev, int n) {
    if(n==0) {
        ans.push_back(s);
        return;
    }
    if(prev==0) {
        s.push_back('0');
        generate(0, n-1);
        s.pop_back();

        s.push_back('1');
        generate(1, n-1);
        s.pop_back();
    }
    else {
        s.push_back('0');
        generate(0, n-1);
        s.pop_back();
    }
}

int main () {
    int n;
    cout << "Enter n: ";
    cin >> n;
    generate(0, n);
    for(string& s: ans) cout << s << endl;
return 0;
}