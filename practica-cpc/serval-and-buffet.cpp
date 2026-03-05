#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    int n, k; cin>>n>>k;
    vector<ll> d(n+1);
    for(int i=1; i<=n ;i++) cin>>d[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    
    int free = 0, i;
    for(i=n;i>=1;i--){
        
        free++;
        
        if(free >= k+1){
            pq.push(d[i]);
            free-=(k+1);
        }  else if(!pq.empty() && pq.top()<d[i]){
            pq.pop();
            pq.push(d[i]);
        }

    }

    ll sol=0;

    while(!pq.empty()){
        sol+=pq.top(); pq.pop();
    }

    cout<<sol;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}