#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(int num){
    int w,h;
    cin>>w>>h;
    
    vector<string> grid(h);
    int startX=-1, startY=-1;
    int i;
    for (i=0; i<h ;i++){
        cin>>grid[i];
        for (int j = 0; j < w; j++){
            if(grid[i][j] == '@'){
                startX = i;
                startY = j;
            }
        }
    }
    
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    
    q.push({startX, startY});
    vis[startX][startY] = true;
    int ans = 1;
    
    while (!q.empty()){

        auto [x, y] = q.front();
        q.pop();
        
        for (i=0; i<4; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            
            if (xx >=0 && xx<h && yy>=0 && yy<w){
                if (!vis[xx][yy] && grid[xx][yy] == '.'){
                    vis[xx][yy] = true;
                    q.push({xx, yy});
                    ans++;
                }
            }
        }
    }
    
    cout<<"Case "<<num<<": " <<ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t; 
    cin>>t;
    for (int i=1;i<=t;i++){
        solve(i);
        cout<<'\n';
    }

    return 0;
}