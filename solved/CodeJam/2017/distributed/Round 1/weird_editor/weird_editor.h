// Sample input 1, in CPP.

#include <cassert>

long long GetNumberLength() {
  return 4LL;
}

long long GetDigit(long long i) {
  switch ((int)i) {
    case 0: return 3LL;
    case 1: return 0LL;
    case 2: return 0LL;
    case 3: return 1LL;
    default: assert(0);
  }
}
