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

struct info{

  int x,y,w;

};

void solve(){
   

  int n,m; cin>>n>>m;
  vector<vector<char>> grid(n,vector<char>(m));

  for( auto &x:grid) for(auto &y:x) cin>>y;

  vi dx = {1,-1,0,0};
  vi dy = {0,0,1,-1};
  vector<char> moves = {'v','^','>','<'};
  deque<info> q;

  q.push_back({0,0,0});

  vector<vi> dp(n,vi(m,1e9));

  dp[0][0] = 0;

  while(!q.empty()){
  
    info mo = q.front();
    q.pop_front();

    int x = mo.x;
    int y = mo.y;
    int w = mo.w;

    for( int i = 0 ; i < 4 ; i++){

      int X = x + dx[i];
      int Y = y + dy[i];

        if(X >= 0 && X < n && Y >= 0 && Y < m){
            int W = (moves[i] == grid[x][y] ? 0 : 1);
            if (dp[x][y] + W < dp[X][Y]) {
                dp[X][Y] = dp[x][y] + W;
                if (W == 0) q.push_front({X, Y, dp[X][Y]});
                else        q.push_back({X, Y, dp[X][Y]});
            }
        }
    }
  }

  cout<<dp[n-1][m-1];




}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
    //cin>>t;

    while(t--){solve();cout<<'\n';}

    return 0;
}
