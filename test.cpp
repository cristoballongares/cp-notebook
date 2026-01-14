#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

struct segment{

    int l,r;

};

//Elegir SIEMPRE la minima cantidad de segmentos
// Casos utiles, pues ocupan un solo segmento para rellenar todo [0,m] 
    // l = 0 y r = m
    // l<=0 t r>=m;
// Si ninguno de estos casos se cumplen, que sigue?
// Fuerza bruta?, tomemos en cuenta que i <= 100000
// Entonces, sale en O(i)?
// o en (i*i)? = 1e9, perfecto!, posible complejidad O(n)
// De ser asi, empezaremos probando los mejores casos
// Como seria la estrategia greedy?
// Recordemos que esta estrategia solo la usaremos en caso de no cumplir ningun caso util, por lo tanto
// Empezaremos con aquellos mas cercanos a [0,m]

void solve(){
    int m; cin>>m;

    // En un inicio, todos los segmentos parecen ser opciones
    vector<segment> segments;
    int a,b;
    while(cin>>a>>b){
        // Lo encontramos de una
        if(a==0 && b==m){
            cout<<0<<' '<<m;
            return ;
        }
        
        if(a<=0 && b>=m){
            cout<<a<<' '<<b;
            return ;
        }

        segment s;
        s.l = a; s.r = b;
        if(a<=m)segments.push_back(s);
        if(a==0 &&b==0) break;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t; cin>>t;

    while(t--){
        solve();
        cout<<'\n';
    }

    return 0;
}