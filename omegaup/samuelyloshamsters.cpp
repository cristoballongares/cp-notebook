// https://omegaup.com/arena/problem/Samuel-y-los-Hamsters?fromLogin
#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
using ll = long long;
using li = long int;

bool f(const vector<li> &nums, const li &hamsters, const li &x){

    li count = 1, prev = 0,i;
    prev = nums[0];
    for(i=1;i<nums.size();i++){
        li diff = abs(nums[i]-prev);
        
        // cout<<"\tPrevio: "<<prev<<" - Evaluando: "<<nums[i]<<'\n';
        // cout<<"\tDIFF: "<<diff<<'\n';

        if(diff>=x){ // x <= (Ubicacion Hamster 1  - Ubicacion Hamster 2)
            count++;
            prev = nums[i];
        }
        if(count==hamsters) return true;
    }

    return false;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    li n, k; cin>>n;
    cin>>k;
    vector<li> nums(n);
    for(li&x:nums)cin>>x;
    // for(li&x:nums) cout<<x<<' ';
    // cout<<'\n';

    // for(n=1;n<=10;n++) cout<<f(nums,k,n)<<' ';

    li l = 1, r = 1e9, sol = 0;
    
    // Mi error: tenia l<r
    // JAMAS PROBABA EL CASO l==r
    // :)

    while(l<=r){
        li mid = l + (r-l)/2;
        // cout<<"Probando con: "<<mid<<'\n';
        if(f(nums,k,mid)){
            sol = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout<<sol;
    return 0;

}