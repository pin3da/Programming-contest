#include <bits/stdc++.h>

#include "message.h"
#include "pancakes.h"

using namespace std;

int main() {
  int nodes = NumberOfNodes();
  int N = GetStackSize();
  int D = GetNumDiners();
  int bucket_size = (N + nodes - 1) / nodes;

  int id = MyNodeId();
  int ans = 0;
  if (id * bucket_size < N) {
    int start = min(id * bucket_size, N - 1);
    int end = min(start + bucket_size, N);
    int last = (start == 0)? D + 10 : GetStackItem(start - 1);
    for (int j = start; j < end; ++j) {
      int current = GetStackItem(j);
      if (current < last) {
        ans++;
      }
      last = current;
    }
  }
  PutInt(0, ans);
  Send(0);

  if (id == 0) {
    long long acc = 0;
    for (int i = 0; i < nodes; ++i) {
      Receive(i);
      int cur = GetInt(i);
      acc += cur;
    }
    cout << acc << endl;
  }

  return 0;
}
