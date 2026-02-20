#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin>>n;
    vector<unordered_set<int>> adj(n+1);

    int t = n-1;
    while(t--){

        int u,v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);

        if(adj[u].size()==(n-1) || adj[v].size()==(n-1)){ // El primero que cumpla, bai
            cout<<"Yes"; return 0;
        }
    }

    cout<<"No";


    return 0;
}