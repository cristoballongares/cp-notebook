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

  int l,r; cin>>l>>r;
  int n = r - l + 1;
  vi a(n);
  

  if( r == 0 ) {

    cout<<0<<'\n'<<0;
  
    return ;
  
  }



  vi res;
  map<int,int> mp;

  // for(int i = 0 ; i<= r ;i++) mp[i] = -1;

  for(int i = r ; i >= 0 ; i--){

      int x = 0;

      if( i == 0) continue;
      else{
         
          if( mp.count(i)  ) continue;

          for(int j = (32 - __builtin_clz(i) - 1)  ; j>=0 ; j--){

                if( !( (1 << j ) & i) ){

                    x+= ( 1 << j);
                  
                }

            }
          
      mp[i] = x;
      mp[x] = i;
            
      }

      // cout<<i<<':'<<x<<' ';


  }

  ll total = 0;
  for(int i = 0 ; i<= r ; i++){
    total += 1LL * (i | mp[i]);
    res.pb(mp[i]);
  }

  cout<<total<<'\n';

  //  for(int &x:res) cout<<x<<' ';


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
