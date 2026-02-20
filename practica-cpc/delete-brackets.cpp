#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    string st; cin>>st;
    stack<char> s;
    for(char &x:st){
        if(x=='(') s.push(x);
        else {
            if(!s.empty() && s.top()=='(') s.pop();
            else s.push(x);
        }
        
    }

    cout<<s.size();


    return 0;
}