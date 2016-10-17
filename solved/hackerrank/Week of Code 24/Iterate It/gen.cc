#include <bits/stdc++.h>

using namespace std;

const int MVAL = 100;

int main(int argc, char **argv) {
  int n = (argc > 1) ? atoi(argv[1]) : 100;
  srand(time(0));
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%d", 1 + int(random() % MVAL));
  }
  puts("");
  return 0;
}
