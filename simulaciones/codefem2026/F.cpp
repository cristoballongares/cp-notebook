#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

  ll n,b; cin>>n>>b;
  vector<ll> a(n);

  for(auto &x:a)cin>>x;


  ll sum = 0;
  ll sol = 0;
  //aaa!!, era esoo!(?)
  ll i = 0, j = 0;

  while(j < n){

    if(sum + a[j] <= b ){

      sum+=a[j];
      sol = max(sol, (j-i+1)); 
      j++;


    } else {
   
      if(i < j){
        sum-=a[i];
        i++;
      } else {
        i++;
        j++;
      }
    
    }
    

  }

  cout<<sol;

  return 0;

}
