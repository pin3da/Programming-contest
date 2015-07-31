using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  unordered_map<int, int> b (n * n * n);
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        int v2 = (nums[i] + nums[j]) * nums[k];
        if (nums[k] != 0)
          b[v2]++;
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        int v1 = nums[i] * nums[j] + nums[k];
        if (b.count(v1)) {
          ans += b[v1];
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
