#include <bits/stdc++.h>
using namespace std;

// tipos
using ll  = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;

// fast io
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

// loops
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FOReq(i,a,b) for(int i=(a);i<=(b);i++)
#define RFOR(i,a,b) for(int i=(a);i>=(b);i--)

// utileria
#define all(x)  (x).begin(),(x).end()
#define sz(x)   (int)(x).size()
#define pb      push_back
#define fi      first
#define se      second

// mates
#define MOD 1000000007LL
#define INF 1e18

// -------------------------------------------

vector<int> dx = {-2,-2,2,2,1,-1,1,-1};
vector<int> dy = {1,-1,1,-1,2,2,-2,-2};

bool isValid(int x, int y, vector<vector<int>> &tab){

    int n = tab.size();

    return((x>=0 && x<n && y>=0 && y<n) && tab[x][y]==-1);

}

int countPositions(int x, int y, vector<vector<int>> &tab){

    int k;
    int count = 0;
    
    for(k=0;k<8;k++){

        int X = x+dx[k];
        int Y = y+dy[k];


        if(isValid(X,Y,tab)) count++;
    }

    return count;
    

}


void solve(){
    
    
    

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}