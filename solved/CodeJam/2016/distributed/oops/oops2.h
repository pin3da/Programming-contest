// Sample input 2, in CPP.

#include <cassert>

long long GetN() {
  return 1LL;
}

long long GetNumber(long long i) {
  switch ((int)i) {
    case 0: return 1LL;
    default: assert(0);
  }
}
