#include<bits/stdc++.h>
using namespace std;

// -1: Significa no existe

// NGE: Devuelve un arreglo (a) que se crea a partir de otro arreglo (b) en donde
// cada a_i es el NGE de b_i 

//Encontrar el Next Greater Element (NGE)
vector<int> nge(vector<int>b, vector<int>a){
    stack<int> s;
    unordered_map<int,int> um;
    int i;
    s.push(a[0]);
    for(i=1;i<a.size();i++){
        int prev = s.top();
        int act = a[i];
        while(act>prev){
            um[prev] = act;
            s.pop();
            if(s.empty()) break;
            prev = s.top();
        }
        s.push(act);
    }

    vector<int> sol;
    for(int x:b) sol.push_back(um.count(x)?um[x]:-1);
    return sol;
}

vector<int> nge(vector<int>a){
    stack<int> s;
    unordered_map<int,int> um;
    int i;
    s.push(a[0]);
    for(i=1;i<a.size();i++){
        int prev = s.top();
        int act = a[i];
        while(act>prev){
            um[prev] = act;
            s.pop();
            if(s.empty()) break;
            prev = s.top();
        }
        s.push(act);
    }

    vector<int> sol;
    for(int x:a) sol.push_back(um.count(x)?um[x]:-1);
    return sol;
}


vector<int> pge(vector<int> a){
    reverse(a.begin(),a.end());
    vector<int> b = nge(a);
    reverse(b.begin(),b.end());
    return b;
}

//Encontrar el NextSmallerElement
// ej: 8 2 5 7 3 2 1
//     2 1 3 3 2 1 -1
vector<int> nse(vector<int> a){
    vector<int> sol;
    unordered_map<int,int> um;
    stack<int> s;
    int i;
    s.push(a[0]);
    for(i=1;i<a.size();i++){
        int prev = s.top();
        int act = a[i];
        while(act<prev){
            um[prev] = act;
            s.pop();
            if(s.empty()) break;
            prev = s.top();
        }
        s.push(a[i]);
    }
    vector<int> solucion;
    for(int elemento:a) solucion.push_back(um[elemento]);
    return solucion;
}
// PSE: Preview Smaller Element
// ej: 2 5 3 4 8 2 1
//    -1 2 2 3 4 -1 -1
vector<int> pse(vector<int> a){
    reverse(a.begin(),a.end());
    vector<int> b = nse(a);
    reverse(b.begin(),b.end());
    return b;
}

// pruebas
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    vector<int> sol = pge(a);
    for(int &x:sol) cout<<x<<' ';
    return 0;
}
