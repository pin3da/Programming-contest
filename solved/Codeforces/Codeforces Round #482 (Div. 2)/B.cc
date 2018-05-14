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


int most_frecuent(string &s) {
  map<char, int> f;
  for (auto c : s) f[c]++;
  int best = 0;
  for (auto it : f) {
    best = max(best, it.second);
  }
  return best;
}

const string names[] = {"Kuro", "Shiro", "Katie"};

void solve() {
  int n; cin >> n;
  vector<string> ribbons(3);
  read(ribbons);

  vector<int> frec(3);
  for (int i = 0; i < 3; i++) {
    frec[i] = most_frecuent(ribbons[i]);
  }

  vector<int> points(3);
  set<int> winner;
  int best = 0;
  for (int i = 0; i < 3; i++) {
    int extra = ribbons[i].size() - frec[i];
    if (extra >= n) {
      points[i] = frec[i] + n;
    } else {
      points[i] = min<int>(ribbons[i].size(), frec[i] + n) - (n == 1);
    }
    best = max(best, points[i]);
  }
  for (int i = 0; i < 3; i++) {
    if (points[i] == best)
      winner.insert(i);
  }
  if (winner.size() > 1) {
    cout << "Draw" << endl;
  } else {
    cout << names[*winner.begin()] << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

