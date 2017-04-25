// http://codeforces.com/contest/508/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

bool even(char c) {
  int t = c - '0';
  return (t % 2) == 0;
}

int main() { ___
  string line; cin >> line;
  char c = line[line.size() - 1];
  int last = -1;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] < c and even(line[i])) {
      swap(line[i], line[line.size() - 1]);
      cout << line << endl;
      return 0;
    }
    if (even(line[i]))
      last = i;
  }

  if (last >= 0) {
    swap(line[last], line[line.size() - 1]);
    cout << line << endl;
    return 0;

  }
  cout << -1 << endl;

  return 0;
}
