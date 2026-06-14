#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        int i, c = 0;
        for(i=1; i*i<=x;i++){
            if(i*i==x)c++;
            else if(!(x%i))c+=2;
        }
        cout<<c<<'\n';
        }

    return 0;

}