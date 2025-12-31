#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

vector<ll> fibo(6005); 
void pre(ll mod){
    fibo[0] = 0;
    fibo[1] = 1 % mod;
    for(int i=2;i<fibo.size();i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % mod; 
    }
}

string fibo_str(){
    string x;
    for(int i = 0; i < fibo.size(); i++) x += (char)(fibo[i] + '0');
    return x;
}

bool f(const string &s, ll l){
    if (l == 0) return false;
    string a = s.substr(0, l);
    string b = s.substr(l, l); 
    // cout << l << " " << a << " " << b << "\n";
    return a == b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    ll n; cin>>n;
    pre(n);
    string fib = fibo_str();
    for(int i=1;i<=3000;i++){ 
        if (f(fib, i)) {
            cout<<i<<"\n"; 
            break;
        }
    }

    return 0;
}