// https://vjudge.net/problem/USACO-916
#include<bits/stdc++.h>

using namespace std;

vector<int> costo;
vector<vector<int>> adj;
unordered_map<int, bool> vis;
 
void check(const int &u){

    int k;
    bool ok = 0;
    for(k=1;k<=4;k++){ // estrategia greedy: siempre probar asignarle costo 1 con todos los nodos 
        ok = 1;
        for(int &v: adj[u]){
            // Verificamos, algun nodo vecino tiene ese costo k?
            if(k==costo[v]){
                ok=false; break;
            }  
        }
        if(ok){ // Es posible asignarle costo k a nodo u
            costo[u]=k;
            return ;
        } // Si no es posible, probar con el siguiente k hasta que lo sea
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    costo.resize(n+1);

    for( int&x:costo) x=1e9;

    int i;
    
    for(i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto &x: adj){
        sort(x.begin(),x.end());
    }

    int j=0;

    string s;
 
    int k;

    for(i=1;i<=n;i++){
        int count = 0;
        // cout<<i<<" : ";

        // for(j=0;j<adj[i].size();j++) cout<<adj[i][j]<<' ';
        // cout<<'\n';
        check(i);
    }

    for(i=1;i<=n;i++) cout<<costo[i];

    return 0;
}