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


void solve() {
    vector<long long> fact(21);
    fact[0] = 1;
    for (long long i = 1; i < 20; i++) {
       fact[i] = fact[i - 1] * i;
    }

    string line; cin >> line;

    vector<int> frec(30);
    long long den = 1;
    for (int i = 0; i < line.size(); i++) {
        frec[line[i] - 'a']++;
    }
    for (int i = 0; i < frec.size(); i++) {
        den *= fact[frec[i]];
    }
    cout << fact[line.size()] / den << endl;

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#else
    freopen("a1.in", "r", stdin);
#endif
    solve();
  return 0;
}

