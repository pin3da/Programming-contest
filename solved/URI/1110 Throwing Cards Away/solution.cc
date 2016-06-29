#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    deque<int> q;
    for (int i = 1; i <= n; ++i)
      q.push_back(i);

    cout << "Discarded cards: ";
    int first = true;
    while (q.size() > 1) {
      if (!first) cout << ", "; first = false;
      cout << q.front();
      q.pop_front();
      q.push_back(q.front());
      q.pop_front();
    }
    cout << endl << "Remaining card: " << q.front() << endl;
  }

  return 0;
}
