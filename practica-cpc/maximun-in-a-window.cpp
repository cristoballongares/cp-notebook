#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;


vector<vector<int>> pre(vector<int> &input){
    int n = input.size();
    vector<vector<int>> sparse(input.size(),vector<int>((int)log2(input.size())+1));

    // sparse 
    int i,j;

    for(i=0;i<n;i++) sparse[i][0] = i;

    for(j=1; (1<<j) <=n; j++){
        for(i=0; (i+(1<<j)) - 1< n ; i++){
            if(input[ sparse[i][j-1] ] > input[sparse[i + (1<<(j-1))][j-1]]){
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
    
    int leftI = sparse[l][k];
    int rightI = sparse[ l + len - (1<<k) ][k];
    
    // comparamos los valores
    return max(input[leftI],input[rightI]);
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    vector<vector<int>> sparse = pre(a);
    int i=0,j=k-1;
    
    // for(vector<int> v:sparse){
    //     for(int &x:v){
    //         cout<<x<<' ';
    //     }
    //     cout<<'\n';
    // }

    while(j < n){
        cout<<query(i,j,sparse,a)<<' ';
        i++; j++;
    }


    return 0;

}