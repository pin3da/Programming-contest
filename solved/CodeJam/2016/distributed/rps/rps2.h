// Sample input 2, in CPP.

#include <cassert>

long long GetN() {
  return 2LL;
}

char GetFavoriteMove(long long id) {
  switch ((int)id) {
    case 0: return 'R';
    case 1: return 'R';
    case 2: return 'R';
    case 3: return 'R';
    default: assert(0);
  }
}
