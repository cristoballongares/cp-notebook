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

    vi a(n);
    vi lge(n);

    for(int &x:a) cin>>x;

    int i,mx = a[0];

    lge[0] = 1;

    int sol = mx;

    for(i = 1 ; i < n ; i++){

      if ( a[i] > mx){
        lge[i] = i + 1;
        mx = a[i];
        // Pero si es <
      } else if(a[i] < mx ) lge[i] = (i + 1) - lge[i - 1] ;
      else lge[i] = lge[i-1];  
    
      


      cout<<"A =  "<<a[i]<< 'x' << lge[i] <<" : " << a[i] * lge[i]<<'\n';
  
      sol = max(sol, a[i] * lge[i]);
    

    }

    cout<<sol;
    //for(int &x:lge) cout<<x<<' ';


}

int main(){
    fast;
    
#ifdef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
  //  cin>>t;
    while(t--){solve();cout<<'\n';}

    
    

    return 0;
}
