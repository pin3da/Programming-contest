// http://codeforces.com/contest/516/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___

  vector<vector<int> > primes(10);
  for (int i = 2; i < primes.size(); i++) {
    int cur = i;
    for (int j = 2; j <= i; j++) {
      while ((cur % j) == 0) {
        primes[i].push_back(j);
        cur /= j;
      }
    }
  }

  int n;
  cin >> n;
  char c;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    cin >> c;
    int cur = c - '0';
    int count =  primes[cur].size();

    if (count > 1) {
      if (cur == 4) {
        ans.push_back(2);
        ans.push_back(2);
        ans.push_back(3);
      }

      if (cur == 6) {
        ans.push_back(3);
        ans.push_back(5);
      }

      if (cur == 8) {
        ans.push_back(2);
        ans.push_back(2);
        ans.push_back(2);
        ans.push_back(7);
      }

      if (cur == 9) {
        ans.push_back(3);
        ans.push_back(3);
        ans.push_back(2);
        ans.push_back(7);

      }
    } else if (primes[cur].size() == 1){
      ans.push_back(cur);
    }
  }

  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }

  cout << endl;


  return 0;
}