#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
//#define endl '\n'

using namespace std;

bool is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void solve() {
  string line;
  cin >> line;
  int q; cin >> q;
  vector<char> c, v;
  vector<int> inv(line.size() + 10);
  for (int i = 0; i < line.size(); ++i) {
    if (is_vowel(line[i])) {
      inv[i] = v.size();
      v.push_back(line[i]);
    } else {
      inv[i] = c.size();
      c.push_back(line[i]);
    }
  }

  int o_v = 0, o_c = 0;

  while (q-- > 0) {
    int t, x;
    cin >> t;
    if (t < 2) {
      cin >> x;
      if (t == 0) {
        if (v.size())
          o_v = (o_v + x) % v.size();
      } else {
        if (c.size())
          o_c = (o_c + x) % c.size();
      }
    } else {
      for (int i = 0; i < line.size(); ++i) {
        if (is_vowel(line[i])) {
          putchar(v[(inv[i] - o_v + v.size()) % v.size()]);
        } else
          putchar(c[(inv[i] - o_c + c.size()) % c.size()]);
      }
      //cout << endl;
      puts("");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    // cout << "Caso #" << (i + 1) << ":" << endl;
    printf("Caso #%d:\n", i + 1);;
    solve();
  }
  return 0;
}
