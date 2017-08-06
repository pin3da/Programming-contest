#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


bool check(char a, char b, char c) {
  vector<char> t = {a, b, c};
  sort(t.begin(), t.end());
  return t[0] == 'B' &&  t[1] == 'L' &&  t[2] == 'R';
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line;
  cin >> line;
  string ans;
  int n = line.size();
  string tmp;
  for (int i = 0; i < n; i++) {
    if (i + 2 < n && check(line[i], line[i + 1], line[i + 2])) {
      tmp.push_back('C');
      i += 2;
    } else {
      tmp.push_back(line[i]);
    }
  }
  for (auto i : tmp) {
    if (i == 'R') cout << 'S';
    else if (i == 'B') cout << 'K';
    else if (i == 'L') cout << 'H';
    else cout << i;
  }
  cout << endl;

  return 0;
}
