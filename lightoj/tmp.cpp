    //
    //AUTHOR: KISLAY
    //DATE: Fri Feb 11 03:05:02 IST 2011
#include <vector>
#include <cassert>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <fstream>
#include <sstream>
#include<ctype.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209749Lf
#define INF 2000000000
#define INFI 1e37
#define eps 1e-6
#define pb push_back
#define PRINT(x) cout << #x << " " << x << endl
#define BUF 4096

char ibuf[BUF];
int ipt = BUF;

int readInt ()
{
  while (ipt < BUF && ibuf[ipt] < '0')
    ipt++;
  if (ipt == BUF)
    {
      fread (ibuf, 1, BUF, stdin);
      ipt = 0;
      while (ipt < BUF && ibuf[ipt] < '0')
	ipt++;
    }
  int n = 0;
  while (ipt < BUF && ibuf[ipt] >= '0')
    n = (n * 10) + (ibuf[ipt++] - '0');
  if (ipt == BUF)
    {
      fread (ibuf, 1, BUF, stdin);
      ipt = 0;
      while (ipt < BUF && ibuf[ipt] >= '0')
	n = (n * 10) + (ibuf[ipt++] - '0');
    }
  return n;
}

using namespace std;
typedef struct point{
  int x;
  int y;
} point;
point p[750];
double slope[750];

inline double computeslope (int x1, int y1, int x2, int y2)
{
  return (double) (y2 - y1) / (double) (x2 - x1);
}

int main ()
{
  int t, n, i, j;
  int index;
  t = readInt ();
  double s;
  int result, countt;
  while (t--)
    {
      n = readInt ();
      for (i = 0; i < n; i++)
	{
	  p[i].x = readInt ();
	  p[i].y = readInt ();
	}
      index = 0;
      result = 2;
      for (i = 0; i < n; i++)
	{
	  index = 0;
	  for (j = i + 1; j < n; j++)
	    {
	      s = computeslope (p[i].x, p[i].y, p[j].x, p[j].y);
	      slope[index++] = s;
	    }
	  sort (slope, slope + index);
	  countt = 2;
	  for (int j = 0; j < index; j++)
	    {
	      if (abs (slope[j] - slope[j + 1]) < eps)
		{
		  countt++;
		}
	      else
		countt = 2;
	      result = max (result, countt);
	    }
	}
      if (n == 1)
	printf ("%d\n", 1);
      else
	printf ("%d\n", result);
    }

  return 0;
}
