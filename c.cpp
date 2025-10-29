#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> a(n);
        for (ll &x:a) cin>>x;

        if(n==1){
            cout<<a[0]<<'\n';
        } else {
            int i=0,j=1;
            bool ok =0;
            while(i<j && j < n){
                int p1 = a[i]%2;
                int p2 = a[j]%2;
                i++;
                j++;
                if(p1!=p2){
                    ok = 1;
                    break;
                }
            }
            if(ok){
                sort(a.begin(),a.end());
                for(ll&x:a)cout<<x<<' ';
            } else {
                for(ll&x:a)cout<<x<<' ';
            }
            cout<<'\n';
        }


    }

}