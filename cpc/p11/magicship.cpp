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

// -----------------
// --------------------------

int moveY(const char x){

  switch(x){
    case 'D': return -1;
    case 'U': return 1;
  }

  return 0;
  
}

int moveX(const char x){

  switch(x){
    case 'L': return -1;
    case 'R': return 1;
  }

  return 0;
  
}

bool check(const ll x, const ll y, const ll x2, const ll y2, const ll d, const vector<pii> moves){

  
  ll vueltas = floor( d / (moves.size() -1)  ); // C
  ll xF = vueltas * moves.back().fi;
  ll yF = vueltas * moves.back().se;


  ll pos = ( d ) % (sz(moves) - 1); // C



  xF += ( moves[pos].fi + x);
  yF += ( moves[pos].se + y);




  ll dx = abs( xF - x2 );
  ll dy = abs( yF - y2);

  //cout<<"XF: "<<xF<<"yF: "<<yF<<'\n';
  //cout<<"dx: "<<dx<<" dy: "<<dy<<'\n';


  ll total = dx + dy;

  return ( total <= d);

  // total es igual a d o total es par y menor igual a d

}

void solve(){
  
    int x,y; cin>>x>>y;
    int x2,y2; cin>>x2>>y2;

    int n; cin>>n;
    string s; cin>>s;
  
    vector<pair<int,int>> moves;
    moves.pb( make_pair( 0,0 ) );

    for(char &c:s){

      if( c == 'L' || c == 'R') {

          moves.push_back( make_pair( moveX(c), 0 ) );

      } else {

          moves.push_back( make_pair( 0, moveY(c) ) );

      }

      if(moves.size() > 1){

          moves[moves.size() - 1].first += moves[moves.size() - 2].first;
          moves[moves.size() - 1].second+= moves[moves.size() - 2].second;


      }

    }
  

    ll l = 1, r =  1e15;

    ll sol = 0;

   // cout<<check(x,y,x2,y2,5,moves);
    //cout<<"\n\n";

    while( l<= r ){

      ll mid = l + ( r - l ) / 2;

      if(check(x,y,x2,y2,mid,moves)){
                
        sol = mid;
        r = mid - 1;
      
      } else l = mid + 1;
      

    }

    cout<<(sol == 0 ? -1 : sol);

  

  
}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
  //  cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}
