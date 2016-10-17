#include <bits/stdc++.h>

using namespace std;

const int MN = 1e5 + 100;
int a[MN];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int seed = time(0);
  srand(seed);
  int n = atoi(argv[1]);
  for (int i = 0; i < n; ++i) {
    a[i] = random() % 1000000000;
  }
  long long m = random() % (100000LL * 100000LL);
  cout << n << ' ' << m << endl;
  for (int j = 0; j < n; ++j)
    cout << a[j] << ' ';
  cout << endl;

  cerr << "Seed : " << seed << endl;
  return 0;
}
