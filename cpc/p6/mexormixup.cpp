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

int xor_acumulado( int a){
  int res = a % 4;
  if(res == 0) return a;
  if(res==1) return 1;
  if(res == 2 ) return a+1;
  if( res == 3) return 0;
}

void solve(){
    
    int a,b; cin>>a>>b;

    int axor = xor_acumulado(a - 1); // 1 ^ 2 ^ 3 ^ ... ^ (a-1)
    
    if(axor == b) {
      cout<<a; return ;
    } else if( (b ^ axor) == a) cout<< ( a +2);
    else cout<< ( a + 1);
}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
    cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}
