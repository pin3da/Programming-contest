#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long mod = 1000000007;

vector<long long> acc(vector<long long> &a) {
  vector<long long> ans(a.size());
  for (int i = 0; i < (int)a.size(); ++i) {
    ans[i] = a[i];
    if (i) ans[i] = (ans[i] + ans[i - 1]) % mod;
  }
  return ans;
}

long long mult(long long a, long long b) {
  return (a * b) % mod;
}

void solve() {
  int p, q, r;
  cin >> p >> q >> r;
  p++;q++;r++;
  vector<long long> A(p), B(q), C(r);
  for (int i = 1; i < p; ++i) cin >> A[i];
  for (int i = 1; i < q; ++i) cin >> B[i];
  for (int i = 1; i < r; ++i) cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  vector<long long> acc_x = acc(A);
  vector<long long> acc_z = acc(C);

  int j = 0, k = 0;
  long long ans = 0;
  for (int i = 1; i < q; ++i) {
    while (j < p && A[j] <= B[i]) j++;
    if (j >= p || A[j] > B[i]) j--;
    while (k < r && C[k] <= B[i]) k++;
    if (k >= r || C[k] > B[i]) k--;
    long long tmp = mult(j, k);
    tmp = mult(mult(B[i], B[i]), tmp);
    ans = (ans + tmp) % mod;
    ans = (ans + mult(B[i], mult(acc_x[j], k))) % mod;
    ans = (ans + mult(B[i], mult(acc_z[k], j))) % mod;
    ans = (ans + mult(acc_x[j], acc_z[k])) % mod;
  }
  cout << ans << endl;
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    solve();
  }
  return 0;
}
