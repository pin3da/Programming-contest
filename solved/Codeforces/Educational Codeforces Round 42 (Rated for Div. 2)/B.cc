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
  int n, a, b;
  read(n, a, b);
  string line;
  cin >> line;
  line.push_back('*');
  vector<int> len;
  int last = 0;
  for (int i = 0; i < int(line.size()); i++) {
    if (line[i] == '*') {
      if (i - last)
        len.push_back(i - last);
      last = i + 1;
    }
  }

  int total = a + b;
  for (auto l : len) {
    int x = l / 2;
    int y = l - x;

    if (a < b) swap(a, b);
    a -= y;
    b -= x;
  }
  a = max(a, 0);
  b = max(b, 0);
  cout << (total - a - b) << endl;
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

