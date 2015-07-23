using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
//#define endl '\n'


long long fun(long long p, long long n) {
  long long ans = 0;
  long long b = p;
  while (p <= n) {
    ans += n / p;
    p *= b;
  }
  return ans;
}


int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  vector<int> p;
  p.push_back(2);
  for (int i = 3; i < 100001; ++i) {
    int ok = true;
    for (int j = 0; j < p.size() && ok; ++j) {
      if ((i % p[j]) == 0)
        ok = false;
    }
    if (ok)
      p.push_back(i);
  }
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    long long a = 0, b = 0;
    for (int i = 0; i < p.size(); ++i) {
      if (p[i] <= n) {
        a++;
        b += fun(p[i], n);
      }
    }
    cout << a << " " << b << endl;
  }

  return 0;
}
