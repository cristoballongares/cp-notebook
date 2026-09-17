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
 
  int n; cin>>n;

  unordered_map<int,string> um;
  unordered_map<int,int> um2;
  int last = 0;

  while(n--){
    string x;cin>>x;
    
    int sum = 0;
    for(char &c:x){
      sum += (c - '0');
    }

    um[sum] = x;
    um2[sum] = um2[sum]+1;

  }

  vector<pii> v;

  for(const auto& p: um2){
    v.pb({p.first,p.second}); 
  }

  sort(all(v), [&](pii a, pii b){

    if(a.second!=b.second) return a.second>b.second;

    return um[a.first] < um[b.first];

  });

  for( const auto& p: v){
    cout<<um[p.first]<<' '<<p.second<<'\n';
  }

}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
//    cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}
