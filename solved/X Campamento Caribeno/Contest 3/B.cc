#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const long long mod = 998244353;

long long mod_pow(long long b, long long exp) {
    long long ans = 1;
    while(exp) {
        if (exp & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        exp >>= 1;
    }
    return ans;
}

long long memo[205];
long long comb[205][205];

long long deragement(long long x) {
    if (x == 1) return 0;
    if (x == 0) return 1;
    if (memo[x] != -1) return memo[x];
    long long ans = ((x - 1) * (deragement(x - 1) + deragement(x - 2)) % mod) % mod;
    return memo[x] = ans;
}

void gen_comb() {
    memset(comb, 1, sizeof comb);
    for (int i = 0; i < 205; i++) {
        for (int j = 0; j < 205; j++)  comb[i][j] = 1;
    }
    for (int i = 2; i < 205; i++) {
        for (int j = 1; j < i; j++) comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }
}


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#else
    freopen("bt.in", "r", stdin);
#endif
    long long n;
    gen_comb();
    while (cin >> n) {
        memset(memo, -1, sizeof memo);
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            long long anst = (comb[n][i] * deragement(n - i)) % mod;
            anst = (anst * mod_pow(2, n - i)) % mod;
            ans = (ans + anst) % mod;
        }

        cout << ans << endl;
    }
    return 0;
}

