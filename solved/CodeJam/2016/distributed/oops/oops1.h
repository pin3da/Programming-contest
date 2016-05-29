// Sample input 1, in CPP.

#include <cassert>

long long GetN() {
  return 9LL;
}

long long GetNumber(long long i) {
  switch ((int)i) {
    case 0: return 12LL;
    case 1: return 21LL;
    case 2: return 32LL;
    case 3: return 24LL;
    case 4: return 100LL;
    case 5: return 25LL;
    case 6: return 49LL;
    case 7: return 7LL;
    case 8: return 7LL;
    default: assert(0);
  }
}
