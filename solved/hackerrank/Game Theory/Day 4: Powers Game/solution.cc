#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int mod_pow(int b, int e, int mod = 17) {
  int ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

int main() {
  for (int i = 1; i < 100; ++i)
    cout << mod_pow(2, i) << endl;
  return 0;
}
