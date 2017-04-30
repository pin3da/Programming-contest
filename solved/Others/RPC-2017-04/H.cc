#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

int sim(deque<int> &d) {
  while (d.size() > 1) {
    d.push_back(d.front());
    d.pop_front();
    d.pop_front();
  }
  return d.front();
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  long long n;
  while (cin >> n && n) {
    long long ans = 1;
    long long ind = 1;
    while (ind + ans <= n) {
      ind += ans;
      ans <<= 1;
    }
    long long f = n - ind;
    cout << (1 + 2 * f) << endl;
  }
}
