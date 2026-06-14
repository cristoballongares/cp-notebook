#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        int i, c = 1;
        for(i=2; i*i<=x;i++){
            if(!(x%i))c+=((x/i) + ((x/i)/i));
        }
        cout<<c<<'\n';
        }

    return 0;

}