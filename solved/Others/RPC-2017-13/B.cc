#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef double T;

const int MN = 100000 + 100;
T used[MN], excess[MN], cap[MN];
int N;

void simulate(T t, T F) {
  int n = N;
  for (int i = 0; i < n; i++) {
    used[i] = 0;
    excess[i] = 0;
  }

  T curr = F * t;
  for (int i = 0; i < n; i++) {
    if (cap[i] < curr) {
      used[i] = cap[i];
      excess[i] = curr - cap[i];
    } else {
      used[i] = curr;
    }
  }
  T acc = 0;
  for (int i = 0; i < n; i++) {
    if (used[i] < cap[i]) {
      T rem = cap[i] - used[i];
      if (acc > rem) {
        acc -= rem;
        used[i] = cap[i];
      } else {
        used[i] += acc;
        acc = 0;
      }
    } else {
      acc += excess[i];
    }
  }
}

bool test_last(T t, T F) {
  simulate(t, F);
  int last = N - 1;
  return used[last] >= cap[last];
}

bool test_all(T t, T F) {
  simulate(t, F);
  for (int i = 0; i < N; i++) {
    if (used[i] < cap[i]) return false;
  }
  return true;
}

int main() {

  int n;
  T f;
  while (scanf("%d %lf", &n, &f) == 2) {
    N = n;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      cap[i] = t;
    }

    T ans;
    T lo = 0, hi = *max_element(cap, cap + N);

    for (int i = 0; i < 50; i++) {
      T mid = (lo + hi) * 0.5;
      if (test_all(mid, f)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    ans = lo;
    lo = 0, hi = ans;

    for (int i = 0; i < 50; i++) {
      T mid = (lo + hi) * 0.5;
      if (test_last(mid, f)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    printf("%.6lf %.6lf\n", lo, ans);
  }
  return 0;
}
