#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a(4);
  for (auto &i : a) cin >> i;
  sort(a.rbegin(), a.rend());
  if ((a[0] < a[1] + a[2]) || (a[1] < a[2] + a[3]))
    cout << "S" << endl;
  else
    cout << "N" << endl;
  return 0;
}

