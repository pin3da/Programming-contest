// http://codeforces.com/contest/509/problem/C

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int ant[1001], tar;

bool visited[1001][1001][2];
int sol[1001][1001][2];
int cool[1001];

int dp(int i, int sum, int start) {
  if (sum > 300) {
    return -1;
  }
  if (i == 1001) {
    if (sum != tar) {
      return -1;
    }
    return 0;
  }
  if (visited[i][sum][start])
    return sol[i][sum][start];

  visited[i][sum][start] = true;


  int ini;
  if (start)
    ini = ant[i];
  else
    ini = 0;

  for (int j = ini; j < 10; ++j) {
    int ans = dp(i + 1, sum + j, (j == ini) and start);
    if (ans > -1) {
      cool[i] = j;
      return  sol[i][sum][start] = j;
    }
  }
  return sol[i][sum][start] = -1;
}

int main() { ___
  int n, t;
  cin >> n;
  memset(ant, 0, sizeof ant);
  while (n--) {
    cin >> tar;
    memset(visited, 0, sizeof visited);
    int cur = dp(0, 0, 1);
    int sum = 0;
    int non_zero = false;
    int start = 1;
    for (int i = 0; i < 1001; ++i) {
      int cur = cool[i];
      if (non_zero or cur > 0)
        cout << cur;
      ant[i] = cur;

      if (cur)
        non_zero = true;


/*
 *      int ini;
 *      if (start)
 *        ini = ant[i];
 *      else
 *        ini = 0;
 *
 *      start = (cur == ini) and start;
 *      cur = sol[i + 1][sum + cur][start];
 *      sum += cur;
 */
    }
    int i = 1000;
    while (i >= 0) {
      if (ant[i] < 9) {
        ant[i]++;
        break;
      }
      ant[i] = 0;
      i--;
    }
    cout << endl;
  }
  return 0;
}
