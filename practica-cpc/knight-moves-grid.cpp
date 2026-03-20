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

vector<int> dx = {-2,-2,2,2,1,-1,1,-1};
vector<int> dy = {1,-1,1,-1,2,2,-2,-2};

bool isValid(int x, int y, vector<vector<int>> &tab){

    int n = tab.size();

    return((x>=0 && x<n && y>=0 && y<n) && tab[x][y]==-1);

}


void solve(){

    int n; cin>>n;
    vector<vi> tab(n, vector<int>(n,-1));

    queue<pii> q;

    tab[0][0] = 0;
    q.push({0,0});

    while(!q.empty()){

        auto u = q.front();
        q.pop();

        // cout<<u.first<<' '<<u.second<<'\n';

        //Buscamos los vecinos de u, los cuales son los posibles movimientos para esa casilla
        for(int k = 0; k<8; k++){

            int x = u.first, y = u.second;

            int X = x + dx[k], Y = y + dy[k];

            if(isValid(X,Y,tab)){

                tab[X][Y] = tab[x][y] + 1;
                q.push({X,Y});

            }

        }

    }

    for(vector<int> &v: tab){

        for(int &x:v){

            cout<<x<<' ';
        }

        cout<<'\n';

    }
    
}

int main(){
    fast;
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}