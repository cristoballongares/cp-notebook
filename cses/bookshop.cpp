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
 
void solve(){
  
  int n,x; cin>>n>>x;
  vi prices(n);
  vi pages(n);

  for(int &a:prices) cin>>a;
  for(int &a:pages) cin>>a;

  vector<vi> dp(n+1,vi(x+1));

  for(int i = 0 ;i <= x ; i++) dp[0][i] = 0;
  
  //dp[i][b] = max num de paginas si usamos los primeros i libros con total de hasta b

  int sol = 0;

  for(int i = 1 ; i<=n ; i++){

      int cost = prices[ i - 1];
      int pag = pages[ i - 1];

      for(int b = 0 ; b <= x ; b++){

          dp[i][b] = dp[i-1][b];

          // lo podemos comprar 
          if( b >= cost ) {
            
            dp[i][b] = max(
                dp[i][b],
                dp[i-1][b - cost] + pag
            );

          }

          sol = max(sol,dp[i][b]);
      
      }

  }

  cout<<sol;


}
 
int main(){
    fast;
    
#ifndef ONLINE_JUDGE
  //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
///    cin>>t;
    while(t--){solve();cout<<'\n';}
 
    return 0;
}

