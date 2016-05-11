#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a(4);
  for (auto &i : a) cin >> i;
  cout << accumulate(a.begin(), a.end(), - 3) << endl;
  return 0;
}

