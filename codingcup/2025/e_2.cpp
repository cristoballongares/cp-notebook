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
 
  string x; cin>>x;

  unordered_map<ll,ll> um;

  ll actual = 5;
  ll contador = 1;
  ll ia = 1;

  for(ll sum = 5 ; sum <= 1e12 ; sum+=( ia )){

      //cout<<"sum: "<<sum<<' '<<"IA: "<<ia<<' ';
      um[sum] = contador;
      //cout<<"um: "<<um[sum]<<'\n';
      ia+=2;
      contador++;

  }

  string num = "";
  for(ll i = 0 ; i < sz(x) - 1 ; i++) num+=x[i];

  ll a = stoll(num) * 26 * 1ll;
  ll b = ( x[x.size()-1] - 'a' + 1); 

  ll r = a + b;

  //cout<<a<<' '<<b<<' '<<r<<'\n';
  
  if(um[r] == 0) cout<<-1;
  else cout<<um[r];
  


}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
//    cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}
