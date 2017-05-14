// Sample input 3, in CPP.

#include <cassert>

long long GetToddLength() {
  return 2LL;
}

long long GetStevenLength() {
  return 4LL;
}

long long GetToddValue(long long i) {
  switch ((int)i) {
    case 0: return 15LL;
    case 1: return 23LL;
    default: assert(0);
  }
}

long long GetStevenValue(long long i) {
  switch ((int)i) {
    case 0: return 4LL;
    case 1: return 8LL;
    case 2: return 16LL;
    case 3: return 42LL;
    default: assert(0);
  }
}
