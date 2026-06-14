#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

unordered_map<lli,lli> factorizar(lli n){
    unordered_map<lli,lli> sol;
    while(n%2==0){
        sol[2]++, n/=2;
    }

    for(lli d = 3;d*d<=n;d+=2){
        while(n%d==0) sol[d]++, n/=d;
    }
    
    if(n>1) sol[n]++;
    return sol;
}

lli binpow(lli base, lli exp) {
    lli res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base; // Si el exponente es impar
        base *= base;
        exp /= 2;
    }
    return res;
}


void solve(){
    
    ll n,p;cin>>n>>p;

    unordered_map<lli,lli> f = factorizar(p);
    
    ll k = 1;

    for(auto &x:f){

        lli exp = floor(x.second/n);
        
        k*= binpow(x.first,exp);

    }

    cout<<k;    


}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}