#include<bits/stdc++.h>
using namespace std;

vector<bool> criba(int n){
    vector<bool> primo(n+1,true);
    primo[0]=primo[1]=false;
    for(int i=2;i*i<=n;i++){
        if(primo[i])
            for(int j=i*i;j<=n;j+=i) primo[j] = false; // Eliminamos sus multiplos
    }
    return primo;
}

// Por si se ncesita preCalcular :)
void pre(int n){
    vector<bool> primo(n+1,true);
    primo[0]=primo[1]=false;
    for(int i=2;i*i<=n;i++){
        if(primo[i])
            for(int j=i*i;j<=n;j+=i) primo[j] = false;
    }
    // miVector = primo;
}

