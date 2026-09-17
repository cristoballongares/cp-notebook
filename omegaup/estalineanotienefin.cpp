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

int op(int a, int b, char o){

  switch(o){
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
  }
  return 0;

}

void solve(){

  int t; cin>>t;
  if( t & 1){
    cout<<"Pistas invalidas"; return ;
  }

  int l=-1,r=1e9+6;

  t/=2;

  int l1,r1;

  while(t--){

    int a,b;
    char x; 
    cin>>a>>x>>b;

    int c,d;
    char y;
    cin>>c>>y>>d;

    l1 = op(a,b,x);
    r1 = op(c,d,y);

  

    if(l1 >= l && l1 <= r) l = l1;
    if( r1 <= r && r1 >= l ) r = r1;

  }

  cout<<l;

}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1;
    while(t--){solve();cout<<'\n';}

    return 0;
}
