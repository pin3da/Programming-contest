#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

void solve() {
  long long x, n;
  cin >> x >> n;
  long long total = (n * (n + 1) / 2) - x;
  if ((total & 1) || n <= 3) {
    cout << "impossible" << endl;
  } else {
    vector<int> ans(n + 1);
    ans[x] = 2;
    int left = 1, right = n;
    int color = 0;
    vector<int> acc(2);

    int is_even = (n / 2) & 1;
    while (ans[right] == 2) right--;

    if ((n & 1) == 0) {
      acc[color] += right; ans[right--] = color;
      color ^= 1;
    }

    while(ans[left] == 2) left++;
    while(ans[right] == 2) right--;

    while (left < right) {
      if (((left + 1) == right) && (is_even)) {
        if (acc[color] > acc[color ^ 1])
          color ^= 1;
        acc[color] += right; ans[right--] = color;
        acc[color ^ 1] += left; ans[left++] = color ^ 1;
      } else {
        acc[color] += left; ans[left++] = color;
        acc[color] += right; ans[right--] = color;
      }

      color ^= 1;

      while(ans[left] == 2) left++;
      while(ans[right] == 2) right--;
    }

    if (acc[0] != acc[1]) {
      long long target = total / 2;
      ans = vector<int>(n + 1);
      ans[x] = 2;
      for (int i = n; i > 0; i--) {
        if (i != x && i <= target) {
          ans[i] = 1;
          target -= i;
        }
      }
    }

    for (int i = 1; i <= n; i++)
      cout << ans[i];
    cout << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
