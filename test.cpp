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

// Usar busqueda binaria en la respuesta, la complejidad sera O(nlogn)
// La idea es simple:p, es posible construir un segmento de k segmentos?
// Para ello, tenemos que ordenar el conjutno de segmentos, sencillo
// iterar por los n segmentos

// Pero, y si hacemos n^2, doble iteracion!
// Evaluar cada caso, que pasa si empezamos desde 0 b, es posible construir el segmento con k segmentos?
// Si, listo, facil.
// No?, se intento, pasamos con el siguiente b_i

// Primero probemos la primer idea

bool check(vector<segment> segs, int k,int m){
    int i,j;
    int count = 0;
    for(i=0;i<segs.size();i++){
        segment s = segs[i];
        int b = s.l;
        
        if(b==0 && s.r==0) continue; // evitamos 0,0

        if(b<0) b=0;
        count = 1; 
        for(j=0;j<segs.size();j++){
            if(i==j) continue; // No sirve comparar los mismos segmentos
            segment s2 = segs[j];
            int c = s2.l, d = s2.r;
            if(c<0) c=0;
            // Encontramos un segmento que empieza en b!, checamos su c!
            if(b==c && d!=c){
                count++;
            }
            b = c; // Actualizamos el punto final

            if(d==m) if(count==k) return true; // Es posible construir un segmento con k segmentos:)

        }
    }

    return false;
}


void solve(){
    int m; cin>>m;

    // En un inicio, todos los segmentos parecen ser opciones
    vector<segment> segments;
    int a,b;
    bool ok=1;
    int x = 0, y = 0;
    while(cin>>a>>b){
        if(a==0&&b==0) break;
        // Lo encontramos de una
        if(a<=0 && b>=m && ok){
            x=a; y=b;
            ok = 0;
        }

        segment s;
        s.l = a; s.r = b;
        if(a<=m)segments.push_back(s);

    }

    if(!ok){
        cout<<1<<'\n'<<x<<' '<<y<<'\n';
        return ;
    }

    sort(segments.begin(), segments.end(), [&](auto a, auto b){
            int lA = a.l; int lB = b.l;
            if(lA==lB) return a.r>b.r;
            return lA<lB;

        });

    // cout<<"AQUI!\n
    // for(segment s:segments) cout<<s.l<<' '<<s.r<<'\n';
    int i;
    stack<segment> s;
    s.push(segments[0]);
    
    for(i=1;i<segments.size();i++){

        int l=segments[i].l, r = segments[i].r;

        while(s.size()>1 && (r>=s.top().r)){
            cout<<"\tsacando: "<<s.top().l<<' '<<s.top().r<<'\n';
            s.pop();
        }
        s.push(segments[i]);
        if(s.top().r==m) break;

    }
    if(s.top().r!=m){ cout<<-1; return;}
    
    cout<<s.size()<<'\n';
    stack<segment> sol;
    while(!s.empty()){
        sol.push(s.top());
        s.pop();
    }
    while(!sol.empty()){
        cout<<sol.top().l<<' '<<sol.top().r<<'\n';
        sol.pop();
    }


}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t; cin>>t;

    while(t--){
        solve();
        cout<<"\n\n";
    }

    return 0;
}