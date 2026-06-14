#include<bits/stdc++.h>

using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<int> &vis, vector<vector<int>> &comp){

    comp.back().push_back(u);
    vis[u] = true;

    for(int v: adj[u]){

        if(!vis[v]) dfs(v, adj, vis, comp);

    }

}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    // freopen("g.txt", "r", stdin);

    int n,m; cin>>n>>m;

    int t = m;

    vector<vector<int>> adj(n);

    while(t--){

        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);


    }

    vector<vector<int>> comp;
    vector<int> vis(n);

    int i;

    for(i = 0; i < n; i++){

        if(!vis[i]){

            comp.push_back({});
            dfs(i, adj, vis, comp);

        }

    }

    // ordenamos comp decrecientemente en funcion al size
    sort(comp.begin(), comp.end(), [](vector<int> &a, vector<int> &b){
        return a.size() > b.size();
    });
    

    int G = comp[0].size();
    
    vector<int> fila;

    for(vector<int> &a:comp) for(int &u:a) fila.push_back(u);

    int izq = 0;
    int k = ( G <= n /2 ? n / 2 : n - G);
    int der = (G <= n/2 ? n /2 : G);
    cout<<k<<'\n';
    while(k--){

        cout<<fila[izq]<<' '<<fila[der]<<'\n';
        izq++; der++;

    }


    return 0;

}

// mostrar comp
    // for(vector<int> &a:comp){
    //     if(a.size() >= 2){
    //         for(int &u:a){
            
    //             cout<<u<<' ';

    //         }
    //         cout<<'\t';
    //     }
    // }
