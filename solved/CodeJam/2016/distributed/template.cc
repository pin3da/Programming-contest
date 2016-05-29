#include <bits/stdc++.h>

#include "message.h"
#include "problem.h"

using namespace std;

void task() {
  cout << "MyId : " << MyNodeId() << endl;
}

int main(int argc, char **argv) {
#ifdef MANUEL
  mp_register(argv[1]);
  task();
  // mp_end();
#else
  task();
#endif
  return 0;
}
