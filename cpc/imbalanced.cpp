#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

vector<int> nge(vector<int>a){
    stack<int> s;
    vector<int> sol(a.size());
    int i;

    for(i=a.size()-1;i>=0;i--){

        while(!s.empty() && a[i]>=a[s.top()]){
            s.pop();
        }

        if(s.empty()){
            sol[i] = a.size();
        } else {
            sol[i] = s.top();
        }

        s.push(i);

    }


    return sol;
}


vector<int> pge(vector<int>a){
    stack<int> s;
    vector<int> sol(a.size());
    int i;
    int n= a.size();
    for(i=0;i<n;i++){

        while(!s.empty() && a[i]>a[s.top()]){
            s.pop();
        }

        if(s.empty()){
            sol[i] = -1;
        } else {
            sol[i] = s.top();
        }

        s.push(i);

    }


    return sol;
}


vector<int> pse(vector<int>a){
    stack<int> s;
    vector<int> sol(a.size());
    int i;
    int n= a.size();
    for(i=0;i<n;i++){

        while(!s.empty() && a[i]<a[s.top()]){
            s.pop();
        }

        if(s.empty()){
            sol[i] = -1;
        } else {
            sol[i] = s.top();
        }

        s.push(i);

    }


    return sol;
}

vector<int> nse(vector<int>a){
    stack<int> s;
    vector<int> sol(a.size());
    int i;
    int n= a.size();
    for(i=a.size()-1;i>=0;i--){

        while(!s.empty() && a[i]<=a[s.top()]){
            s.pop();
        }

        if(s.empty()){
            sol[i] = n;
        } else {
            sol[i] = s.top();
        }

        s.push(i);

    }


    return sol;
}

void solve(){

int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a)cin>>x;

    vector<int> left_mayor=pge(a);
    vector<int> right_mayor=nge(a);
    vector<int> left_menor=pse(a);
    vector<int> right_menor=nse(a);

    ll total_imbalance = 0;
    int i;
    for (i = 0; i<n; i++) {
        
        ll rangos_como_max = 1LL * (i - left_mayor[i]) * (right_mayor[i] - i); 
        ll rangos_como_min = 1LL * (i - left_menor[i]) * (right_menor[i] - i);

        total_imbalance += (rangos_como_max * a[i]);
        total_imbalance -= (rangos_como_min * a[i]);
    }

    cout<<total_imbalance;    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}