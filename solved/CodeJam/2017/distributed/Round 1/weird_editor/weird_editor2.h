// Sample input 2, in CPP.

#include <cassert>

long long GetNumberLength() {
  return 8LL;
}

long long GetDigit(long long i) {
  switch ((int)i) {
    case 0: return 1LL;
    case 1: return 0LL;
    case 2: return 2LL;
    case 3: return 3LL;
    case 4: return 2LL;
    case 5: return 1LL;
    case 6: return 3LL;
    case 7: return 0LL;
    default: assert(0);
  }
}
