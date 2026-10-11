#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// O((n+m+q)logn);

struct BIT{

  int n;
  vector<ll> bit;

  BIT(int n) : n(n), bit(n+2,0) {}

  void add( int i, ll x ){

    i++;
    while( i<=n+1){
      bit[i] +=x;
      i += i & -i;
    }

  }

  ll query(int i ){

    i++;
    ll sum = 0;

    while(i>0){

      sum += bit[i];
      i -= i & -i;

    }

    return sum;

  }

  void rangeAdd(int l, int r, ll x){

    add(l,x);
    add(r+1,-x);

  }

};

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;cin>>n>>m;

  unordered_map<string,int> pos;

  // necesitamos guardaer nom persona y su posicion
  for(int i = 0 ; i < n ; i++){

    string nm; cin>>nm;
    pos[nm] = i;

  }

  // producto y precio
  unordered_map<string,ll> price;

  for(int i = 0 ; i < m ; i++){

    string p;
    ll pr;

    cin>>p>>pr;
    price[p] = pr;

  }

  BIT bit(n);

  int q;
  cin>>q;
  while(q--){

    int t;
    cin>>t;

    if( t == 1){
      string person, product;
      cin>>person>>product;

      int p = pos[person];
      ll cost = price[product];

      bit.rangeAdd( p, p,cost);

    } else if( t == 2){

      int l,r; string p; cin>>l>>r>>p;

      ll cost = price[p];

      if( l <= r) bit.rangeAdd(l,r,cost);
      else{
        bit.rangeAdd(l, n-1, cost);
        bit.rangeAdd(0,r,cost);
      }

    } else {

      string p; cin>>p;
      cout<<bit.query(pos[p])<<'\n';

    }


  }

  return 0;
}
