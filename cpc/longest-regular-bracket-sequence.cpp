#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){

    string st; cin>>st;
    
    stack<int> s; s.push(-1);
    int mx=0, count=1; 
    
    for(int i=0;i<st.length();i++){
        
        if(st[i] == '('){
            s.push(i);
        } else {

            s.pop();
            
            if(s.empty()){
                s.push(i);
            } else {
                
                int k = i-s.top();
                
                if(k>mx){
                    mx = k;
                    count=1;
                } else if(k==mx) count++;
                
            }
        }
    }
    
    cout<<mx<<' '<<count;;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}