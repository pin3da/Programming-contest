// http://codeforces.com/contest/614/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool valid(string &s) {
  vector<int> f(10);
  for (int i = 0; i < s.size(); ++i) {
    f[s[i] - '0']++;
  }
  if (f[1] > 1) return false;
  for (int i = 2; i < 10; ++i) if (f[i]) return false;
  return true;
}
void solve(int n) {
  vector<string> a(n);
  int zero = false;
  string first;
  int total = 0;
  for (auto &i: a) {
    cin >> i;
    if (i == "0") zero = true;
    if (!valid(i)) {
      first = i;
    } else {
      total += i.size() - 1;
    }
  }

  if (zero) {
    cout << 0 << endl;
    return;
  }
  if (first == "") first = "1";
  cout << first << string(total, '0') << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
