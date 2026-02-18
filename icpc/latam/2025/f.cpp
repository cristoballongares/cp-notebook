// https://codeforces.com/gym/106178/problem/F
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

vector<lli> factorizar(lli n){
    vector<lli> sol;
    while(n%2==0){
        sol.push_back(2), n/=2;
    }

    for(lli d = 3;d*d<=n;d+=2){
        while(n%d==0) sol.push_back(d), n/=d;
    }
    
    if(n>1) sol.push_back(n);
    return sol;
}

unordered_map<ll, ll> fact(ll n){
    unordered_map<ll, ll> factores;
    while(n%2==0){
        factores[2]++;
        n/=2;
    }
    for(ll d = 3; d*d <= n; d += 2){
        while(n%d==0){
            factores[d]++;
            n /= d;
        }
    }
    if(n>1) factores[n]++;
    return factores;
}


void solve(){
    string x; cin>>x;
    
    if(x.size()<=12){
        ll n = stoll(x);
        unordered_map<ll,ll> m = fact(n);
        cout<<m.size()<<'\n';
        for(auto &x:m) cout<<x.first<<' '<<x.second<<'\n';
        return ;

    }

    ll n = stoll(x.substr(0,13));
    ll k = x.length()-13;

    unordered_map<ll,ll> m = fact(n);
    // lo descomponemos en primos: n x 10^k = P x (5x2)^k
    // P x 2^k x 5^k
    m[2]+=k; m[5]+=k;

    cout<<m.size()<<'\n';
    for (auto&x:m) cout<<x.first<<' '<<x.second<<'\n';


}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    solve();

    return 0;
}