#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    
    int n; cin>>n;

    priority_queue<ll> pq;
    vector<ll> a(n);
    for(ll &x:a)cin>>x;
    
    ll i;

    ll sum=0, count=0;

    for(i=0;i<n;i++){

        ll x = a[i];
        if(x<0) pq.push(-x);

        sum+=x;
        count++;

        while(sum<0 && !pq.empty()){ // me arrepiento, vomito la que me quito mas vida
                sum+=pq.top();
                pq.pop();
                count--;
        }

    }

    cout<<count;
    



}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}