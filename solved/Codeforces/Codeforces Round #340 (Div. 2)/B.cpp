// http://codeforces.com/contest/617/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


void solve(int n) {
  deque<int> a(n);
  int ones = 0;
  for (auto &i : a) {
    cin >> i;
    if (i) ones++;
  }

  if (ones <= 1) {
    cout << ones << endl;
    return;
  }

  while (a.size() && (a.front() == 0)) a.pop_front();
  while (a.size() && (a.back() == 0)) a.pop_back();

  int accum = 1;
  long long ways = 1;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i]) {
      ways *= accum;
      accum = 1;
    } else {
      accum++;
    }
  }
  ways *= accum;
  cout << ways << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n) {
    solve(n);
  }

  return 0;
}