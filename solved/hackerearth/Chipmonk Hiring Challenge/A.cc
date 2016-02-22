#include <iostream>
#define D(x) cout << #x " = " << (x) << endl
using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    n = (n * (n + 1)) >> 1LL;
    if ((k % n) == 0 && k > 0)
      cout << 0 << endl;
    else
      cout << n - (k % n) << endl;
  }
  return 0;
}
