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

const long long mod = 1000000007;

long long solve(vector<int> &gr) {
    int m = gr.size();
    vector<long long> dp(gr.size());
    dp[0] = gr[0] - (m - 1);
    if (dp[0] < 0)
        return 0;

    dp[0] %= mod;

    for (int i = 1; i < m; i++) {
        if (gr[i] - (m - i - 1) < 0) return 0;
        dp[i] = ((gr[i] - (m - i - 1)) * dp[i - 1]) % mod;
    }
    return dp[m - 1];

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#else
    freopen("h2.in", "r", stdin);
#endif
    long long n, m;
    cin >> n >> m;
    vector<int> ri(n), le(m);
    for (auto &it : ri) cin >> it;
    for (auto &it : le) cin >> it;
    sort(ri.begin(), ri.end());
    sort(le.begin(), le.end());
    if (n < m) {
        cout << 0 << endl;
    } else {
        vector<int> gr(m);
        for (int i = 0; i < m; i++) {
            gr[i] = n - (lower_bound(ri.begin(), ri.end(), le[i]) - ri.begin());
        }
        cout << solve(gr) << endl;
    }
    return 0;
}

