#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m){
    if(b==0) return 1;
    if(b%2) return binpow(a,b-1,m) * a%m;
    long long r = binpow(a,b/2,m);
    return r*r% m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<binpow(a,b,10)<<'\n';
    }
        return 0;
}