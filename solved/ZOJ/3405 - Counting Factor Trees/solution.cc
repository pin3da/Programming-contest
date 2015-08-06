using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
int e[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};


int find_exp(int p, int n) {
  int ans = 0;
  long long b = p;
  while (b <= n) {
    ans += n / b;
    b *= p;
  }
  return ans;
}
long long dp[100];

void solve(long long n) {
  map<int, int> frec;
  int tot = 0;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      frec[i]++;
      tot++;
      n /= i;
    }
  }
  if (n > 1) {
    frec[n]++;
    tot++;
  }

  memset(e, 0, sizeof e);
  for (int i = 0; p[i] <= tot; ++i) {
    e[i] += find_exp(p[i], tot);
    for (map<int, int>::iterator it = frec.begin(); it != frec.end(); ++it) {
      e[i] -= find_exp(p[i], it->second);
    }
  }

  long long ans = 1;
  for (int i = 0; p[i] <= tot; ++i) {
    long long cur = 1;
    for (int j = 0; j < e[i]; ++j) {
      cur *= p[i];
    }
    ans *= cur;
  }

  cout << ans * dp[tot - 1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i < 40; ++i) {
    dp[i] = 0;
    for (int j = 0; j < i; ++j) {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }

  long long int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}

