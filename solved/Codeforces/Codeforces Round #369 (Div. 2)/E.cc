#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const long long mod = 1000003;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, k;
  while (cin >> n >> k) {
    if (n < 61) {
      if (k > (1LL << n)) {
        cout << "1 1" << endl;
      }
    } else {

    }
  }

  return 0;
}
