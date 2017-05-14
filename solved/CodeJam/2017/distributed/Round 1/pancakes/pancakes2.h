// Sample input 2, in CPP.

#include <cassert>

long long GetStackSize() {
  return 6LL;
}

long long GetNumDiners() {
  return 4LL;
}

long long GetStackItem(long long i) {
  switch ((int)i) {
    case 0: return 0LL;
    case 1: return 0LL;
    case 2: return 0LL;
    case 3: return 2LL;
    case 4: return 2LL;
    case 5: return 3LL;
    default: assert(0);
  }
}
