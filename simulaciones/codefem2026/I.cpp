// combinatoria
// resolvi un problema bastante similar en la icpc mx 2026 primera fecha :p
//
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 122333221;
const ll MAXN = 1e5;

// usamos inverso modular con fermat
//
ll fact[MAXN+1];

ll binpow(ll a, ll b){

  ll ans = 1;

  while(b){

    if(b&1) ans = ans * a % MOD;

    a = a*a % MOD;
    b/=2;

  }

  return ans;

}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  fact[0] = 1; // :p
               //
  for(int i = 1; i <= MAXN; i++) fact[i] = fact[i-1] * i % MOD;

  int T; cin>>T;

  while(T--){

    int n,k;cin>>n>>k;
    ll ans = fact[n];

    ans = ans * binpow(fact[k], MOD - 2) % MOD;
    ans = ans * binpow(fact[n-k], MOD - 2) % MOD;

    cout<<ans<<'\n';

    // que sea lo que dios quiera

  }




  return 0;

}
