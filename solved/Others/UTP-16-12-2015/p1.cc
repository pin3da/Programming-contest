using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int next_int() {
  string line; getline(cin, line); return atoi(line.c_str());
}

int dp[222][222];
bool go(vector<int> &a, int i, int sum, int &total) {
  if (i == a.size())
    return total - sum == sum;
  if (dp[i][sum] != -1) return dp[i][sum];
  return dp[i][sum] = (go(a, i + 1, sum + a[i], total) || go(a, i + 1, sum, total));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n = next_int();
  while (n--) {
    string line; getline(cin, line);
    stringstream ss(line);
    vector<int> a;
    int t;
    int total = 0;
    while (ss >> t) {
      a.push_back(t);
      total += t;
    }
    memset(dp, -1, sizeof dp);
    if (go(a, 0, 0, total))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
