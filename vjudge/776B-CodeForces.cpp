#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

vector<bool> criba(int n){
    vector<bool> primo(n+1,true);
    primo[0]=primo[1]=false;
    for(int i=2;i*i<=n;i++){
        if(primo[i])
            for(int j=i*i;j<=n;j+=i) primo[j] = false; // Eliminamos sus multiplos
    }
    return primo;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<bool> isPrime = criba(100001);
    int k,i; cin>>k;

    if(k<2){
        cout<<1<<"\n1";
    } else if(k==2){
        cout<<1<<"\n1 1";
    } else {
        cout<<2<<'\n';
        for(int i=2;i<=k+1;i++){
            if(isPrime[i]) cout<<1<<' ';
            else cout<<2<<' ';
        }
    }

    return 0;
}