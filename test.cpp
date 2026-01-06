#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n,m; cin>>n>>m;
    ll i;
    ll sol = -1;
    for(i=1;i<=m;i++) sol+=(n+i)/(i*i);
    cout<<sol<<'\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        solve();
    } 
    return 0;
}