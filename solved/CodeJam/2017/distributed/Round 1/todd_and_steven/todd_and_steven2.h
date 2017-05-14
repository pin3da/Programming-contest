// Sample input 2, in CPP.

#include <cassert>

long long GetToddLength() {
  return 1LL;
}

long long GetStevenLength() {
  return 1LL;
}

long long GetToddValue(long long i) {
  switch ((int)i) {
    case 0: return 101LL;
    default: assert(0);
  }
}

long long GetStevenValue(long long i) {
  switch ((int)i) {
    case 0: return 100LL;
    default: assert(0);
  }
}
