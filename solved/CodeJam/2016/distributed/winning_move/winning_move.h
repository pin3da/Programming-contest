// Sample input 2, in CPP.

#include <cassert>

long long GetNumPlayers() {
  return 8LL;
}

long long GetSubmission(long long playernum) {
  switch ((int)playernum) {
    case 0: return 4LL;
    case 1: return 2LL;
    case 2: return 1LL;
    case 3: return 3LL;
    case 4: return 4LL;
    case 5: return 1LL;
    case 6: return 2LL;
    case 7: return 2LL;
    default: assert(0);
  }
}
