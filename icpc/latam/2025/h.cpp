#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    vector<int> a(n);

    for(int &x:a) cin>>x;

    int count = 1;
    int mx = a[0], res = 0;

    for(int i = 1; i < n ; i++){
     
        if(a[i] > mx){
            count++;
            mx = a[i];
        }

    }

    cout<<count;



}