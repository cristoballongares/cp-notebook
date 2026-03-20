#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const char nl = '\n';

struct p{
    int year, score;
    string name;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin>>n;
    vector<p> a(n);
    for(auto &x:a){
        int y,p; string nm;
        cin>>y>>nm>>p;
        x.year = y;
        x.name = nm;
        x.score = p;
    }

    sort(a.begin(),a.end(), [&](p a, p b){
        if(a.year==b.year) return a.score<b.score;
        return a.year<b.year;
    });

    // for(auto &x:a){
    //     cout<<' '<<x.year<<' '<<x.name<<' '<<x.score<<'\n';
    // }

    // cout<<"\n\n\n";

// 1. El maratón debe avanzar a través del tiempo: cada película seleccionada debe tener un año de estreno mayor o igual al de la película anterior.

// 2. El maratón debe ser variado: no deben incluirse dos películas del mismo director de manera consecutiva.

// 3. Cada película seleccionada debe ser "mejor" que la anterior, donde "mejor" se mide usando el puntaje dado (por ejemplo, de IMDb o Rotten Tomatoes).


    int i,j;
    int sol = 0,count=0;
    vector<int> dp(n,1);
    for(i=0;i<a.size();i++){
        for(j=0;j<i;j++){
            if(a[i].name != a[j].name && (a[j].score< a[i].score) &&a[j].year<=a[i].year){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    sol = *max_element(dp.begin(),dp.end());
    cout<<sol;


    return 0;
}