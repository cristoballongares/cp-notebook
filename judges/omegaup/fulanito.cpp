#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
void solve(vector<ll> &a, const ll &t){
    ll l = 1, r = a.size()-1;
    ll res = 0, sol = 0;
    while(l<=r){
        int m = (l+r)/2;
        ll x = a[m];
        if(x<=t){
            res = x;
            sol = m;
            l=m+1;
        } else r = m-1;
    }
    cout<<sol<<' '<<t-res<<'\n';


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    vector<ll> a(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    
    while(n--){
        ll t; cin>>t;
        solve(a,t);
    }


    return 0;
}