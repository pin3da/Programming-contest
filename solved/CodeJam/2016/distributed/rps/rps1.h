// Sample input 1, in CPP.

#include <cassert>

long long GetN() {
  return 3LL;
}

char GetFavoriteMove(long long id) {
  switch ((int)id) {
    case 0: return 'R';
    case 1: return 'P';
    case 2: return 'S';
    case 3: return 'R';
    case 4: return 'P';
    case 5: return 'S';
    case 6: return 'R';
    case 7: return 'P';
    default: assert(0);
  }
}
