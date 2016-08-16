#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

struct bigint {
  deque<int> q;
  bigint () {}
  bigint (string a) {
    q.clear();
    for (int i = 0; i < a.size(); ++i)
      q.push_front(a[i] - '0');
  }

  bigint (const bigint &a) {
    q = a.q;
  }

  bool operator < (const bigint &o) const {
    return q < o.q;
  }

  bigint operator + (const bigint &o) const {
    bigint ans;
    int carry = 0;
    int mmin = min(o.q.size(), q.size());
    for (int i = 0; i < mmin; ++i) {
      int cur = (o.q[i] + q[i] + carry);
      ans.q.push_back(cur % 10);
      carry = cur / 10;
    }
    for (int i = mmin; i < o.q.size(); ++i) {
      int cur = o.q[i] + carry;
      ans.q.push_back(cur % 10);
      carry = cur / 10;
    }
    for (int i = mmin; i < q.size(); ++i) {
      int cur = q[i] + carry;
      ans.q.push_back(cur % 10);
      carry = cur / 10;
    }
    if (carry)
      ans.q.push_back(carry);
    return ans;
  }

  void print() {
    for (int i = q.size() - 1; i >= 0; --i) {
      cout << q[i];
    }
    cout << endl;
  }
};

bool is_creeper1(bigint &c) {
  int n = c.q.size() - 1;
  if (c.q.size() < 8) return false;
  deque<int> &q = c.q;
  if (q[n] != 1 || q[n - 1] != 2 || q[n - 2] != 3 || q[n - 3] != 3)
    return false;

  for (int i = 4; i < q.size() - 4; ++i)
    if (q[n - i] != 3) return false;

  for (int i = 0; i < 4; ++i)
    if (q[i] != 4) return false;
  return true;
}

bool is_creeper2(bigint &c) {
   int n = c.q.size() - 1;
  if (c.q.size() < 8) return false;
  deque<int> &q = c.q;
  if (q[n] != 5 || q[n - 1] != 5 || q[n - 2] != 6 || q[n - 3] != 6)
    return false;

  for (int i = 4; i < q.size() - 4; ++i)
    if (q[n - i] != 6) return false;

  for (int i = 0; i < 4; ++i)
    if (q[i] != 7) return false;
  return true;
}

bigint comp_next(bigint c) {
  bigint d(c);
  reverse(d.q.begin(), d.q.end());
  bigint f = d + c;
  sort(f.q.rbegin(), f.q.rend());
  while (f.q.size() > 1 && f.q.back() == 0) f.q.pop_back();
  return f;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int p; cin >> p;
  while (p--) {
    int m, k;
    string number;
    cin >> k >> m >> number;
    bigint cur(number);
    set<bigint> seen;
    cout << k << ' ';
    int p = 0;
    for (int i = 0; i < m; ++i) {
      if (is_creeper1(cur) || is_creeper2(cur)) {
        cout << "C " <<  i + 1 << endl;
        p = 1;
        break;
      }
      if (seen.count(cur)) {
        cout << "R " << i + 1 << endl;
        p = 1;
        break;
      }
      seen.insert(cur);
      if (i + 1 < m)
        cur = comp_next(cur);
    }
    if (!p)
      cur.print();
  }
  return 0;
}
