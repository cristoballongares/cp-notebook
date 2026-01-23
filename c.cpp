#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int &x:a)cin>>x;

    sort(a.begin(),a.end());
    
    if(n==1){
        cout<<1;
        return ;
    }

    auto last = unique(a.begin(),a.end());
    a.erase(last,a.end());
    
    n = a.size();
    
    int count=1;
    int sol=1;
    for(int i=0;i<n-1;i++){
        if(a[i]+1==a[i+1]) count++;
        else count=1;
        sol=max(count,sol);
    }

    cout<<sol;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t; cin>>t;

    while(t--){
        solve();
        cout<<'\n';
    }

    return 0;
}