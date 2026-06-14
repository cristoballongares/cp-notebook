#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

const int INF = INT_MAX;

void solve(){

    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());

    int t = m;

    while(m--){

        int a,b; cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    vector<int> dist(n+1,INF);
    queue<int> q; q.push(1); dist[1]=1;
    vector<int> parent(n+1,-1);

    while(!q.empty()){

        int v = q.front(); q.pop();

        for(int &u:adj[v]){

            if(dist[u]!=INF) continue;

            dist[u] = dist[v]+1;
            parent[u] = v;
            q.push(u);

        }
    }

    if(dist[n]==INF){
        cout<<"IMPOSSIBLE"; return ;
    }

    vector<int> path;
    int curr = n;
    
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout<<path.size()<<'\n';
    for (int u:path) {
        cout<<u<<' ';
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    t = 1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}