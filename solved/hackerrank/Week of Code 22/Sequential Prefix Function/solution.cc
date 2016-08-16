#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void kmp(deque<int> &word, deque<int> &border) {
  if (word.size() == 1) return;

  int i = word.size() - 1;
  border[i] = border[i - 1];
  while (border[i] > 0 && word[i] != word[border[i]])
    border[i] = border[border[i] - 1];
  if (word[i] == word[border[i]]) border[i]++;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  deque<int> q;
  deque<int> border(n);
  while (n--) {
    char t; int x;
    cin >> t;
    if (t == '-') {
      q.pop_back();
    } else {
      cin >> x;
      q.push_back(x);
      kmp(q, border);
    }
    if (q.size())
      cout << border[q.size() - 1] << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}
