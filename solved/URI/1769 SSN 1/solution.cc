#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    vector<int> a(9);
    for (int i = 0; i < 3; ++i) a[i] = line[i] - '0';
    for (int i = 0; i < 3; ++i) a[i + 3] = line[i + 4] - '0';
    for (int i = 0; i < 3; ++i) a[i + 6] = line[i + 8] - '0';

    int b1 = line[12] - '0';
    int b2 = line[13] - '0';
    int f = 0, p = 0;
    for (int i = 0; i < 9; ++i) {
      f += a[i] * (i + 1);
      p += a[i] * (9 - i);
      f %= 11;
      p %= 11;
    }
    if (f == 10) f = 0;
    if (p == 10) p = 0;
    if (b1 == f && b2 == p) {
      cout << "CPF valido" << endl;
    } else {
      cout << "CPF invalido" << endl;
    }

  }
  return 0;
}
