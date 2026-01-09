#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using lli = long long int; // ojo, evitamos algo malo...

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


int main(){
    lli n; cin>>n;
    vector<lli> productos = factorizar(n);

    lli sol =1;

    for(lli &x:productos){
        cout<<x<<' ';
        sol*=x;
    }

    cout<<'\n';

    cout<<sol;
}