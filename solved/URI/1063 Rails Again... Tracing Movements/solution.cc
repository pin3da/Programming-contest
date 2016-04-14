#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<char> a(n), b(n);
    vector<int> id(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        if (b[j] == a[i])
          id[i] = j;
    }

    int cur = 0;
    deque<int> st;
    for (int i = 0; i < n; ++i) {
      if (id[i] >= cur) {
        st.push_back(id[i]);
        cout << "I";
      }

      while (st.size() && st.back() == cur) {
        cout << "R";
        st.pop_back();
        cur++;
      }
    }

    if (st.size()) {
      cout << " Impossible";
    }
    cout << endl;

  }
  return 0;
}

