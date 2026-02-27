#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

void solve(){
    int n,k; cin>>n>>k;
    int l = 0;
    map<int,int> freq;
    ll count = 0;

    vector<int> a(n);
    for(int &x:a)cin>>x;

    for(int r=0;r<n;r++){

        freq[a[r]]++;
        
        // si tenemos mas freq.size() elementos distintos de los permitidos
        while(freq.size() > k){

            freq[a[l]]--; // sacamos el ultimo ingresado


            if(freq[a[l]]==0) freq.erase(a[l]); // si nos quedamos sin valores de a[l], lo eliminamos

            l++;

        }

        count += (r-l+1);


    }

    cout<<count;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();}

    return 0;
}