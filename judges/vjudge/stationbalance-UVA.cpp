#include<bits/stdc++.h>
using namespace std;

void solve(double &C, double &S){

    deque<int>s; int i;
    double sum_mass=0;
    for(i=0;i<S;i++){
        int x; cin>>x;
        s.push_back(x);
        sum_mass+=x;
    }
    int resto = 2*C-s.size();
    for(i=0;i<resto;i++) s.push_back(0.00);

    sort(s.begin(),s.end());

    
    double avg=sum_mass/C;
    double sum=0;
    for(i=0;i<C;i++){
        int a,b;
        a = s.front(); s.pop_front();
        b = s.back(); s.pop_back();
        sum+=abs((a+b)-avg);
        
        cout<<" "<<i<<":";
        if (a > 0 && b > 0) cout<<" "<<a<<" "<<b;
        else if (b>0) cout<<" "<< b; 
        
        cout << "\n";
    }
    cout<<"IMBALANCE = "<<fixed<<setprecision(5)<<sum<<'\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // int t; cin>>t;
    double n,m, count=1;
    while(cin>>n>>m){
        cout<<"Set #"<<(int)count++<<'\n';
        solve(n,m);
        cout<<"\n";
        
    }

    return 0;
}