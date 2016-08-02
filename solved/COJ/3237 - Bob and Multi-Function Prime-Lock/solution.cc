#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN  = 1000000 + 100;
const int inf = 1000;

int sieve[MN];
int dist[MN];
int color[MN];


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  sieve[0] = sieve[1] = 1;

  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      for (int j = i + i; j < MN; j += i)
        sieve[j] = 1;
    }
  }

  int tc; cin >> tc;
  int curcol = 1;
  while (tc--) {
    string t;
    cin >> t >> t;


    deque<string> q;
    q.push_back(t);
    dist[stoi(t)] = 0;
    bool ok = false;
    while (!q.empty() && !ok) {
      string cur = q.front(); q.pop_front();
      int num = stoi(cur);

      if (!sieve[num]) {
        cout << dist[num] << endl;
        break;
      }

      if (color[num] >= curcol) continue;
      color[num] = curcol;

      for (int i = 0; i < cur.size(); ++i) {
        string next = cur;
        if (cur[i] > '0') {
          next[i]--;
        } else {
          next[i] = '9';
        }
        int nn = stoi(next);
        if (color[nn] < curcol) {
          dist[nn] = dist[num] + 1;
          if (!sieve[nn]) {
            cout << dist[nn] << endl;
            ok = true;
            break;
          }
          q.push_back(next);
        }

        next = cur;
        if (cur[i] < '9') {
          next[i]++;
        } else {
          next[i] = '0';
        }

        nn = stoi(next);
        if (color[nn] < curcol) {
          dist[nn] = dist[num] + 1;
          if (!sieve[nn]) {
            cout << dist[nn] << endl;
            ok = true;
            break;
          }
          q.push_back(next);
        }
      }
    }
    curcol++;

  }

  return 0;
}


