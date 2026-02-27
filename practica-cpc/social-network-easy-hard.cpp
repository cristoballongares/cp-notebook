#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    int n,k; cin>>n>>k;
    deque<int> dq;
    vector<bool> flag(1e9+1,false);
    int t = n;
    
    while(t--){

        int x; cin>>x;
        
        if(flag[x]) continue;
        
        if(dq.size()==k){

            flag[dq.back()] = false;
            dq.pop_back();
            
            dq.push_front(x);
            flag[x] = true;

        } else {

            flag[x] = true;
            dq.push_front(x);
            
        }

    }

    cout<<dq.size()<<'\n';

    while(!dq.empty()){
        cout<<dq.front()<<' '; dq.pop_front();
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();}

    return 0;
}