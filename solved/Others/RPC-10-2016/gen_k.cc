#include <bits/stdc++.h>

using namespace std;

const int rounds = 50;
const int MN = 100000;
const int MX = 1000000000 + 1;

int main() {

  srand(time(0));
  for (int k = 0; k < rounds; ++k) {
    int n = MN;
    int m = MN;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i)
      printf("%d %d %d\n", random() % MX, random() % MX, random() % MX);
    for (int i = 0; i < m; ++i)
      printf("%d %d %d\n", random() % MX, random() % MX, random() % MX);
  }

  return 0;
}
