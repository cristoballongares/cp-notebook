#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin>>n;
  vector<ll> a(n);

  ll sum = 0;

  for(ll &x:a){
    cin>>x;
    sum+=x;
  }
 
  if(n == 1){

    cout<<0; return 0;

  }

  // quedara uno con mas
  if(sum % n != 0){
    cout<<-1; return 0;
  }

  ll q = sum / n;

  ll sol = 0;

  for(int i = 0 ; i < n - 1; i++){

    // volviendo a la logica anterior, la que borre:p
  
    if(a[i] < q){
      cout<<-1; return 0;
    }

    ll dif = a[i] - q;
    a[i+1]+=dif;
    sol+=dif;


  }

  cout<<sol;

  return 0;

}
