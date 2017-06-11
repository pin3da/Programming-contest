#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl

#include "message.h"
#include "broken_memory.h"

using namespace std;

int main() {
  int nodes = NumberOfNodes();
  int id = MyNodeId();
  int N = GetLength();
  for (int i = 0; i < N; ++i) {
    PutLL(0, GetValue(i));
  }
  Send(0);

  if (id == 0) {
    vector<vector<long long>> all(nodes, vector<long long> (N));
    for (int i = 0; i < nodes; ++i) {
      Receive(i);
      for (int j = 0; j < N; ++j) {
        all[i][j] = GetLL(i);
      }
    }
    for (int i = 0; i < nodes; ++i) {
      if (i) cout << ' ';
      for (int j = 0; j < N; ++j) {
        int prev = (i - 1 + nodes) % nodes;
        int next = (i + 1) % nodes;
        if ((all[i][j] != all[prev][j]) && (all[i][j] != all[next][j])) {
          cout << j;
          break;
        }
      }
    }
    cout << endl;
  }
  return 0;
}

