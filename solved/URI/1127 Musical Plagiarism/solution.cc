#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

// Reports all occurrences of 'needle' in 'haystack'.
bool kmp(const vector<int> &needle, const vector<int> &haystack) {
  // Precompute border function
  int m = needle.size();
  vector<int> border(m);
  border[0] = 0;
  for (int i = 1; i < m; ++i) {
    border[i] = border[i - 1];
    while (border[i] > 0 and needle[i] != needle[border[i]]) {
       border[i] = border[border[i] - 1];
    }
    if (needle[i] == needle[border[i]]) border[i]++;
  }

  // Now the actual matching
  int n = haystack.size();
  int seen = 0;
  for (int i = 0; i < n; ++i){
    while (seen > 0 and haystack[i] != needle[seen]) {
      seen = border[seen - 1];
    }
    if (haystack[i] == needle[seen]) seen++;

    if (seen == m) {
      return true;
      seen = border[m - 1];
    }
  }
  return false;
}



int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  map<string, int> notes;
  notes["A"] = 0;
  notes["A#"] = 1;
  notes["Bb"] = 1;
  notes["B"] = 2;
  notes["Cb"] = 2;
  notes["B#"] = 3;
  notes["C"] = 3;
  notes["Db"] = 4;
  notes["C#"] = 4;
  notes["D"] = 5;
  notes["Eb"] = 6;
  notes["D#"] = 6;
  notes["E"] = 7;
  notes["Fb"] = 7;
  notes["F"] = 8;
  notes["E#"] = 8;
  notes["F#"] = 9;
  notes["Gb"] = 9;
  notes["G"] = 10;
  notes["Ab"] = 11;
  notes["G#"] = 11;

  int n, m;
  string t;
  while (cin >> n >> m && (n + m)) {
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
      cin >> t;
      a[i] = notes[t];
    }
    for (int i = 0; i < m; ++i) {
      cin >> t;
      b[i] = notes[t];
    }

    bool plagi = false;
    for (int i = 0; i < 12 && !plagi; ++i) {
      vector<int> c(m);
      for (int j = 0; j < m; ++j)
        c[j] = (b[j] + i) % 12;
      if (kmp(c, a)) {
        cout << "S" << endl;
        plagi = true;
      }
    }
    if (!plagi)
      cout << "N" << endl;

  }
  return 0;
}
