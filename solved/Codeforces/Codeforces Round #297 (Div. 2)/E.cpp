// http://codeforces.com/contest/525/problem/E

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long fact[20], total, s;
unordered_map<long long, long long> ans[26];
int half, n, k;

void gen(const vector<int> &a, int pos, int used, long long sum) {
  if (sum > s)
    return;
  if (used > k)
    return;
  if (pos >= half) {
    for (int i = used; i <= k; ++i)
      ans[i][sum]++;
    return;
  }

  gen(a, pos + 1, used, sum);
  gen(a, pos + 1, used, sum + a[pos]);
  if (a[pos] < 20)
    gen(a, pos + 1, used + 1, sum + fact[a[pos]]);
}

void solve(const vector<int> &a, int pos, int used, long long sum) {
  if (sum > s)
    return;
  if (used > k)
    return;
  if (pos >= a.size()) {
    long long missing = s - sum;
    if (ans[k - used].count(missing))
      total += ans[k - used][missing];
    return;
  }

  solve(a, pos + 1, used, sum);
  solve(a, pos + 1, used, sum + a[pos]);
  if (a[pos] < 20)
    solve(a, pos + 1, used + 1, sum + fact[a[pos]]);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  for (int i = 1; i < 20; ++i) {
    fact[i] = fact[i - 1] * (long long) (i);
  }

  cin >> n >> k >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  half = n / 2;
  total = 0;
  gen(a, 0, 0, 0);
  solve(a, half, 0, 0);
  cout << total << endl;
}

