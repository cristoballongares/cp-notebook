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

ll dist(const int a1, const int a2, const int b1, const int b2){

    return hypot ( (a2 - a1), (b2 - b1));

}

void solve(){
    
    int n; cin>>n;

    vector<int> x(n);
    vector<int> y(n);

    for(int &a:x) cin>>a;
    for(int &a:y) cin>>a;

    ll sol = 0;

    
    for(int i = 0; i < x.size() - 1 ; i++){

        ll a1,a2;
        a1 = 1LL * x[i];
        a2 = 1LL * x[i + 1];

        for(int j = 0 ; j < y.size() - 1; j++){

            ll y1,y2;
            y1 = 1LL * y[j];
            y2 = 1LL * y[j + 1];

            ll sol = max(sol, dist(a1,a2,y1,y2));

        }

    }

    cout<<sol;

}

int main(){
    fast;
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}