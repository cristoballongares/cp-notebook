#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i;
    vector<string> sus(1);
    string abc = "abcdefghijklmnopqrstuvwxyz";
    for(int i =0;i<4;i++){
        for(char &x:abc){
            string c = to_string(i)+x;
            sus.push_back(c);
        }
    }

    for(string &x: sus)cout<<x<<",";

    for(i=1;i<4;i++){
        int n = i*i + 4;
    }

    return 0;
}