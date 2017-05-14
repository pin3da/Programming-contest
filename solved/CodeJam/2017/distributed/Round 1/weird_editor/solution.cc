#include <bits/stdc++.h>

#include "message.h"
#include "weird_editor.h"

using namespace std;

void send_array(vector<int> &a, int to) {
  for (int i = 0; i < (int)a.size(); ++i)
    PutInt(to, a[i]);
  Send(to);
}

void read_array(vector<int> &a, int from) {
  Receive(from);
  for (int i = 0; i < (int)a.size(); ++i)
    a[i] = GetInt(from);
}

const long long mod = 1000000007;


long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

long long my_fun(long long d, long long times) {
  if (times == 0) return 1;
  if (times == 1) {
    return d;
  }
  else {
    long long base = my_fun(d, times / 2);
    long long ans = (base * mod_pow(10, times / 2)) % mod;
    ans = (ans + base) % mod;
    if (times & 1) {
      return (ans * 10 + d) % mod;
    }
    return ans;
  }
}

int main() {
  int nodes = NumberOfNodes();
  int N = GetNumberLength();
  int bucket_size = (N + nodes - 1) / nodes;

  int id = MyNodeId();
  vector<int> frec(10);
  if (id * bucket_size < N) {
    int start = min(id * bucket_size, N - 1);
    int end = min(start + bucket_size, N);
    for (int j = start; j < end; ++j) {
      int d = GetDigit(j);
      for (int k = d - 1; k >= 0; --k) {
        frec[k] = 0;
      }
      frec[d]++;
    }
  }
  send_array(frec, 0);

  if (id == 0) {
    vector<int> acc(10);
    for (int i = 0; i < nodes; ++i) {
      vector<int> tmp(10);
      read_array(tmp, i);
      for (int j = 9; j > 0; --j) {
        if (tmp[j]) {
          for (int k = j - 1; k >= 0; --k) {
            acc[k] = 0;
          }
          acc[j] += tmp[j];
        }
      }
    }

    long long used = 0;
    long long ans = 0;
    for (int i = 9; i > 0; --i) {
      used += acc[i];
      if (acc[i]) {
        ans = (ans * mod_pow(10, acc[i])) % mod;
        ans = (ans + my_fun(i, acc[i])) % mod;
        /*
           while (acc[i]--) {
           ans = (ans * 10 + i) % mod;
           }
           */
      }
    }
    int missing = N - used;
    ans = (ans * mod_pow(10, missing)) % mod;
    cout << ans << endl;
  }
  return 0;
}
