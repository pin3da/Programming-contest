#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl

#include "message.h"
#include "broken_memory.h"

using namespace std;

int main() {
  int nodes = NumberOfNodes();
  int id = MyNodeId();
  int N = GetLength();
  vector<long long> acc(N + 1);
  for (int i = 0; i < N; ++i)
    acc[i + 1] = GetValue(i);

  for (int i = 1; i <= N; ++i)
    acc[i] ^= acc[i - 1];

  int seen = 0;
  int left = 0;
  vector<long long> broken(nodes);
  map<long long, vector<long long>> ans;
  while (seen < nodes) {
    int lo = left, hi = N;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      long long val = acc[mid];
      PutLL(0, val);
      Send(0);

      if (id == 0) {
        vector<long long> all(nodes);
        for (int i = 0; i < nodes; ++i) {
          Receive(i);
          all[i] = GetLL(i);
        }
        int diff = false;
        for (int i = 0; i < nodes; ++i) {
          if (all[i] != all[0])
            diff = true;
        }
        for (int i = 0; i < nodes; ++i) {
          PutLL(i, diff);
          Send(i);
        }
        ans[mid] = all;
      }
      Receive(0);
      int diff = GetLL(0);
      if (diff) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    seen++;
    if (id == 0) {
      map<long long, vector<int>> frec;
      for (int i = 0; i < nodes; ++i) {
        frec[ans[lo][i]].push_back(i);
      }

      long long correct;
      int idx;
      for (auto &it: frec) {
        if (it.second.size() == 1) {
          broken[it.second[0]] = lo;
          idx = it.second[0];
        } else {
          correct = it.first;
        }
      }

      for (int i = 0; i < nodes; ++i) {
        PutInt(i, lo);
        PutLL(i, i == idx ? correct: -1);
        Send(i);
      }
    }

    Receive(0);
    int idx = GetInt(0);
    long long val = GetLL(0);
    if (val >= 0) {
      cout << "update " << idx << " with " << val << " in node " << id << endl;
      acc[idx] = val;
      for (int i = idx; i <= N; ++i)
        acc[i] ^= acc[i - 1];
    }
  }

  if (id == 0) {
    for (int i = 0; i < nodes; ++i) {
      if (i) cout << ' ';
      cout << broken[i];
    }
    cout << endl;
  }

  return 0;
}

