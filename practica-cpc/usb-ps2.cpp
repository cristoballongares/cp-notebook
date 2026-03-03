#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    
    int usb,ps2,both; cin>>usb>>ps2>>both;
    priority_queue<ll> pq_usb;
    priority_queue<ll> pq_ps2;

    int m; cin>>m;

    if(m==0){

        cout<<"0 0"; return;

    }

    int t=m;
    while(t--){

        ll x; cin>>x;
        string s;cin>>s;

        if(s=="USB") pq_usb.push(-x);
        else pq_ps2.push(-x);


    }

    ll sum = 0, count = 0;

    while(usb-- > 0 && !pq_usb.empty()){
        sum += -pq_usb.top(); count++;
        pq_usb.pop();
    }

    while(ps2-- > 0 && !pq_ps2.empty()){
        sum += -pq_ps2.top(); count++;
        pq_ps2.pop();
    }

    while(both-- > 0){
        bool USB = !pq_usb.empty();
        bool PS2 = !pq_ps2.empty();
        if(!USB && !PS2) break;
        
        if(USB && PS2){
            if(-pq_usb.top() <= -pq_ps2.top()){
                sum+= -pq_usb.top(); pq_usb.pop();
            } else {
                sum+= -pq_ps2.top(); pq_ps2.pop();
            }
        } else if(USB){
            sum+= -pq_usb.top(); pq_usb.pop();
        } else {
            sum+= -pq_ps2.top(); pq_ps2.pop();
        }
        count++;
    }

    cout<<count<<' '<<sum;

}



int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}