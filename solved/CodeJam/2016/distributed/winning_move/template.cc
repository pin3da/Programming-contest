#include <bits/stdc++.h>

#include "message.h"
#include "winning_move.h"

using namespace std;

void task() {
  if (MyNodeId() == 0) {
    int n = GetNumPlayers();
    map<long long, long long> frec;
    for (int i = 0; i < n; ++i) {
      frec[GetSubmission(i)]++;
    }
    long long ans = 0;
    for (auto &i: frec) {
      if (i.second == 1) {
        ans = i.first;
        break;
      }
    }
    cout << ans << endl;
  }
}

int main(int argc, char **argv) {
#ifdef MANUEL
  mp_register(argv[1]);
  task();
  // mp_end();
#else
  task();
#endif
  return 0;
}
