#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
using ll = long long;
int solve(const vector<ll>& arr) {
    for (ll x=2; x<=1e6;x++) {
        for (ll a:arr) {
            if (__gcd(x,a) == 1) {
                return x;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);


    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> a(n); for(ll &x:a)cin>>x;

        cout<<solve(a)<<'\n';

    }
}
