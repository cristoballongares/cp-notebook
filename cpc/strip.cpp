#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    
    int n,s,l; cin>>n>>s>>l;

    vector<int> a(n); 
    for(int &x:a) cin>>x;

    int i=0,j=0;

    int mx = INT_MIN, mn = INT_MAX, count = 0;
    bool ok = 0, res_back = 0;
    // stack<int> s;
    while(i<=j && j < n){

        int x = a[i];

        mx = max(mx,a[j]);
        mn = min(mn,a[j]);

        if(x == mx && x == mn){
            j++;
            continue;
        }

        int r = mx-mn;
        cout<<"["<<i<<' '<<j<<"] , "<<r<<'\n';
        int k = j-i+1;

        if(k<l){
            j++;
        } else {

            if(r>s){

                if(ok){
                    count++;
                    ok = 0;
                }

                i = j;

            } else {
                j++;
                ok = true;
            }

            }

    }

    cout<<count;


}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>> t;
    while(t--){solve();cout<<'\n';}

    return 0;
}