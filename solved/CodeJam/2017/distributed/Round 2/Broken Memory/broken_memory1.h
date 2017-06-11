// Sample input 1, in CPP.
#include <cassert>
#include "message.h"

long long GetLength() {
  return 10LL;
}

long long GetValue(long long i) {
  if (i < 0LL || i >= GetLength())
    assert(0);
  if ((MyNodeId()) == i)
    return (i ^ (i + MyNodeId() + 1)) + 1LL;
  return (i) + 1LL;
}
