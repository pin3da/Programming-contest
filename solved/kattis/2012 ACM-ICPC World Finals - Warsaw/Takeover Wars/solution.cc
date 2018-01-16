#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

bool takeover(deque<long long> &A, deque<long long> &B) {
  if (A[0] > B[0]) {
    B.pop_front();
    return true;
  }
  return false;
}

void merge(deque<long long> &A) {
  if (A.size() > 1) {
    long long a = A[0], b = A[1];
    A.pop_front();
    A.pop_front();
    A.push_front(a + b);
  }
}

bool a_wins(deque<long long> &A, deque<long long> &B) {
  while (A.size() && B.size()) {
    if (!takeover(A, B)) merge(A);
    if (!takeover(B, A)) merge(B);
  }
  return A.size() > 0;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n, m;
  int tc_id = 0;
  while (cin >> n >> m) {
    deque<long long> A(n), B(m);
    for (auto &i : A) cin >> i;
    for (auto &i : B) cin >> i;

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    auto A1 = A, A2 = A, B1 = B, B2 = B;

    int win = a_wins(A1, B1);

    merge(A2);
    if (!takeover(B2, A2)) {
      merge(B2);
      win |= a_wins(A2, B2);
    }

    printf("Case %d: ", ++tc_id);
    puts(win ? "Takeover Incorporated" : "Buyout Limited");
  }

  return 0;
}
