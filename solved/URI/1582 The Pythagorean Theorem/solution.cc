#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


bool pythagorean(long long x, long long y, long long z) {
  vector<long long> a;
  a.push_back(x);
  a.push_back(y);
  a.push_back(z);
  sort(a.begin(), a.end());
  return (a[2] * a[2]) == (a[1] * a[1] + a[0] * a[0]);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long x, y, z;
  while (cin >> x >> y >> z) {
    if (pythagorean(x, y, z))
      cout << ((__gcd(__gcd(x, y), z) == 1) ? "tripla pitagorica primitiva" : "tripla pitagorica") << endl;
    else
      cout << "tripla" << endl;
  }
  return 0;
}
