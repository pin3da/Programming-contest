/**
 *  TLE on test 25 ):
 * */

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

const int S = 317;

struct ds {
  deque<int> q;
  unordered_set<int> s;
  ds() {
    s.reserve(S);
  }

  void push_front(int x) {
    q.push_front(x);
    s.insert(x);
  }
  void push_back(int x) {
    q.push_back(x);
    s.insert(x);
  }

  int pop_front() {
    int x = q.front();
    q.pop_front();
    s.erase(x);
    return x;
  }

  int pop_back() {
    int x = q.back();
    q.pop_back();
    s.erase(x);
    return x;
  }

  size_t count(int x) {
    return s.count(x);
  }

  size_t size() {
    return s.size();
  }
};

deque<int> tree;
vector<ds> data;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  data.reserve(S * S);

  int i = 0;
  int pop = 0;
  while (n--) {
    char op; cin >> op;
    if (op == 'F') {
      if (tree.size() == 0 || data[tree.front()].size() >= S) {
        ds cur;
        tree.push_front(data.size());
        data.push_back(cur);
      }

      data[tree.front()].push_front(i);
      pop++;
    } else if (op == 'B') {
      if (tree.size() == 0 || data[tree.back()].size() >= S) {
        ds cur;
        tree.push_back(data.size());
        data.push_back(cur);
      }
      data[tree.back()].push_back(i);
      pop++;
    } else {
      int id;
      cin >> id;
      id--;
      int left = 0;

      int seen = 0;
      for (int j = 0; j < tree.size() && !seen; ++j) {
        if (data[tree[j]].count(id)) {
          deque<int> &cur = data[tree[j]].q;
          for (int k = 0; k < cur.size() && !seen; ++k)
            if (cur[k] == id)
              seen = true;
            else
              left++;
        } else {
          left += data[tree[j]].size();
        }
      }

      int right = pop - left - 1;

      if (left <= right) {
        cout << left << endl;
        while (data[tree.front()].count(id) == 0) {
          int cur = tree.front(); tree.pop_front();
          tree.push_back(cur);
        }
        ds &first = data[tree.front()];

        while (first.q.front() != id) {
          int cur = first.pop_front();
          if (data[tree.back()].size() >= S) {
            ds nnn;
            tree.push_back(data.size());
            data.push_back(nnn);
          }
          data[tree.back()].push_back(cur);
        }

        first.pop_front();
        if (first.size() == 0) {
          tree.pop_front();
        }
      } else {
        cout << right << endl;
        while (data[tree.back()].count(id) == 0) {
          int cur = tree.back(); tree.pop_back();
          tree.push_front(cur);
        }
        ds &first = data[tree.back()];

        while (first.q.back() != id) {
          int cur = first.pop_back();
          if (data[tree.front()].size() >= S) {
            ds nnn;
            tree.push_front(data.size());
            data.push_back(nnn);
          }
          data[tree.front()].push_front(cur);
        }

        first.pop_back();
        if (first.size() == 0) {
          tree.pop_back();
        }
      }

      pop--;
      --i;
    }

    i++;
  }

  return 0;
}
