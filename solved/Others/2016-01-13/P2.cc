#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;



int haab_to_days(int year, int month, int day) {
  int total = year * 365  + 20 * month + day;
  return total;
}

void days_to_tzolkin(int days, int &year, int &month, int &day) {
  year = days / (20 *  13);
  day = days % (20 * 13);
}

map<string, int> haab;

string tzolkin[] = {
"imix", "ik", "akbal", "kan", "chicchan",
"cimi", "manik", "lamat", "muluk", "ok",
"chuen", "eb", "ben", "ix", "mem",
"cib", "caban", "eznab", "canac", "ahau"
};

void solve() {
  int day, year;
  string month, t;
  cin >> t >> month >> year;
  day = atoi(t.substr(0, t.size() - 1).c_str());
  int days = haab_to_days(year, haab[month], day);
  int m;
  days_to_tzolkin(days, year, m, day);
  cout << (day % 13) + 1 << " " << tzolkin[(day % 20)] << " " << year << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string f[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin",
                "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax",
                "koyab", "cumhu", "uayet"};
  for (int i = 0; i < 19; ++i) {
    haab[f[i]] = i;
  }
  int n; cin >> n;
  cout << n << endl; // I hate you UVa!!
  while (n--) solve();
  return 0;
}
