#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Cuantas veces son necesarias para que n sea <= 2?
    // n tiene mitad exacta?

    // porque para 8 y 4 son iguales?
    // para todo n>3 son 2 veces!
    // Solo tenemos que evaluar dos casos para todo n>3
    // Dividir m en 3 partes(?)
    // m1 = n%3, m2 = n/3, m3 = n/3

    // por ejemplo, para n = 10
    // 3 3 4


    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==3) cout<<1<<'\n';
        else if(n>3){
            int r = n%3;
            if(n/3 > 1) r++;
            cout<<r<<'\n';
        } else cout<<0<<'\n';

    }
    


}