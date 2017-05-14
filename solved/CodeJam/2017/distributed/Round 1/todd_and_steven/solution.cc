#include <bits/stdc++.h>

#include "message.h"
#include "todd_and_steven3.h"

#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

long long mod = 1000000007;

long long top;

long long find_greater(long long x) {
  long long lo = 0, hi = top - 1;
  if (GetStevenValue(top - 1) < x) {
    return top;
  }
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (GetStevenValue(mid) < x)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}


long long find_less(long long x) {
  long long lo = 0, hi = top - 1;
  if (GetStevenValue(lo) > x)
    return -1;

  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    if (GetStevenValue(mid) > x)
      hi = mid - 1;
    else
      lo = mid;
  }
  return lo;
}

long long fun(long long i, long long j,
    long long N, long long M, long long cur) {

  long long ans = 0;
  while (i < N && j < M) {
    long long a = GetToddValue(i);
    long long b = GetStevenValue(j);
    if (a < b) {
      ans = (ans + (a ^ cur)) % mod;
      i++;
    } else if (b < a) {
      ans = (ans + (b ^ cur)) % mod;
      j++;
    } else {
      assert(false);
    }
    cur++;
  }
  while (i < N) {
    long long a = GetToddValue(i);
    ans = (ans + (a ^ cur)) % mod;
    i++;
    cur++;
  }
  while (j < M) {
    long long b = GetStevenValue(j);
    ans = (ans + (b ^ cur)) % mod;
    j++;
    cur++;
  }
  return ans;
}

int main() {
  int nodes = NumberOfNodes();
  long long N = GetToddLength();
  long long M = GetStevenLength();
  top = M;
  int id = MyNodeId();
  long long bucket_size = (N + nodes - 1) / nodes;

  long long cur_val = 0;
  if (id * bucket_size < N) {
    long long startA = min(id * bucket_size, N - 1);
    long long endA = min(startA + bucket_size, N);
    long long startB = find_less(GetToddValue(startA));
    long long endB = find_less(GetToddValue(endA - 1)) + 1;
    long long cur = startA + startB;
    // cout << startA << " " << endA << " " << startB << " " << endB << endl;
    cur_val = (cur_val + fun(startA, startB, endA, endB, cur)) % mod;
  } else if ((id - 1) * bucket_size < N) {
    long long startB = find_greater(GetToddValue(N - 1));
    long long cur = N + startB;
    cur_val = (cur_val + fun(0, startB, -1, M, cur)) % mod;
  }
  PutLL(0, cur_val);
  Send(0);

  if (id == 0) {
    long long ans = 0;
    for (int i = 0; i < nodes; ++i) {
      Receive(i);
      ans = (ans + GetLL(i)) % mod;
    }
    cout << ans << endl;
  }

  return 0;
}
