using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long lcm(long long a, long long b) {
  return a * (b / __gcd(a, b));
}

void solve(int n) {
  while (n--) {
    long long a, c;
    cin >> a >> c;
    if (c % a) {
      cout << "NO SOLUTION" << endl;
      continue;
    }
    long long t = c / a;
    while (lcm(t, a) != c) {
      t += c / a;
    }
    cout << t << endl;
  }
}

int main() {
  int n;
  while(cin >> n)
    solve(n);
  return 0;
}
