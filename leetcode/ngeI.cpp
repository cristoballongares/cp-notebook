#include<bits/stdc++.h>

using namespace std;

void showStack(stack<int> s){
    stack<int> t = s;
    while(!t.empty()){
        cout<<t.top()<<' ';
        t.pop();
    }
    cout<<'\n';

}

vector<int> nextGreaterElement(vector<int> &a, vector<int> &b){

    stack<int> s;
    unordered_map<int, int> um;
    int i;
    bool ok = 0;
    for(i=b.size()-1;i>=0;i--){
        int x = b[i];
        ok = 1;
        while(!s.empty() && x>=s.top()){
            // cout<<x<<" >= "<<s.top()<<'\n';
            s.pop();
            if(!s.empty()&&x<s.top()){
                ok = 0;
                um[x] = s.top();
            }
        }

        if(s.empty()) um[x] = -1;
        if(ok && !s.empty() && s.top()>=x){
            um[x] = s.top();
        }
        s.push(x);
        // showStack(s);

    }

    vector<int> sol;

    for(int &x: a) sol.push_back(um[x]);

    return sol;


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m; cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);

    for(int &x:a) cin>>x;

    for(int &x:b) cin>>x;

    vector<int> sol = nextGreaterElement(a,b);

    for(int &x: sol) cout<<x<<' ';


}