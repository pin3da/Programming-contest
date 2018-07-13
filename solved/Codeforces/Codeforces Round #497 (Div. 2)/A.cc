#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


string vowel = "aeiou";

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  string line;
  cin >> line;
  int ok = true;
  for (int i = 1; i < int(line.size()); i++) {
    if (vowel.find(line[i - 1]) == string::npos) {
      if (line[i - 1] == 'n') continue;
      ok &= (vowel.find(line[i]) != string::npos);
    }
  }
  if (vowel.find(line.back()) == string::npos) {
    if (line.back() != 'n') ok = false;
  }

  puts(ok ? "YES" : "NO");
  return 0;
}
