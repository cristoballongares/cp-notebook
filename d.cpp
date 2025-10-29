#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b?gcd(b, a % b):a; }

int solve(const vector<int>& arr) {
    for (int a:arr) if(a==1) return 2;
    
    for (int x=2; x<=1e6;x++) {
        for (int a:arr) {
            if (gcd(x,a) == 1) {
                return x;
            }
        }
    }
    
    bool allEven = true;
    for (int a :arr) if(a%2) allEven = false;
    if (allEven) return 3;
    // funcionara probar solo con primos peque;os?
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
    for (int p:primes) {
        for (int a:arr) {
            if (gcd(p,a) == 1) return p;
        }
    }

    return 2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);


    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n); for(int &x:a)cin>>x;

        cout<<solve(a)<<'\n';

    }
}