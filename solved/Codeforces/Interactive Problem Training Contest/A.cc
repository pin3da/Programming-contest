#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int lo = 1, hi = 1000000;
  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    cout << mid << endl;
    string ans; cin >> ans;
    if (ans == "<")
      hi = mid - 1;
    else
      lo = mid;
  }
  cout << "! " << lo << endl;
  return 0;
}
