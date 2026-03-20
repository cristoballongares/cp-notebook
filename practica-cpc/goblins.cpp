#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    
    int n; cin>>n;
    deque<pair<int,int>> dq;
    
    int t = n;
    int sz = 0;
    while(t--){
        char x; cin>>x;
        if(x=='+'){
            
            int a; cin>>a;
            dq.push_back(make_pair(a,-1));
            sz++;

        } else if(x=='*'){
            int a;cin>>a;
            int pos;

            if(sz&1){ //impar
            
                pos = floor(dq.size()/2)-1; // si sale algun error de indices verifiquemos este
                // se supone que con 1 debe dar 0 y es coreecto

                dq[pos].second = a;

            } else { // tam par
                
                pos =(dq.size()/2)-1;
                dq[pos].second = a;
                cout<<"Me unire en: "<<pos<<'\n';


            }

            sz++;
            
            // cout<<"Me unire en: "<<pos<<'\n';

        } else { // goblins salen
            // when a goblin leaves the queue is never empty :P

            if(dq.front().second!=-1){

                cout<<dq.front().second;
                dq.front().second = -1;

            } else {

                cout<<dq.front().first;
                dq.pop_front();

            }

            sz--;

            cout<<'\n';



        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
        // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}