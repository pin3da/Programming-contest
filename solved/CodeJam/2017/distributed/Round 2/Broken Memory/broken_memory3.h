// Sample input 3, in CPP.
#include <cassert>
#include "message.h"

long long GetLength() {
  return 16LL;
}

long long GetValue(long long i) {
  if (i < 0LL || i >= GetLength())
    assert(0);
  if ((12LL ^ MyNodeId()) == i)
    return ((i * i) ^ 21LL ^ (i + MyNodeId() + 1)) + 1LL;
  return ((i * i) ^ 21LL) + 1LL;
}
