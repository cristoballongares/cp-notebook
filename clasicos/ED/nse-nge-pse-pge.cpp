#include<bits/stdc++.h>
using namespace std;

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

    for(int &x:a) sol.push_back((um.count(x)?um[x]:-1));

    return sol;
}

// pruebas
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    vector<int> sol = nse(a);
    for(int &x:sol) cout<<x<<' ';
    return 0;
}
