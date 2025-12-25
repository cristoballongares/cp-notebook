#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);


    int a; cin>>a;
    if(a==-999) cout<<-998<<' '<<-1;
    else if(a==999) cout<<998<<' '<<1;
    else if(a==1) cout<<2<<' '<<-1;
    else cout<<a-1<<' '<<1;

    return 0;

}