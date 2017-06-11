// Sample input 2, in CPP.

#include <cassert>

long long GetNumFlagpoles() {
  return 4LL;
}

long long GetHeight(long long i) {
  switch ((int)i) {
    case 0: return 2LL;
    case 1: return 2LL;
    case 2: return 2LL;
    case 3: return 2LL;
    default: assert(0);
  }
}
