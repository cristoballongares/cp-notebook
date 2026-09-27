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

struct movie{
  int year;
  string name;
  int rating;
};

void solve(){
  
  int n; cin>>n;
  vector<movie> movies(n);
  
  for(auto &x:movies){

    cin>>x.year>>x.name>>x.rating;

  }

  sort(all(movies), [&](movie a, movie b){

      if(a.year!=b.year) return a.year <= b.year;

      return a.rating < b.rating;

  });


  vi dp(n,1);

  for(int i = 0; i <n ;i++){
    for(int j = 0 ; j < i ; j++){
      if( movies[j].year <= movies[i].year && movies[j].rating < movies[i].rating && movies[j].name!=movies[i].name)
        dp[i] = max(dp[i], dp[j]+1);
    
    }
  }

  cout<<*max_element(all(dp));

}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
 //   cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}
