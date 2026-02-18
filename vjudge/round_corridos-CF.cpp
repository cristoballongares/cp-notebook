//https://codeforces.com/contest/2196/problem/A

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    ll n,m,q;
    cin>>n>>m>>q;

    //NUm de intersecciones    
    ll g = __gcd(n,m);
    
    
    while(q--){
        ll a,b,c,d; cin>>a>>b>>c>>d;

        if(g!=1){

            ll bloques_adentro = n/g, bloques_afuera = m/g;
            ll inicio, fin;
            if(a==1){
                // Empezamos adentro
                inicio = (b-1)/bloques_adentro;
            } else inicio = (b-1)/bloques_afuera; // afuera

            //acabamos dentro
            if(c==1){
                fin = (d-1)/bloques_adentro;
            } else fin = (d-1)/bloques_afuera; // terminamos fuera!

            cout<<(inicio==fin?"YES":"NO");
            cout<<'\n';

            
        } else cout<<"YES\n";

    }
    


    return 0;
}