// Sample input 3, in CPP.

#include <cassert>

long long GetNumFlagpoles() {
  return 5LL;
}

long long GetHeight(long long i) {
  switch ((int)i) {
    case 0: return 1LL;
    case 1: return 3LL;
    case 2: return 2LL;
    case 3: return 4LL;
    case 4: return 3LL;
    default: assert(0);
  }
}
