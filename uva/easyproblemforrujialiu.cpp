#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    int n,t;
    while(cin>>n && cin>>t){
    // OJO!
    // The input is terminated by end-of-file (EOF). The size of input file does not exceed 5 MB.


    vector<vector<int>> adj(1e6+1);

    for(int i=1;i<=n;i++){
        int a; cin>>a;
        adj[a].push_back(i);
    }

    while(t--){
        int pos, u; cin>>pos>>u;

        // cout<<adj[u].size()<<'\n';

        if(adj[u].size() == 0 ||pos>adj[u].size()) cout<<0;
        else cout<<adj[u][pos-1];
        cout<<'\n';
    }
    
    }

    return 0;
}