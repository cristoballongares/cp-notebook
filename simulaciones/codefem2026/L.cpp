#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string b; getline(cin,b);
  int x; cin>>x;

  vector<string> patt = {
    "pgr", "byyb", "wwgyw", "bwwbwb", "prpb", "prrb", "rrggr", "pywb", "vpggpv", "gpbrywvpg"
  };

  vector<int> beauty = { 3,5,7,8,10,12,14,17,20,25};

  ll ans = 0;

  string cur;

  for(int i = 0 ; i <= b.size() ; i++){

    if( i < b.size() && b[i] != ' '){
      cur+=b[i]; continue;
    }

    // si no tenemos ninguna palabra a procesar, continuamos
    if(cur.empty()) continue;

    int best = 0;

    // probamos los 10 patrones
    for(int j= 0 ; j<10 ; j++){

      // comparamos solo si tieen la misma l
      if(patt[j].size() != cur.size()) continue;

      int dif = 0;

      // en cuantas difieren
      //
      for(int k = 0 ; k < cur.size() ; k++){

        if(cur[k] != patt[j][k]) dif++;

      }

      // caso simple, es el mismo patron
      if(dif == 0){
        best = 0;
        break;
      }

      if(dif == 1) best = max(best,beauty[j]);

    }

    ans+=best;
    cur.clear();

  }

  cout<<ans;

  return 0;
}
