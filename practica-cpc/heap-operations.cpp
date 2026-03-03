#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    
    int n; cin>>n;
    priority_queue<int> pq;

    queue<string> q;
    
    map<int,int> exist;

    int t = n;

    while(t--){

        string s; cin>>s;
        if(s == "insert"){

            int x; cin>>x;

            string ss = "insert " + to_string(x);

            q.push(ss);

            pq.push(-x);

        } else if(s == "removeMin"){


            if(!pq.empty()){
                
                q.push("removeMin");

                pq.pop();

            } else {

                q.push("insert 1");
                q.push("removeMin");

            }


        } else {

            int x; cin>>x;

            while (!pq.empty() && -pq.top()<x) {
                q.push("removeMin");
                pq.pop();
            }

            if (pq.empty() || -pq.top() != x) {
                q.push("insert " + to_string(x));
                pq.push(-x);
            }

            q.push("getMin " + to_string(x));

        }

    }

    cout<<q.size()<<'\n';

    while(!q.empty()){

        cout<<q.front()<<'\n'; q.pop();

    }


}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}