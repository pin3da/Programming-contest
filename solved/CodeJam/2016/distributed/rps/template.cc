#include <bits/stdc++.h>

#include "message.h"
#include "rps.h"

using namespace std;

bool match(char a, char b, int x, int y) {
  if (a == b) return x < y;
  if (a == 'R' && b == 'P') return false;
  if (a == 'R' && b == 'S') return true;
  if (a == 'P' && b == 'S') return false;
  if (a == 'P' && b == 'R') return true;
  if (a == 'S' && b == 'R') return false;
  if (a == 'S' && b == 'P') return true;
}

pair<char, int> simulate(deque<char> &d, deque<int> &id) {
  while (d.size() > 1) {
    deque<char> nd;
    deque<int> nid;
    for (int i = 0; i < d.size(); i += 2) {
      if (match(d[i], d[i + 1], id[i], id[i + 1])) {
        nd.push_back(d[i]);
        nid.push_back(id[i]);
      } else {
        nd.push_back(d[i + 1]);
        nid.push_back(id[i + 1]);
      }
    }
    d = nd;
    id = nid;
  }
  return make_pair(d[0], id[0]);
}

void task() {
  int n = GetN();
  int myid = MyNodeId();
  int nodes = NumberOfNodes();
  if (n < nodes)
    nodes = 1;
  else {
    int i = 0;
    int pos = 1;
    while ((1 << i) <= nodes) {
      pos = (1 << i);
      i++;
    }
    nodes = min(pos, NumberOfNodes());
  }
  int total = 1 << n;
  int bucket_size = (total + nodes - 1) / nodes;
  int start = myid * bucket_size;
  int end = start + bucket_size;

  deque<char> d;
  deque<int> id;
  for (int i = 0; i < bucket_size && start + i < total; ++i) {
    d.push_back(GetFavoriteMove(start + i));
    id.push_back(start + i);
  }
  if (d.size()) {
    pair<char, int> local_best = simulate(d, id);
    PutChar(0, local_best.first);
    PutInt(0, local_best.second);
    Send(0);
  } else {
    PutChar(0, 'X');
    PutInt(0, -1);
    Send(0);
  }

  if (myid == 0) {
    d.clear();
    id.clear();
    for (int i = 0; i < nodes; ++i) {
      Receive(i);
      char a = GetChar(i);
      int b = GetInt(i);
      if (a == 'X') continue;
      d.push_back(a);
      id.push_back(b);
    }
    cout << simulate(d, id).second << endl;
  }
}

int main(int argc, char **argv) {
#ifdef MANUEL
  mp_register(argv[1]);
  task();
#else
  task();
#endif
  return 0;
}
