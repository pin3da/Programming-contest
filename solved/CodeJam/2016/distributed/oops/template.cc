#include <bits/stdc++.h>

#include "message.h"
#include "oops.h"

using namespace std;
long long inf = numeric_limits<long long>::max() / 2;

#define MASTER_NODE 0

void task() {
  int n = GetN();
  int nodes = NumberOfNodes();
  int id = MyNodeId();
  int bucket_size = (n + nodes - 1) / nodes;
  int start = bucket_size * id;
  int end = start + bucket_size;
  long long local_min = inf, local_max = -inf;
  for (int i = start; i < end && i < n; ++i) {
    long long cur = GetNumber(i);
    local_min = min(local_min, cur);
    local_max = max(local_max, cur);
  }
  PutLL(MASTER_NODE, local_min);
  PutLL(MASTER_NODE, local_max);
  Send(MASTER_NODE);

  if (id == MASTER_NODE) {
    long long mmin = inf, mmax = -inf;
    for (int i = 0; i < nodes; ++i) {
      Receive(i);
      local_min = GetLL(i);
      local_max = GetLL(i);
      mmin = min(mmin, local_min);
      mmax = max(mmax, local_max);
    }
    cout << max(0LL, mmax - mmin) << endl;
  }
}

int main(int argc, char **argv) {
  task();
  return 0;
}
