#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main(int argc, char  **argv) {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  srand(time(0));

  int n = atoi(argv[1]);
  int q = n;
  cout << n << " " << q << endl;
  int base = 1e9;
  for (int i = 0; i < n; i++) {
    long long t = random() % (2LL * base);
    t -= base;
    cout << " " << t;
  }
  cout << endl;
  while (q--) {
    int i = random() % (n - 1) + 1;
    int k = random() % i;
    int l = random() % (n - 1) + 1;
    cout << k << " " << i << " " << l << endl;
  }
  return 0;
}
