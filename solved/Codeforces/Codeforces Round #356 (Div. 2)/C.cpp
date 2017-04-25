// http://codeforces.com/contest/680/problem/C

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int divs = 0;
  string line;
  vector<int> div(15);
  for (int i = 0; i < 15; ++i) {
    cout << primes[i] << endl;
    cin >> line;
    if (line == "yes") divs++;
    div[i] = line == "yes";
  }
  if (divs > 1)
    cout << "composite" << endl;
  else {
    for (int i = 0; i < 4; ++i) {
      cout << primes[i] * primes[i] << endl;
      cin >> line;
      if (line == "yes") divs++;
    }
    if (divs > 1)
      cout << "composite" << endl;
    else
      cout << "prime" << endl;
  }
  return 0;
}
