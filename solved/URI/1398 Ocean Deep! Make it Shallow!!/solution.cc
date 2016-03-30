#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int mod = 131071;

int go(string line, int acc) {
  for (int i = 0; i < line.size(); ++i) {
    acc *= 2;
    acc += (line[i] == '1');
    acc %= mod;
  }
  return acc;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;

  int acc = 0;
  while (cin >> line) {
    if (line.back() == '#') {
      if (go(line, acc))
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
      acc = 0;
    } else {
      acc = go(line, acc);
    }
  }
  return 0;
}
