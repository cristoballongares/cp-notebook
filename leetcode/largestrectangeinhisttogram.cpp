#include<bits/stdc++.h>

using namespace std;

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    vector<int> b=a;
    vector<int> s = nge(b,a);
    for(int x:s) cout<<x<<' ';


    return 0;
}

