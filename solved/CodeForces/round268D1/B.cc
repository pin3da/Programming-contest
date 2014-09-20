using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


struct mio {
  long long val;
  int id;
  mio () {}
  mio (long long a, int b) : val(a) , id(b)  {}
  bool operator < (const mio &o ) const {
    if (val == o.val)
      return id < o.id;
    return val < o.val;
  }
};



int main () { ___

  int n;
  long long a , b;
  cin >> n >> a >> b;
  map<long long , deque<int> > idx;
  set<long long> cur;
  vector<int> ans(n,-1);
  long long tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    cur.insert(tmp);
    idx[tmp].push_back(i);
  }

  int ok = 1;
  while (!cur.empty() and ok) {
    long long first = (*cur.begin());
    if (cur.count(a - first) and cur.count(b - first)) {
      if (idx[a - first].size() < idx[b - first].size()) {
        while (!idx[first].empty() and !idx[a - first].empty()) {
          ans[idx[first].back()] = 0;
          idx[first].pop_back();
          if (idx[a - first].empty()) {
            ok = 0;
            break;
          }
          ans[idx[a - first].back()] = 0;
          idx[a - first].pop_back();
        }
        cur.erase(cur.begin());
        if (cur.find(a - first) != cur.end())
          cur.erase(cur.find(a - first));
        if (!idx[first].empty())
          cur.insert(first);
        if (!idx[a - first].empty())
          cur.insert(a - first);
      } else {
        while (idx[first].size() > 0 and idx[b - first].size() > 0) {
          ans[idx[first].back()] = 1;
          idx[first].pop_back();
          if (idx[b - first].empty()) {
            ok = 0;
            break;
          }
          ans[idx[b - first].back()] = 1;
          idx[b - first].pop_back();
        }
        cur.erase(cur.begin());
        if (cur.find(b - first) != cur.end())
          cur.erase(cur.find(b - first));
        if (idx[first].size())
          cur.insert(first);
        if (idx[b - first].size())
          cur.insert(b - first);
      }

    } else if (cur.find(a - first) != cur.end()) {
      while (!idx[first].empty() and !idx[a - first].empty()) {
        ans[idx[first].back()] = 0;
        idx[first].pop_back();
        if (idx[a - first].empty()) {
          ok = 0;
          break;
        }
        ans[idx[a - first].back()] = 0;
        idx[a - first].pop_back();
      }

      cur.erase(cur.begin());
      if (cur.find(a - first) != cur.end())
        cur.erase(cur.find(a - first));
      if (!idx[first].empty())
        cur.insert(first);
      if (!idx[a - first].empty())
        cur.insert(a - first);
    } else if (cur.count(b - first) > 0) {

      while (idx[first].size() > 0 and idx[b - first].size() > 0) {
        ans[idx[first].back()] = 1;
        idx[first].pop_back();
        if (idx[b - first].empty()) {
          ok = 0;
          break;
        }
        ans[idx[b - first].back()] = 1;
        idx[b - first].pop_back();
      }
      cur.erase(cur.begin());
      if (cur.find(b - first) != cur.end())
        cur.erase(cur.find(b - first));
      if (idx[first].size())
        cur.insert(first);
      if (idx[b - first].size())
        cur.insert(b - first);
    } else {
      ok  = 0;
    }
  }

  if (!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;

  }
  return 0;
}
