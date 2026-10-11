#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin>>n;

  vector<pair<ll,ll>> sch;

  for(int i =0; i < n ; i++){

    string x,y; cin>>x>>y;
    string h = " ";
    h+=x[0];
    h+=x[1];
    
    string m = "";
    m+=x[3];
    m+=x[4];

    string h1 = " ";
    h1+=y[0];
    h1+=y[1];
    
    string m1 = "";
    m1+=y[3];
    m1+=y[4];


    ll H = stoll(h);
    ll M = stoll(m);

    ll H1 = stoll(h1);
    ll M1 = stoll(m1);

    ll s = H*60+M;
    ll e = H1*60+M1;

    if( e<=s) e+= 24*60;

    sch.push_back({s,e});

  }

  sort(sch.begin(),sch.end(), [](pair<int,int> a, pair<int,int> b){

      return a.second < b.second;

  });

  ll mn = sch[0].second;
  ll count = 1;

  for(int i = 1 ; i < sch.size(); i++){

      ll x = sch[i].first;
      ll y = sch[i].second;

      if( x >= mn){
        count++;
        mn = y;
      }

  }

  cout<<count;

  return 0;

}

