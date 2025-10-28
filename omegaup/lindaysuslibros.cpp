#include<bits/stdc++.h>
// https://omegaup.com/arena/problem/Linda-y-sus-libros
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    

    int n; cin>>n;

    unordered_map<int, string> um;
    priority_queue<pair<int,int>> pq;

    int i;
    for(i=0;i<n;i++){
        int y; string s; cin>>y>>s;
        um[i] = s;
        pq.push({-y,-i});
    }

    while(!pq.empty()){
        pair<int,int> pi = pq.top();
        pq.pop();
        // cout<<-pi.first<<' '<<-pi.second<<' '<<um[-pi.second]<<'\n';
        cout<<um[-pi.second]<<'\n';
    }


    


}