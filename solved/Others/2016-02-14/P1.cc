#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x;
  while (cin >> x && x) {

    int t = 1 << ((x - 1) << 1);
    int a = 0;
    while (t > 0) {
      t /= 10;
      a++;
    }

    a++;
    int p[30];
    p[0] = 1;
    for (int i = 1; i < 30; ++i)
      p[i] = p[i - 1] << 1;

    string f1 = "%" + to_string(a) + "d";
    string f2 = "%" + to_string(a - 1) + "d";
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < x; ++j) {
        if (j)
          printf(f1.c_str(), p[j + i]);
        else
          printf(f2.c_str(), p[j + i]);
      }
      puts("");
    }
    puts("");
  }
  return 0;
}
