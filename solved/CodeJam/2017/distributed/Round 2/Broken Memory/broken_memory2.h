// Sample input 2, in CPP.
#include <cassert>
#include "message.h"

long long GetLength() {
  return 30LL;
}

long long GetValue(long long i) {
  if (i < 0LL || i >= GetLength())
    assert(0);
  if ((29LL - MyNodeId()) == i)
    return (((i % 9LL) + 1LL) * ((i % 7LL) + 1LL) ^ (i + MyNodeId() + 1)) + 1LL;
  return (((i % 9LL) + 1LL) * ((i % 7LL) + 1LL)) + 1LL;
}
