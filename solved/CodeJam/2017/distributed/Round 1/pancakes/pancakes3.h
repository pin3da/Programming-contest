// Sample input 3, in CPP.

#include <cassert>

long long GetStackSize() {
  return 7LL;
}

long long GetNumDiners() {
  return 5LL;
}

long long GetStackItem(long long i) {
  switch ((int)i) {
    case 0: return 0LL;
    case 1: return 1LL;
    case 2: return 3LL;
    case 3: return 2LL;
    case 4: return 1LL;
    case 5: return 3LL;
    case 6: return 0LL;
    default: assert(0);
  }
}
