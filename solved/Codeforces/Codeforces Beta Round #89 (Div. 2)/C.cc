#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

map<int, int> changes;

int cost(const vector<int> &frec, int t, int k) {
  int missing = k - frec[t];

  changes.clear();

  int total = 0;

  for (int i = 1; missing > 0 && i < 10; i++) {
    if (missing && t + i < 10 && frec[t + i]) {
      total += i * min(missing, frec[t + i]);
      if (missing <= frec[t + i]) {
        changes[t + i] += missing;
        missing = 0;
      } else {
        changes[t + i] += frec[t + i];
        missing -= frec[t + i];
      }
    }
    if (missing && (t - i) >= 0 && frec[t - i]) {
      total += i * min(missing, frec[t - i]);
      if (missing <= frec[t - i]) {
        changes[t - i] += missing;
        missing = 0;
      } else {
        changes[t - i] += frec[t - i];
        missing -= frec[t - i];
      }
    }
  }
  return total;
}

string BuildAns(vector<deque<int>> pos, int id, string ori) {
  string ans = ori;
  for (auto it : changes) {
    while (it.second--) {
      if (it.first > id) {
        ans[pos[it.first].front()] = id + '0';
        pos[it.first].pop_front();
      } else {
        ans[pos[it.first].back()] = id + '0';
        pos[it.first].pop_back();
      }
    }
  }
  return ans;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  vector<int> frec(10);
  vector<deque<int>> pos(10);
  string ans;
  for (int i = 0; i < n; i++) {
    char t;
    cin >> t;
    frec[t - '0']++;
    pos[t - '0'].emplace_back(i);
    ans.push_back(t);
  }

  int id = 0, best = n * 11;
  for (int i = 0; i < 10; i++) {
    int c = cost(frec, i, k);
    if (c < best) {
      best = c;
      id = i;
    } else if (c == best) {
      string ansC = BuildAns(pos, i, ans);
      cost(frec, id, k);
      string ansBest = BuildAns(pos, id, ans);
      if (ansC < ansBest)
        id = i;
    }
  }

  cout << cost(frec, id, k) << endl;
  assert(changes[id] == 0);
  cout << BuildAns(pos, id, ans) << endl;

  return 0;
}
