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
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rof(i,a,b) for(int i=(a);i>=(b);i--)

// utileria
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second

// mates
#define MOD 1000000007LL
#define INF 1e18

// debugging

#ifdef LOCAL
    #define dbg(x) cerr << #x << " = " << x << "\n"
    #define dbgv(v) cerr << #v << " = "; for(auto x : v) cerr << x << " "; cerr << "\n"
    #define dbgm(m) cerr << #m << ":\n"; for(auto row : m){ for(auto x : row) cerr << x << " "; cerr << "\n";}
#else
    #define dbg(x)
    #define dbgv(v)
    #define dbgm(m)
#endif

// -------------------------------------------

vector<int> dx = {-2,-2,2,2,1,-1,1,-1};
vector<int> dy = {1,-1,1,-1,2,2,-2,-2};

bool isValid(int x, int y, vector<vector<int>> &tab){

    int n = tab.size();

    return((x>=0 && x<n && y>=0 && y<n) && tab[x][y]==-1);

}

int countPositions(int x, int y, vector<vector<int>>& tab){

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
    
    int n;cin>>n;

    assert(n>=4);

    vector<vector<int>> tab(n,vector<int>(n, -1));

    int x = 0, y = 0;
    tab[x][y] = 1;

    int step;

    int bestX = -1, bestY = -1, bestCount = INT_MAX;

    vector<pii> valid_moves;

    for(step = 2; step<= n*n; step++){
    
        for(int k = 0; k<8; k++){

            int X = step + dx[k];
            int Y = step + dy[k];

            if(isValid(X, Y, tab)){
                tab[X][Y] = tab[x][y]+1;
                int count = countPositions(X, Y, tab);
                if(count < bestCount){
                    bestCount = count;
                    bestX = X;
                    bestY = Y;
                }
            }
        }


        x = bestX;
        y = bestY;
        tab[x][y] = step;


    }



    dbgm(tab);


    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}