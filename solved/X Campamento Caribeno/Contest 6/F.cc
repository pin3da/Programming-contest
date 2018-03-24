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

int get(char s) {
  if (s >= '0' && s <= '9') return s - '0';
  return (s - 'A') + 10;
}

long long eval(string &a) {
  long long fact = 1, cur = 2;
  long long acc = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    acc += get(a[i]) * fact;
    fact *= cur++;
  }
  return acc;
}

char inv(long long n) {
  if (n < 10)
    return '0' + n;
  return 'A' + (n - 10);
}

string conv(long long n) {
  long long fact = 1;
  string ans;
  while (n) {
    ans.push_back(inv(n % (fact + 1)));
    n /= (fact + 1);
    fact++;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

void solve() {
  long long ans = 0;
  string line; cin >> line;
  deque<int> nxt;
  deque<char> ops;
  for (int i = 0; i < int(line.size()); i++) {
    if ((line[i] == '+') || (line[i] == '-')) {
      nxt.push_back(i);
      ops.push_back(line[i]);
    }
  }
  nxt.push_back(line.size());
  deque<long long> values;
  int pos = 0;
  while (pos < int(line.size())) {
    string cur = line.substr(pos, nxt.front() - pos);
    pos = nxt.front() + 1;
    nxt.pop_front();
    values.push_back(eval(cur));
  }

  ans = values[0];
  for (int i = 0; i < int(ops.size()); i++) {
    if (ops[i] == '+')
      ans += values[i + 1];
    else
      ans -= values[i + 1];
  }

  cout << conv(ans) << endl;
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

