// pense que era geometria
// PERO ES PRINCIPIO DEL PALOMAR !!! XDDDDDD
// queremos garantizar un poligono cuyos vertices sean todos del mismo color
// cuantos puntos del mismo color podemos garantizar?????
// ceil ( n/k)
// n: luces
// k: colores disponibles

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t; cin>>t;
  while(t--){

    ll n,k; cin>>n>>k;

    ll ans = (n + k - 1) / k;

    cout<< ( ans < 3 ? "0" : to_string(ans))<<'\n';


  }

  return 0;

}
