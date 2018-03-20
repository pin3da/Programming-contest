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

double dp[(1 << 20) + 10];
double go(vector<double> &p, int mask) {
    if (mask == 0) return 0; // no falta nada

    if (dp[mask] > -1) return dp[mask];
    double prep = 0;
    for (int j = 0; j < p.size(); j++) {
        if (((mask >> j) & 1) == 0) prep += p[j];
    }
    double tmp = 0;
    for (int j = 0; j < p.size(); j++) {
        if ((mask >> j) & 1) {
            int nxt = mask ^ (1 << j);
            tmp += (1 + go(p, nxt)) * p[j];
        }
    }
    double ans = (tmp + prep) / (1.0 - prep);
    return dp[mask] = ans;
}


void solve() {
    int n; cin >> n;
    vector<double> a(n);
    for (auto &i : a) cin >> i;
    double total = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < n; i++) a[i] /= total;
    int top = (1 << n) - 1;
    for (int i = 0; i < (1 << 20); i++) dp[i] = -10;
    cout << fixed << setprecision(8);
    cout << go(a, top) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#else
    freopen("b1.in", "r", stdin);
#endif
    solve();
  return 0;
}

