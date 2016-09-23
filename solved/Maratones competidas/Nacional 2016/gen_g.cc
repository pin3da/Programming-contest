#include <bits/stdc++.h>

using namespace std;

const int CASES = 100;
const int MK = 10000;
const int MQ = 500;

int main() {
  srand(time(0));
  cout << CASES << endl;
  for (int i = 0; i < CASES; ++i) {
    int k = (random() % MK) + 2;
    int q = (random() % MQ);
    cout << dec << k << ' ' << q << endl;
    int len = (k + 3) / 4;
    for (int i = 0; i < len; ++i) {
      cout << uppercase << hex << (random() % 16);
    }
    cout << endl;
    for (int i = 0; i < q; ++i) {
      int a = random() % k + 1;
      int b = random() % k + 1;
      if (b < a) swap(a, b);
      cout << dec << a << ' ' << b << endl;
    }
    cout << endl;
  }
  return 0;
}
