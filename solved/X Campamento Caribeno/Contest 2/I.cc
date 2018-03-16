#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl;

const int MOD = 2007;

int main() {
    int n; cin >> n;
    vector<int> f(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    g[1] = 1;
    for (int i = 2; i <= n; i++) {
        int acc = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (j != 1) acc = (acc + (f[j] * g[i / j]) % MOD) % MOD;
                if (j * j != i) acc = (acc + (f[i / j] * g[j]) % MOD) % MOD;
            }
        }
        g[i] = (MOD - acc) % MOD;
    }
    for (int i = 1; i <= n; i++)
        cout << g[i] << " ";
    cout << endl;
    return 0;
}
