#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;

using namespace __gnu_pbds;

#define debug(x) cout << #x " = " << (x) << endl

struct team {
  int a, b, id; // problems, penalty, id
  team() {}
  team(int x, int y, int z) : a(x), b(y), id(z) {}
  bool operator < (const team &o) const {
    if (a == o.a) {
      if (b == o.b) return id < o.id;
      return b < o.b;
    }
    return a > o.a;
  }
};

void print_team(team &a) {
  cout << a.a << " " << a.b << " " << a.id << endl;
}

typedef tree<
team,
null_type,
less<team>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void solve() {
  int n;
  cin >> n;
  vector<team> teams(n);

  ordered_set all;
  for (int i = 0; i < n; i++) {
    teams[i] = team(0, 0, i);
    all.insert(teams[i]);
  }

  int events;
  cin >> events;

  while (events--) {
    int t, p;
    cin >> t >> p;
    t--;
    team cur = teams[t];
    all.erase(cur);
    cur.a++;
    cur.b += p;
    all.insert(cur);
    teams[t] = cur;
    team favorite = teams[0];
    favorite.b--;
    favorite.id = n + 10;
    // print_team(favorite);
    cout << all.order_of_key(favorite) + 1<< endl;
  }

}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}
