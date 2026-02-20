// https://dmoj.ca/problem/coci15c2p2
// backtracking!, yei

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

int n, m;
bool bad[21][21];
int total = 0;

vector<int> pizza_actual;

void buscar(int id) {
    if(id>n){
        total++;
        return;
    }
    buscar(id+1);

    bool ok = true;
    for(int ing:pizza_actual) {
        if(bad[id][ing]) {
            ok=false;
            break;
        }
    }

    if(ok){
        pizza_actual.push_back(id); // metemos
        buscar(id+1); // seguimos buscando con el siguiente
        pizza_actual.pop_back(); // lo sacamos para probar otras
    }
}

void solve(){
    cin>>n>>m;
    int t = m;
    while(t--){
        int x,y;cin>>x>>y;
        bad[x][y] = true;
        bad[y][x] = true;
    }

    buscar(1);
    cout<<total;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}