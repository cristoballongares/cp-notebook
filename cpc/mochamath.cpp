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
    vector<int> a(n); for(int &x:a)cin>>x;

    // hallar el minimo maximo posible en la secuencia
    // a_{l + i} = a_{l + i} & a_{r - i}

    // Aplicar AND a un numero nos resulta en dos casos para dicho numero
    // o se hace mas pequeño o permanece igual.
    // y si hacemos esto 1e4 veces?

    // Si todos son iguales...
    vi b=a; unique(all(b));
    if(b.size() == 1){
        cout<<b[0];
        return ;
    }
        int x = a[0];
        for(int j = 1 ; j < n ; j++) x&=a[j];

    cout<<x;
}

int main(){
    fast;
    
    int t=1; 
    cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}