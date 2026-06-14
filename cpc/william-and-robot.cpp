#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    
    priority_queue<int, vector<int>, greater<int>> mn;
    ll ans = 0;
    
    // procesamos en pares
    for(int k=0; k<n/2; k++){
        mn.push(a[2*k]);
        mn.push(a[2*k+1]);
        
        // sacamos al peor xD
        mn.pop();
    }
    
    // sumamos los mejores
    while(!mn.empty()){
        ans+= mn.top();
        mn.pop();
    }
    
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1; 
    // cin>>t;
    while(t--){ solve(); cout<<'\n'; }
    return 0;
}