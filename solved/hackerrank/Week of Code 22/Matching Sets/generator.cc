#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000000LL;

int main(int argc, char **argv) {
  int type = atoi(argv[2]);
  srand(time(0));
  if (type == 0) {
    int N = atoi(argv[1]);
    cout << N << endl;
    vector<long long> a(N);
    vector<long long> b(N);


    for (int i = 0; i < N; ++i) {
      a[i] = (random() % (2 * mod)) - mod;
      b[i] = (random() % (2 * mod)) - mod;
    }

    for (int i = 0; i < N; ++i)
      cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < N; ++i)
      cout << b[i] << " ";
    cout << endl;
  } else {
    int N = atoi(argv[1]);
    cout << N << endl;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i)
      cout << a[i] << ' ';
    cout << endl;
    int iter = 10000000;
    while (iter--) {
      int i = random() % N;
      int j = random() % N;
      a[i]++;
      a[j]--;
    }
    for (int i = 0; i < N; ++i)
      cout << a[i] << ' ';
    cout << endl;
  }
  return 0;
}
