// http://codeforces.com/contest/451/problem/D

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


int main() {
  string line;
  while (cin >> line) {
    long long a_even = 0, a_odd = 0, b_even = 0, b_odd = 0;
    long long even = 0, odd = 0;
    for (int i = 0; i < line.size(); ++i) {
      odd++;
      if (i & 1) { // odd
        if (line[i] == 'a') {
          even += a_even;
          odd  += a_odd;
          a_odd++;
        } else {
          even += b_even;
          odd  += b_odd;
          b_odd++;
        }
      } else { // even
        if (line[i] == 'a') {
          even += a_odd;
          odd  += a_even;
          a_even++;
        } else {
          even += b_odd;
          odd  += b_even;
          b_even++;
        }
      }
    }
    cout << even << " " << odd << endl;
  }
  return 0;
}
