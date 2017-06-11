#include <bits/stdc++.h>

#include "message.h"
#include "flagpoles.h"
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const long long inf = 1000000LL * 1000000LL;

struct state {
  pair<long long, long long> left, mid, right;
  int len;
  state () {
    left = {0, inf};
    mid = {0, inf};
    right = {0, inf};
    len = 0;
  }
};

void send_state(int node, state &s) {
  PutLL(node, s.left.first);
  PutLL(node, s.left.second);
  PutLL(node, s.mid.first);
  PutLL(node, s.mid.second);
  PutLL(node, s.right.first);
  PutLL(node, s.right.second);
  PutLL(node, s.len);
}

void read_state(int from, state &s) {
  s.left.first  = GetLL(from);
  s.left.second = GetLL(from);
  s.mid.first  = GetLL(from);
  s.mid.second = GetLL(from);
  s.right.first  = GetLL(from);
  s.right.second = GetLL(from);
  s.len = GetLL(from);
}

state merge_state(state &a, state &b, int id, int bucket_size, int N) {
  // Merge id - 1, id

  id--;
  int startA = min(id * bucket_size, N - 1);
  int endA = min(startA + bucket_size, N);
  id++;
  int startB = min(id * bucket_size, N - 1);
  int endB = min(startB + bucket_size, N);

  int diff_mid = GetHeight(startB) - GetHeight(endA - 1);

  if (b.len == 0) { // last merge
    state ans = a;
    ans.len++;
    if (diff_mid == ans.right.second)
      ans.right.first++;
    ans.mid = max(ans.mid, ans.right);
    return ans;
  }

  state ans;
  ans.left = a.left;
  ans.right = b.right;
  ans.mid = max(a.mid, b.mid);
  ans.len = a.len + b.len;

  if (a.right.second == b.left.second) {
    if (diff_mid == b.left.second)
      ans.mid = max(ans.mid, make_pair(a.right.first + b.left.first + 1, a.right.second));
  }

  if (diff_mid == a.right.second)
    a.right.first++;
  if (diff_mid == b.left.second)
    b.left.first++;
  ans.mid = max(ans.mid, a.right);
  ans.mid = max(ans.mid, b.left);

  if (ans.left.first + 1 == a.len && ans.left.second == diff_mid) {
    ans.left.first++;
    if (b.left.second == diff_mid) {
      ans.left.first += (b.left.first - 1);
    }
  }

  if (ans.right.first + 1 == b.len && ans.right.second == diff_mid) {
    ans.right.first++;
    if (a.right.second == diff_mid) {
      ans.right.first += (a.right.first - 1);
    }
  }
  return ans;
}

void debug_state(state &a) {
  cout << "L : " << a.left.first << " " << a.left.second << endl;
  cout << "M : " << a.mid.first << " " << a.mid.second << endl;
  cout << "R : " << a.right.first << " " << a.right.second << endl;
  cout << "len : " << a.len << endl;
}

int main() {
  int id = MyNodeId();
  int nodes = NumberOfNodes();
  int N = GetNumFlagpoles();
  if (nodes >= N) {
    nodes = 1;
  }
  int bucket_size = (N + nodes - 1) / nodes;
  if (id < nodes) {
    state ans;
    if (id * bucket_size < N) {
      int start = min(id * bucket_size, N - 1);
      int end = min(start + bucket_size, N);
      vector<int> delta(end - start - 1);
      if (delta.size()) {
        for (int i = start; i + 1 < end; ++i) {
          delta[i - start] = GetHeight(i + 1) - GetHeight(i);
        }
        int cur = delta[0];
        ans.left.second = cur;
        for (int i = 0; i < delta.size() && delta[i] == cur; ++i) {
          ans.left.first++;
        }
        int frec = 1, val = delta[0];
        int best = 1, val_best = delta[0];
        for (int i = 1; i < delta.size(); ++i) {
          if (delta[i] == val) {
            frec++;
          } else {
            frec = 1;
            val = delta[i];
          }
          if (frec > best) {
            best = frec;
            val_best = val;
          }
        }
        ans.mid.first = best;
        ans.mid.second = val_best;

        cur = delta.back();
        ans.right.second = cur;
        for (int i = delta.size() - 1; i >= 0 && delta[i] == cur; --i) {
          ans.right.first++;
        }
        ans.len = end - start;
      }
    }
    send_state(0, ans);
    Send(0);
  }

  if (id == 0) {
    state best;
    Receive(0);
    read_state(0, best);
    for (int i = 1; i < nodes; ++i) {
      Receive(i);
      state cur;
      read_state(i, cur);
      if (cur.left.second == inf) continue;
      best = merge_state(best, cur, i, bucket_size, N);
    }
    cout << best.mid.first + 1 << endl;
  }
  return 0;
}

