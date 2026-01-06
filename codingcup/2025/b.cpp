#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
int solve(vector<int>&nodos, int n, vector<vector<int>>&adj){
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i=0;i<nodos.size();i++) {
        int u = nodos[i];
        dist[u] = i+1; 
        pq.push({i+1, u});
    }

    int sol = 0;

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d>dist[u]) continue;
        
        for(int v:adj[u]) {
            if(dist[u]+1 < dist[v]) {
                dist[v] = dist[u]+1;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dist[i]==INF) return INF;
        sol = max(sol,dist[i]);
    }
    return sol;

}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; 
    ll m; 
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> pares, imp; 
    int sol = m; 
    for(ll i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);    
        adj[v].push_back(u);
    }

    for(int k=1;k<=n;k++){
        if(!(k%2)) pares.push_back(k);
        else imp.push_back(k);
    }

    int p,i;
    p = solve(pares,n,adj);
    i = solve(imp, n, adj);

    int ans = min(p,i);
    if(ans==INF) cout<<-1;
    else cout<<ans;
    

    return 0;
}