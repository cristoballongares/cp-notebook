#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

vector<vector<int>>pre_min(vector<int> &input, int n){
    vector<vector<int>> sparse(n,vector<int>(1+log2(n)));

    // Llenamos nuestra columna inicial:)
    int i,j;
    for(i=0;i<n;i++) sparse[i][0] = i;

    // Recordemos que 2^n = (1<<n) 
    // Bitwise Left Shift

    for(j=1;(1<<j)<=n;j++){
        for(i=0; i + (1<<j) - 1 <n;i++){
            if(input[sparse[i][j-1]] < input[sparse[i + (1<<(j-1))][j-1]]){
                sparse[i][j] = sparse[i][j-1];
            } else {
                sparse[i][j] = sparse[i + (1<<(j-1))][j-1];
            }
        }
    }

    return sparse;

}

vector<vector<int>>pre_max(vector<int> &input, int n){
    vector<vector<int>> sparse(n,vector<int>(1+log2(n)));

    // Llenamos nuestra columna inicial:)
    int i,j;
    for(i=0;i<n;i++) sparse[i][0] = i;

    // Recordemos que 2^n = (1<<n) 
    // Bitwise Left Shift

    for(j=1;(1<<j)<=n;j++){
        for(i=0; i + (1<<j) - 1 <n;i++){
            if(input[sparse[i][j-1]] > input[sparse[i + (1<<(j-1))][j-1]]){
                sparse[i][j] = sparse[i][j-1];
            } else {
                sparse[i][j] = sparse[i + (1<<(j-1))][j-1];
            }
        }
    }

    return sparse;

}



int query(int l, int r, const vector<vector<int>>& sparse, const vector<int>& input) {
    int len = r - l+ 1;
    // k = potencia de 2 mas grande que cabe    
    int k = (int)log2(len);
    
    // obtenemos indices en ambos bloques
    int leftI = sparse[l][k];
    int rightI = sparse[r - (1 << k) + 1][k]; // r - 2^k + 1
    
    // comparamos los valores
    return min(input[leftI],input[rightI]);
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin>>n;
    vector<int>a(n);
    for(int &x:a)cin>>x;

    vector<vector<int>> sparse = pre_max(a,a.size());

    // for(vector<int> x:sparse){
    //     for(int &y:x){
    //         cout<<y<<' ';
    //     }
    //     cout<<'\n';
    // }

    cout<<query(3,5,sparse,a);


    return 0;
}