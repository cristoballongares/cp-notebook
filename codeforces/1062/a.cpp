#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
    vector<int> e(4);
    cin>>e[0]>>e[1]>>e[2]>>e[3];
    
    
    int s = e[0]+e[1]+e[2]+e[3];
    int s1 = *min_element(e.begin(),e.end()) * 4;
    if(s==s1) cout<<"YES\n";
    else cout<<"NO\n";
    }


}