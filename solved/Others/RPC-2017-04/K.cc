#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> sliding_window_minmax(vector<int> & ARR, int K, bool mx) {
  deque< pair<int, int> > window;
  vector<int> ans;
  for (int i = 0; i < ARR.size(); i++) {
    if (mx) {
      while (!window.empty() && window.back().first <= ARR[i])
        window.pop_back();
    } else {
      while (!window.empty() && window.back().first >= ARR[i])
        window.pop_back();
    }
    window.push_back(make_pair(ARR[i], i));

    while(window.front().second <= i - K)
      window.pop_front();

    ans.push_back(window.front().first);
  }
  return ans;
}

bool solver(vector<int> &v, int n, int w, int k) {
  vector<int> minIn = sliding_window_minmax(v, w, 0);
  vector<int> maxIn = sliding_window_minmax(v, w, 1);
  for (int i = w; i < n; i++) {
    if (minIn[i - 1] < v[i] - k or maxIn[i - 1] > v[i] + k)
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, w, k;
  while (cin >> n >> w >> k and (n or w or k)) {
    vector<int> input(n);
    for (int i = 0; i < n; i++)
      cin >> input[i];
    bool ans = solver(input, n, w, k);
    cout << ((ans)? "Yes." : "No.") << endl;
  }
  return 0;
}
