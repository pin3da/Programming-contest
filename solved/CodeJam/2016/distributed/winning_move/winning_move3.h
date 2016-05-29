// Sample input 3, in CPP.

#include <cassert>

long long GetNumPlayers() {
  return 3LL;
}

long long GetSubmission(long long playernum) {
  switch ((int)playernum) {
    case 0: return 1LL;
    case 1: return 1LL;
    case 2: return 1LL;
    default: assert(0);
  }
}
