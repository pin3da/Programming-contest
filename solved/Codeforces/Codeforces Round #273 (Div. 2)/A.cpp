// http://codeforces.com/contest/478/problem/A

using namespace std;
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


int main() {

  vector<int> n(5);
  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> n[i];
    sum += n[i];
  }

  if (sum % 5 or sum == 0) {
    cout << -1 << endl;
    return 0;
  }

  while ((*min_element(all(n))) != (*max_element(all(n)))) {
    sort(all(n));
    n[0]++;
    n[4]--;
  }

  cout << n[0] << endl;

  return 0;
}