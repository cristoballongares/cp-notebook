// https://vjudge.net/problem/UVA-10020/origin
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    int m; cin>>m;
    int a,b;
    bool ok = 0;

    priority_queue<pair<int,int>> pq;

    while(cin>>a>>b){
        if(!a&&!b) break;
        if(a<=0 && b>=m){
            cout<<1<<'\n'<<a<<' '<<b; 
            ok = 1;
        }
        pq.push(make_pair(a,b));
    }
    if(ok) return ;

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        cout<<p.first<<' '<<p.second<<'\n';
        pq.pop();
    }


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