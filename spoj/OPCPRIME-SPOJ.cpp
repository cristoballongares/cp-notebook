// https://www.spoj.com/problems/OPCPRIME/en/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

set<lli> factorizar(lli n){
    set<lli> sol;
    while(n%2==0){
        sol.insert(2); n/=2;
    }

    for(lli d = 3;d*d<=n;d+=2){
        while(n%d==0) sol.insert(d), n/=d;
    }
    
    if(n>1) sol.insert(n);
    return sol;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    lli n; cin>>n;
    set<lli> sol = factorizar(n);

    for(auto &x:sol)cout<<x<<'\n';

    return 0;
}