// http://codeforces.com/contest/611/problem/A

using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

// Time - Leap years
//

const int A[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
// same as A, but for a leap year
const int B[13] = { 0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
// returns number of leap years up to, and including, y
int leap_years(int y) { return y / 4 - y / 100 + y / 400; }
bool is_leap(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }
// number of days in blocks of years
const int p400 = 400*365 + leap_years(400);
const int p100 = 100*365 + leap_years(100);
const int p4   = 4*365 + 1;
const int p1   = 365;
int date_to_days(int d, int m, int y)
{
  return (y - 1) * 365 + leap_years(y - 1) + (is_leap(y) ? B[m] : A[m]) + d;
}
void days_to_date(int days, int &d, int &m, int &y)
{
  bool top100;  // are we in the top 100 years of a 400 block?
  bool top4;	  // are we in the top 4 years of a 100 block?
  bool top1;	  // are we in the top year of a 4 block?

  y = 1;
  top100 = top4 = top1 = false;

  y += ((days-1) / p400) * 400;
  d = (days-1) % p400 + 1;

  if (d > p100*3) top100 = true, d -= 3*p100, y += 300;
  else y += ((d-1) / p100) * 100, d = (d-1) % p100 + 1;

  if (d > p4*24) top4 = true, d -= 24*p4, y += 24*4;
  else y += ((d-1) / p4) * 4, d = (d-1) % p4 + 1;

  if (d > p1*3) top1 = true, d -= p1*3, y += 3;
  else y += (d-1) / p1, d = (d-1) % p1 + 1;

  const int *ac = top1 && (!top4 || top100) ? B : A;
  for (m = 1; m < 12; ++m) if (d <=  ac[m + 1]) break;
  d -= ac[m];
}


int start = date_to_days(1, 1, 2016);
int end_day = date_to_days(31, 12, 2016);
int st_day = 5;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a;
  string of, q;
  while (cin >> a >> of >> q) {
    int ans = 0;
    if (q == "week") {
      int b = date_to_days(4, 1, 2016);
      if (a == 5 || a == 6) ans++;
      while (b <= end_day) {
        ans++;
        b += 7;
      }
      cout << ans << endl;
    } else {
      for (int i = 0; i < 13; ++i) {
        if (B[i] - B[i - 1] >= a) ans++;
      }
      cout << ans + 1 << endl;
    }
  }
  return 0;
}
