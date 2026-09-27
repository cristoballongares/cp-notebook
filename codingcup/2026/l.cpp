#include <bits/stdc++.h>
using namespace std;

// tipos
using ll  = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using ull = unsigned ll;

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
 
  char t;
  string x;
  cin>>t>>x;

  if(t == 'D'){

    map<int,char> m;
    m[10] = 'A';
    m[11] = 'B';
    m[12] = 'C';
    m[13] = 'D';
    m[14] = 'E';
    m[15] = 'F';
    m[16] = 'G';
    m[17] = 'H';
    m[18] = 'I';
    m[19] = 'J';

    ll num = stoll(x);
    string res = "";

    while(num > 0 ){

      ll r = num %20;

      if(r<=9) res+= ('0'+r);
      else res+=m[r];

      num/=20;


    }

    reverse(all(res));

    cout<<x<<' '<<res;
    

    return ;
  } 

  // maya a decimal
  
  map<char,ll> m;
  m['A'] = 10;
  m['B'] = 11;
  m['C'] = 12;
  m['D'] = 13;
  m['E'] = 14;
  m['F'] = 15;
  m['G'] = 16;
  m['H'] = 17;
  m['I'] = 18;
  m['J'] = 19;


  vll v_pow(9,1);
  
  ll r = 1;

  for(ll i = 1 ; i <= 8 ; i++){
  
    v_pow[i] = r*20;
    r*=20;

    
  }

  ll i = x.size()-1;
  ll res = 0;

  //cout<<i<<'\n';
  //cout<<v_pow[i]<<'\n';

  for(char &c:x){
  

    //cout<<i<<' '<<res<<'\n';

    if(isdigit(c)){

        res+= (( (c - '0')) *1LL * v_pow[i] );


    } else {

        res+= ( (m[c]*1LL) * v_pow[i]);

    }

    i--;

  }

cout<<res<<' '<<x;



}

int main(){
    fast;
    
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // Descomenta esta linea si queremos que la salida vaya a un archivo
#endif
    
    int t=1; 
    cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}
