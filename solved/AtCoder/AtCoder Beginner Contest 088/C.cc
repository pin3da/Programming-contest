#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

int g[3][3];
int g2[3][3];
int s[3];

bool test(int b) {
  int ok = true;
  for (int r = 0; r < 3; r++) {
    ok &= (((s[r] - b) % 3) == 0);
  }
  if (!ok)
    return false;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      g2[i][j] = g[i][j] - (s[i] - b) / 3;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ok &= g2[j][i] == g2[0][i];
    }
  }
  return ok;
}

void solve() {
  int total = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> g[i][j];
      total += g[i][j];
      s[i] += g[i][j];
    }
  }

  for (int b = 0; b <= total; b++) {
    if (test(b)) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
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

