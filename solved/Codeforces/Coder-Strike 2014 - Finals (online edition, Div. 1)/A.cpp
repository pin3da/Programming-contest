// http://codeforces.com/contest/420/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string symetric = "AHIMOTUVWXY";

bool solve(string &line) {
  for (auto &i : line) {
    if (symetric.find(i) == string::npos)
      return false;
  }
  string t = line;
  reverse(t.begin(), t.end());
  return t == line;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    if (solve(line))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
