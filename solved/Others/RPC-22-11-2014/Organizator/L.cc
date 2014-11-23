using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl


const int MN = 1810101;
const int VERGA = 2000002;
long long ans[VERGA];

typedef long long lli;
typedef vector<int> IV;

#define Sc(t, v) static_cast<t>(v)
#define cFor(t, v, c) for(t::const_iterator v=c.begin(); v != c.end(); v++)

#define ISCOMP(n)  (_c[(n)>>5]&(1<<((n)&31)))
#define SETCOMP(n) _c[(n)>>5]|=(1<<((n)&31))

namespace Num{
  const int MAX = 1515;
  const int LMT = 50; // sqrt(MAX)
  int _c[(MAX>>5)+1];

  IV primes;

  void primeSieve() {
    SETCOMP(0); SETCOMP(1);
    for (int i = 3; i <= LMT; i += 2)
      if (!ISCOMP(i))
        for (int j = i * i; j <= MAX; j += i + i) SETCOMP(j);

    primes.push_back(2);
    cerr << "int primes[] = {2";
    for (int i = 3; i <= MAX; i+=2)
      if (!ISCOMP(i)) {
        primes.push_back(i);
        cerr << "," << i;
      }
    cerr << "};";
  }
}

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511};

void divisors(vector<int> &pri, vector<int> &exp, int i, int acum, vector<int> &ans) {
  if (i == pri.size()) {
    ans.push_back(acum);
    return;
  }

  for (int j = 0; j <= exp[i]; ++j) {
    divisors(pri, exp, i + 1, acum, ans);
    acum *= pri[i];
  }
}

vector<int> gen_div(int x) {

  vector<int> pri, exp;

  // using Num::primes;

  for (int i = 0; i < 240 and primes[i] * primes[i] <= x; ++i) {
    if (x % primes[i]) continue;
    int e = 0; for(; (x % primes[i]) == 0; e++, x /= primes[i]);
    pri.push_back(primes[i]);
    exp.push_back(e);
  }
  if (x > 1) {
    pri.push_back(x);
    exp.push_back(1);
  }

  vector<int> ans;
  divisors(pri, exp, 0, 1, ans);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Num::primeSieve();


  int n;
  cin >> n;
  vector<int> input(2000002, 0);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    input[t]++;
  }

  for (int i = 0; i < input.size(); ++i) {
    if (input[i]) {
      vector<int> dv = gen_div(i);

      for (int j = 0; j < dv.size(); ++j) {
        ans[dv[j]] += input[i];
      }
    }
  }

  long long best = 0;


  for (long long i = 0; i < VERGA; ++i) {
    if (ans[i] >= 2)
      best = max(i * ans[i], best);
  }
  cout << best << endl;

  return 0;
}
