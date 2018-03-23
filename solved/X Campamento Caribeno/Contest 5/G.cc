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

typedef vector<vector<int>> graph;

int mex[22];

void solve() {
    int k; cin >> k;
    vector<int> moves(k);
    read(moves);
    vector<int> grundy(1000000 + 100);
    for (int i = 0; i < grundy.size(); i++) {
        memset(mex, 0, sizeof mex);
        for (auto m : moves) {
            if (i < m) continue;
            int g = grundy[i - m];
            if (g < 22) mex[g] = true;
        }
        for (int j = 0; j < 22; j++) {
            if (mex[j] == 0) {
                grundy[i] = j;
                break;
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        puts(grundy[n] > 0 ? "First" : "Second");
    }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#else
    freopen("g1.in", "r", stdin);
#endif
    solve();
  return 0;
}

