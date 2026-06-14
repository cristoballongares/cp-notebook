#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;


bool check(vector<int> &a, int x, int b){

    int count=0;
    for(int &v:a){
        count+=(v+x-1)/x;
    }

    return (count<=b);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n,b;

    while(cin>>n>>b && n!=-1){
        vector<int>a(n);
        int mx=0;
        for(int&x:a)cin>>x;
        for(int&x:a)mx = max(mx,x);
        
        int l = 1, r = mx;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(check(a,mid,b)){
                r=mid-1;
            } else l=mid+1;
        }

        cout<<r+1;
        cout<<"\n";
    }

    return 0;
}