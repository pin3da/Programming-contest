/**
 * NOT SOLVED YET
 * */
using namespace std;
#include <bits/stdc++.h>
#include <thread>
#define D(x) cout << #x " = " << (x) << endl

int next() {
  string buff;
  getline(cin, buff);
  return atoi(buff.c_str());
}


unordered_map<string, int> t;
int ans;
int n;
vector<vector<string>> all;

void fun(int ini, int end) {
  for (int mask = ini; mask < end; ++mask) {
    unordered_map<string, int> type;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < all[i].size(); ++j) {
        if (t.count(all[i][j]) && t[all[i][j]] & 1) {
          type[all[i][j]] |= 1;
        }
        if (t.count(all[i][j]) && t[all[i][j]] & 2) {
          type[all[i][j]] |= 2;
        }
        if ((mask >> i) & 1) { // english
          type[all[i][j]] |= 1;
        } else { // french
          type[all[i][j]] |= 2;
        }
      }
    }
    for (auto &it : t) {
      type[it.first] |= it.second;
    }
    int cur = 0;
    // for (unordered_map<string, int>::iterator it = type.begin(); it != type.end(); ++it) {
    for (auto &it : type) {
      if (it.second == 3) {
        cur++;
      }
    }
    ans = min(ans, cur);
  }
}

  void solve() {
    n = next();
    string english, french;
    getline(cin, english);
    getline(cin, french);

    // unordered_map<string, int> t;
    t.clear();
    string tmp;
    stringstream ss(english);
    while (ss >> tmp) {
      t[tmp] |= 1;
    }

    stringstream st(french);
    while (st >> tmp) {
      t[tmp] |= 2;
    }

    n = n - 2;
    all = vector<vector<string>>(n);
    for (int i = 0; i < n; ++i) {
      tmp;
      getline(cin, tmp);
      stringstream ss(tmp);
      while (ss >> tmp) {
        all[i].push_back(tmp);
      }
    }

    int top = 1 << n;
    ans = 1 << 30;
    vector<thread> task(8);
    int batch = (top + task.size() - 1 ) / task.size();
    for (int i = 0; i < task.size(); ++i) {
      task[i] = thread(fun, batch * i, min(batch * (i + 1), top));//pthread_create( &task[i], NULL, fun, (void*) (batch * i), (void *) top);
    }
    for (int i = 0; i < task.size(); ++i) {
      task[i].join();
    }
    if (ans == (1 << 30)) {
      ans = 0;
      for (auto &it : t) {
        if (it.second == 3)
          ans++;
      }
    }
    cout << ans << endl;
  }

  int main() {
    int tc = next();
    for (int i = 0; i < tc; ++i) {
      cout << "Case #" <<  i + 1 << ": ";
      solve();
    }
    return 0;
  }
