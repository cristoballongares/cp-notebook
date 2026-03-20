#include<bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> nse(vector<ll> a){
    int i;
    unordered_map<ll,ll> um;
    stack<pair<ll,ll>> s;
    int n = a.size();
    // what hahaha
    // hice lo mismo que pse:p, solo cambie la forma de recorrer *a* jajaja
    for(i=a.size()-1;i>=0;i--){
        int x = a[i];
        while(!s.empty() && s.top().first>=x){
            s.pop(); 
        }
        if(!s.empty() && s.top().first<x) um[i] = s.top().second+1;
        s.push({x,i});
    }

    vector<ll> sol(a.size(),n+1);
    for(i=0;i<a.size();i++){
        if(um.count(i)) sol[i] = um[i];
    }
    return sol;}

vector<ll> pse(vector<ll> a){
    int i;
    int n = a.size();
    unordered_map<ll,ll> um;
    stack<pair<ll,ll>> s;
    //         valor,pos
    // Recorremos de inico a fin
    for(i=0;i<a.size();i++){
        int x = a[i];
        // Si tenemos algo en s y este es mayor igual a lo actual...
        while(!s.empty() && s.top().first>=x){
            s.pop(); // lo sacamos!, hasta encontrar uno < x
        }
        // Si s no esta vacia y el tope es <= x, listo!, PSE encontrado:)
        if(!s.empty() && s.top().first<x) um[i] = s.top().second+1; // OJOO, estamos usando 1-based indexing xD
        s.push({x,i});
     }
    vector<ll> sol(a.size(),0);
    for(i=0;i<a.size();i++){
        if(um.count(i)) sol[i] = um[i];
    }
    return sol;

}
// Como manejamos repetidos?, recuerda que estas usando almcacenando por mapa, aquello involucra claves hash
// En este caso, lo unico son las posiciones (0,1,2,3,..,n-1)
// si um almacena <pos,pos_PSE>, entoncessss...
// 

// Si no hay un PSE o un NSE podemos usar -1 para indicarlo, gracias a las restricciones del problemaaaa:))
long long largestRectangleArea(vector<ll>& heights) {
    long long sol = INT_MIN, n = heights.size(),i;
    vector<ll> a = heights;
    vector<ll> NSE = nse(heights);
    vector<ll> PSE = pse(heights);
    // cout<<"NSE: ";
    // for(int &x:NSE) cout<<x<<' ';
    // cout<<'\n';
    // cout<<"PSE: ";
    // for(int &x:PSE) cout<<x<<' ';
    // cout<<'\n';
    int j;
    for(j=0;j<n;j++){
        i=j+1;
        int h = heights[j];
        sol = max(sol,h*(NSE[j]-PSE[j]-1));
    }

    return sol;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;
    
    while(cin>>n && n!=0){
        vector<ll> a(n);
        for(ll &x:a) cin>>x;
        cout<<largestRectangleArea(a)<<'\n';
    }


    return 0;
}

