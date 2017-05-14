// Sample input 1, in CPP.

#include <cassert>

long long GetToddLength() {
  return 1LL;
}

long long GetStevenLength() {
  return 2LL;
}

long long GetToddValue(long long i) {
  switch ((int)i) {
    case 0: return 3LL;
    default: assert(0);
  }
}

long long GetStevenValue(long long i) {
  switch ((int)i) {
    case 0: return 2LL;
    case 1: return 6LL;
    default: assert(0);
  }
}
