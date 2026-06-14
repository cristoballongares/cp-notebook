#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; 
    cin >> n >> m;
    
    vector<int> bad_mask(n, 0); 
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;

        bad_mask[u] |= (1 << v); 
        bad_mask[v] |= (1 << u);
    }
    
    int valid_pizzas = 0;
    int total_combinations = (1 << n); 
    
    for(int mask = 0; mask < total_combinations; mask++){
        bool is_valid = true;
        
        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) != 0){
                
                if((mask & bad_mask[i]) != 0){
                    is_valid = false;
                    break;
                }
            }
        }
        
        if(is_valid) {
            valid_pizzas++;
        }
    }
    
    cout << valid_pizzas;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}