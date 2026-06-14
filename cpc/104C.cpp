// https://codeforces.com/problemset/problem/104/C
#include <bits/stdc++.h>
using namespace std;

// tipos
using ll  = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;

// fast io
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

// loops
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rof(i,a,b) for(int i=(a);i>=(b);i--)

// utileria
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second

// mates
#define MOD 1000000007LL
#define INF 1e18

// debugging

#ifdef LOCAL
    #define dbg(x) cerr << #x << " = " << x << "\n"
    #define dbgv(v) cerr << #v << " = "; for(auto x : v) cerr << x << " "; cerr << "\n"
    #define dbgm(m) cerr << #m << ":\n"; for(auto row : m){ for(auto x : row) cerr << x << " "; cerr << "\n";}
#else
    #define dbg(x)
    #define dbgv(v)
    #define dbgm(m)
#endif

// -------------------------------------------

enum {UNVISITED = -1, VISITED = -2};

vi dfs_num;

void dfs(int u, vector<vi>&adj, int &count, int &edges){
    // cout<<u<<' ';
    dfs_num[u] = VISITED;
    count++;

    for(auto &v: adj[u]){
        
        if(dfs_num[v] == UNVISITED){
            edges++;
             dfs(v, adj, count,edges);

        } else edges++;

    }

}

void solve(){
    
    int n,m; cin>>n>>m;
    dfs_num.assign(n+1,UNVISITED);

    vector<vi> adj(n+1);


    int dummy = m;
    while(dummy--){

        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int numCC = 0, nodes = 0, edges = 0;


    // exploramos todos los nodos 
    for(int u = 1; u <= n ; u++){

        if(dfs_num[u] == UNVISITED){
        
            // cout<<"CC "<<++numCC<<": ";

            numCC++;

            dfs(u,adj,nodes,edges);

            // cout<<"\n";

        }   

    }

            if(numCC == 1 && edges/2 == nodes){

                cout<<"FHTAGN!"; return;

            } else{
                
                cout<<"NO"; return;

            }            



}

int main(){
    fast;
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}