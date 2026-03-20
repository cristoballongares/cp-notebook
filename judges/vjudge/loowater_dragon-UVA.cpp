#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;
void solve(){
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n,m;
    while(cin>>n>>m &&( n!=0 || m!=0)){
            priority_queue<int> dragons;
            vector<int> a,b;
            priority_queue<int> knights;
            int i;
            for(i=0;i<n;i++){
                int x; cin>>x;
                a.push_back(x);
                dragons.push(-x);
            }
            for(i=0;i<m;i++){
                int x; cin>>x;
                b.push_back(x);
                knights.push(-x);
            }

            // for(int &x:a)cout<<x<<' ';
            // cout<<'\n';
            // for(int &x:b)cout<<x<<' ';
            // cout<<'\n';


        if(n>m) cout<<"Loowater is doomed!";
        else{
            
            int count =0;

            while(!dragons.empty()){
                int a,b;
                a = -dragons.top();
                b = -knights.top();
                knights.pop();
                // cout<<b<<" vs "<<a<<'\n';
                if(b>=a){
                    count+=b;
                    dragons.pop();
                }

                if(knights.empty()) break;
                if(dragons.empty()) break;
            }

            if(!dragons.empty()) cout<<"Loowater is doomed!";
            else cout<<count;
            
  
        }

        cout<<'\n';
    }


    return 0;
}