#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

void solve() {
  string line;
  cin >> line;
  deque<char> q;
  q.push_back(line[0]);

  for (int i = 1; i < line.size(); ++i) {
    if (q.front() <= line[i])
      q.push_front(line[i]);
    else
      q.push_back(line[i]);
  }

  for (int i = 0; i < line.size(); ++i)
    cout << q[i];
  cout << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  int c = 1;
  while (tc--) {
    cout << "Case #"  << (c++) << ": ";
    solve();
  }
  return 0;
}
