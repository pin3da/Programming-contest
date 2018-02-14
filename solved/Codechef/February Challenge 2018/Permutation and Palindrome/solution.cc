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


void solve() {
  string line; cin >> line;

  vector<vector<int>> frec(30);
  for (int i = 0; i < int(line.size()); i++) {
    frec[line[i] - 'a'].emplace_back(i);
  }

  vector<int> alone;
  deque<int> front, back;
  for (auto &it : frec) {
    if (it.size() & 1) {
      alone.push_back(it.back() + 1);
      it.pop_back();
    }
    for (int i = 0; i < int(it.size()); i += 2) {
      front.push_back(it[i] + 1);
      back.push_front(it[i + 1] + 1);
    }
  }

  if (alone.size() > 1)
    cout << -1 << endl;
  else {
    for (auto it : front)
      cout << it << " ";
    if (alone.size())
      cout << alone[0] << " ";
    for (auto it : back)
      cout << it << " ";
    cout << endl;
  }

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}

