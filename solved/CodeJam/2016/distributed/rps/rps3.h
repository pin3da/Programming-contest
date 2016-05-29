// Sample input 3, in CPP.

#include <cassert>

long long GetN() {
  return 2LL;
}

char GetFavoriteMove(long long id) {
  switch ((int)id) {
    case 0: return 'S';
    case 1: return 'R';
    case 2: return 'P';
    case 3: return 'P';
    default: assert(0);
  }
}
