#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n;
  cin >> n;
  set<pair<string, string>> all;
  while (n--) {
    string line;
    cin >> line;
    size_t id = line.find('@');
    string local = line.substr(0, id);
    string provider = line.substr(id + 1, line.size() - id - 1);
    string real;
    for (auto c : local) {
      if (c == '+') break;
      if (c != '.') real.push_back(c);
    }

    all.insert({provider, real});
  }

  cout << all.size() << endl;
  return 0;
}
