#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; 
int n, k;
vector<int> A, T;
vector<long long> P; 
long long memo[20][1 << 18]; 

long long get_sum(int i, int j) {
    return P[j] - P[i - 1];
}

long long solve(int idx, int mask) {
    if (mask == (1 << k) - 1) {
        return (idx == n + 1) ? 0 : INF;
    }
    if (idx == n + 1) return INF;

    // Memoria

    long long res = INF;

    int segments_needed = k - __builtin_popcount(mask);
    
    int limit = n - (segments_needed - 1);

    for (int i = idx; i <= limit; i++) {
        long long current_segment_sum = get_sum(idx, i);

        for (int j = 0; j < k; j++) {
            if (!((mask >> j) & 1)) {
                long long diff = current_segment_sum - T[j];
                long long cost = diff * diff; 
                
                long long remaining_cost = solve(i + 1, mask | (1 << j));
                
                if (remaining_cost != INF) {
                    res = min(res, cost + remaining_cost);
                }
            }
        }
    }

    return memo[idx][mask] = res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    if(cin >> n >> k) {
        A.resize(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        
        T.resize(k);
        for(int i = 0; i < k; i++) cin >> T[i];

        P.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            P[i] = P[i-1] + A[i-1];
        }

        memset(memo, -1, sizeof(memo));

        cout << solve(1, 0) << endl;
    }

    return 0;
}