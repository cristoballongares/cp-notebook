// https://vjudge.net/problem/UVA-10020
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    int m; cin>>m;
    int a,b;
    vector<pair<int,int>> points;
    while(cin>>a>>b &&(a!= 0||b!=0)){
        points.push_back({a, b});
    }
    sort(points.begin(),points.end());

    int count = 1;
    int current = 0;
    int nxt=0,i=0;
    vector<pair<int,int>> sol;

    while(current<m){
        int bestReach = INT_MIN;
        int bestIndex = -1;

        while(i<points.size() && points[i].first<=current){
            if(points[i].second>bestReach){
                bestReach = points[i].second;
                bestIndex = i;
            }
            i++;
        }

        if(bestIndex==-1||bestReach<=current){
            cout<<0<<'\n'; return ;
        }

        sol.push_back(points[bestIndex]);
        current = bestReach;

    }

    cout<<sol.size()<<'\n';
    for(pair<int,int>x:sol) cout<<x.first<<' '<<x.second<<'\n';
    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t; cin>>t;

    while(t--){
        solve();
        cout<<'\n';
    }

    return 0;
}