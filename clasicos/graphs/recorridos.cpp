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

void bfs(int &x, vector<vi> &adj){

    int n = adj.size();

    queue<int> q;
    q.push(x);
    vector<bool> vis(n+1,false);
    vector<int> d(n+1,0), p(n+1,-1);

    vis[x] = true;
    d[x] = 0;
    p[x] = -1;

    while(!q.empty()){

        int u = q.front();
        q.pop();
        

        for(int &v: adj[u]){

            if(!vis[v]){

                vis[v] = true;
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);

            }

        }

    }

    int nodoDestino; cin>>nodoDestino;

    vector<int> path;

    for(int i = nodoDestino; i!=-1; i = p[i]){

        path.push_back(i);

    }

    reverse(path.begin(), path.end());
    cout<<"Camino: "<<'\n';
    for(int &x: path) cout<<x<<' ';

    cout<<"\nCosto"<< d[nodoDestino];


}




void solve(){
    
}

int main(){
    fast;
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}