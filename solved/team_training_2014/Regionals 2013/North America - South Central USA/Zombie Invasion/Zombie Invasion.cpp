using namespace std;
#include<bits/stdc++.h>

void solve() {
  vector<int> cur(20);
  for (int i = 0; i< 20; ++i)
    cin>>cur[i];

  for (int i = 19; i > 0; --i) {
    cur[i - 1] += cur[i] / 2;
    cur[i] %= 2;
  }

  for (int i = 0; i < 20; ++i) {
    if (i) cout<<" ";
    cout<<cur[i];
  }

  cout<<endl;
}

int main() {

  int tc;cin>>tc;
  for (int i = 0; i< tc; ++i)
    solve();
  return 0;
}

