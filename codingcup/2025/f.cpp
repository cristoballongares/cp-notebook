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

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    char dir[] = {'v', '^', '>', '<'};
                    
    bool isValid(int x, int y, int &r, int &c){

        return ( x >= 0 && y >= 0 && x < r && y < c);

    }

    void solve(){
        
        int r,c; cin>>r>>c;
        vector<vector<char>> tab(r,vector<char>(c));

        for(vector<char> &y:tab){
            for(char &x:y) cin>>x;
        }

        
        vector<vector<bool>> vis(r, vector<bool>(c));
        vector<vector<int>> d(r, vector<int>(c,INT_MAX/2));


        deque<pii> q;
        q.push_back({0,0});
        d[0][0] = 0;
        vis[0][0] = true;
        

        while(!q.empty()){

            pii u = q.front();
            q.pop_front();

            int x = u.first; // r
            int y = u.second; // c
            char mov = tab[x][y];
        
            // vemos los adyacentes de (x,y)
            for(int k = 0; k < 4 ; k++){

                int X = x + dx[k], Y = y + dy[k];
            
                // cout<<X<<' '<<Y<<'\n';


                if(isValid(X,Y,r,c)){

                    // cout<<"\t "<<tab[X][Y]<<'\n';

                    char v = tab[X][Y];
                    int w = (mov == dir[k]) ? 0 : 1;

                    if(d[x][y] + w < d[X][Y]){

                        d[X][Y] = d[x][y] + w; 

                        if(w) q.push_back({X,Y});
                        else q.push_front({X,Y});

                    } 

                }

            }
        }

        // for(vector<int> &y:d){
        //     for(int &x:y) cout<<x<<' ';
        //     cout<<'\n';
        // }

        cout<<d[r-1][c-1];


    }

    int main(){
        fast;
        
        int t=1; 
        // cin>>t;
        while(t--){solve();cout<<'\n';}

        return 0;
    }