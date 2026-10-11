#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n,c; cin>>n>>c;
  ll sum = 0;

  for(int i = 0 ; i < n ; i++){

    ll x; cin>>x;
    sum+=x;
    
  }
  if(sum > c) {
    cout<<"NO "<< (sum - c);

  }
  cout<<"YES " << ( c - sum);


  return 0;

}
