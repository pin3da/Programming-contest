// http://codeforces.com/contest/722/problem/A

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

string tos(int a) {
  stringstream ss;
  ss << a;
  string b = ss.str();
  while (b.size() < 2) b = '0'+ b;
  return b;
}

int md(string &a, string &b) {
  int ans = 0;
  for (int i = 0; i < a.size(); ++i)
    ans += a[i] != b[i];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t;
  vector<string> a24, a12;
  for (int i = 0; i < 60 * 24; ++i) {
    a24.push_back(tos(i / 60) + ":" + tos(i % 60));
  }
  for (int i = 0; i < 60 * 12; ++i) {
    a12.push_back(tos(1 + (i / 60)) + ":" + tos(i % 60));
  }

  while (cin >> t) {
    string line; cin >> line;
    string ans;
    if (t == 12) {
      int di = 11111;
      for (int i = 0; i < a12.size(); ++i) {
        if (md(a12[i], line) < di) {
          di = md(a12[i], line);
          ans = a12[i];
        }
      }
    } else {
      int di = 11111;
      for (int i = 0; i < a24.size(); ++i) {
        if (md(a24[i], line) < di) {
          di = md(a24[i], line);
          ans = a24[i];
        }
      }
    }


    cout << ans << endl;
  }

  return 0;
}
