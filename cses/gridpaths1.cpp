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

bool check(int x, int y , int n){

  return x < n && y < n;

}

void solve(){

  vi dx = {1,0};
  vi dy = {0,1};

  int n; cin>>n;
  vector<vector<char>> grid(n,vector<char>(n));

  for(int i = 0 ; i < n ; i++){
    for(int j = 0; j < n ; j++) cin>>grid[i][j];
  }

  if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
    cout<<0; return ;
  }

  vector<vi> dp(n,vi(n,0));

  dp[0][0] = 1;

  for(int i = 0 ; i < n; i++){

      for(int j = 0 ; j < n ; j++){

        for(int m = 0 ; m < 2 ; m++){

            int X = i + dx[m];
            int Y = j + dy[m];

            if(check(X,Y,n) && grid[X][Y] != '*'){

                dp[X][Y] = (dp[i][j] + dp[X][Y]) % MOD;

            }          

        }       
    
      }
  
  }

  cout<<dp[ n -1 ][ n - 1];





}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
    //cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}
