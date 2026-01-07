//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2545
#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, m; cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(m));        
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>graph[i][j];
    }

        // Recorremos en vertical y sumamos los 1
    int count=0;
    int i,j;
        
    set<pair<int,int>> vis;
    pair<int,int> edge;
    bool flag = 0;
    for(j=0;j<m;j++){
        count=0;
        for(i=0;i<n;i++){
            if(graph[i][j]){
                count++;
                if(flag){
                    flag=0;
                    edge.first = i;
                 } else {
                    flag = 1;
                    edge.second = i;
                }
            }
    }

        if(count>2 || count<2){
            cout<<"No"; return;
        }
        if(!vis.empty() && vis.count(edge)){
            cout<<"No"; return ;
        } else vis.insert(edge);
    }
        cout<<"Yes"; 
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