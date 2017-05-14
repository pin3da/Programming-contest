#include <bits/stdc++.h>

#include "message.h"
#include "todd_and_steven.h"

using namespace std;

long long mod = 1000000007;

int main() {
  int nodes = NumberOfNodes();
  int N = GetToddLength();
  int M = GetStevenLength();
  int id = MyNodeId();

  if (id == 0) {
    long long ans = 0;
    long long i = 0, j = 0, cur = 0;

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
    cout << ans << endl;
  }

  return 0;
}
