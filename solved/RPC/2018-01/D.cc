#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);   debug_out(t...); }

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#define endl '\n'
#endif


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line; cin >> line;
  string s = line;
  sort(s.begin(), s.end());

  swap(line, s);

  debug(line);

  for (int i = 0; i < int(line.size()); i++) {
    if (line[i] == s[i]) continue;
    for (int j = i + 1; j < int(line.size()); j++) {
      if (line[j] == s[i]) {
        int a = i, b = j;
        if (line[i] < line[j])
          swap(a, b);
        cout << (a + 1) << " " << (b + 1) << endl;
        swap(line[i], line[j]);
        break;
      }
    }
  }
  debug(line);

  return 0;
}
