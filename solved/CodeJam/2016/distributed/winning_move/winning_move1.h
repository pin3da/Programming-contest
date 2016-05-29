// Sample input 1, in CPP.

#include <cassert>

long long GetNumPlayers() {
  return 6LL;
}

long long GetSubmission(long long playernum) {
  switch ((int)playernum) {
    case 0: return 4LL;
    case 1: return 8LL;
    case 2: return 15LL;
    case 3: return 16LL;
    case 4: return 23LL;
    case 5: return 42LL;
    default: assert(0);
  }
}
