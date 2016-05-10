#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  string line;
  int acc = 0;
  while (cin >> line) {
    if (line == "caw") {
      cin >> line;
      cout << acc << endl;
      acc = 0;
    } else {
      int val = 0;
      for (int i = 0; i < 3; ++i) {
        val <<= 1;
        val += line[i] == '*';
      }
      acc += val;
    }
  }
  return 0;
}
