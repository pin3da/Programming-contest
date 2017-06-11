// Sample input 1, in CPP.

#include <cassert>

long long GetNumFlagpoles() {
  return 7LL;
}

long long GetHeight(long long i) {
  switch ((int)i) {
    case 0: return 5LL;
    case 1: return 7LL;
    case 2: return 5LL;
    case 3: return 3LL;
    case 4: return 1LL;
    case 5: return 2LL;
    case 6: return 3LL;
    default: assert(0);
  }
}
