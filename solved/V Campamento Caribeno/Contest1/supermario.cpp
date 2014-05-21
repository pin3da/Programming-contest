using namespace std;
#include<bits/stdc++.h>

struct Point{
  double x, y, z;
  Point(){}
  Point(double xx, double yy, double zz){
    x = xx;
    y = yy;
    z = zz;
  }
  double distance(const Point &o) {
    double tmp = (x - o.x) * (x - o.x) + (y - o.y)*(y - o.y) + (z - o.z)*(z - o.z);
    return sqrt(tmp);
  }
};

int N;
Point start;
vector<vector<Point> > arr;
vector<Point> switches;
double memodpb[15][(1 << 13) + 2][15];
double memodp[(1 << 13) + 2][15];


double eps = 1e-9;

double dpb(int b, int mask, int idx){
  int monedas = arr[b].size();
  if (mask == ((1<<monedas) - 1))
    return arr[b][idx].distance(switches[b]);
  if (memodpb[b][mask][idx] > -eps)
    return memodpb[b][mask][idx];
  double ret = 1e100;
  for(int i = 0; i < monedas; i++){
    int aux = mask >> i;
    aux = aux & 1;
    if (aux == 0)
      ret = min(ret, dpb(b, mask | (1<<i), i) + arr[b][idx].distance(arr[b][i]));
  }
  memodpb[b][mask][idx] = ret;
  return ret;
}


double dp(int mask, int b){
  if (mask == ((1<<N) - 1))
    return start.distance(switches[b]);
  if (memodp[mask][b] > -eps)
    return memodp[mask][b];
  double ret = 1e100;
  for(int i = 0; i < N; i++){
    for(int m = 0; m < arr[i].size(); m++){
      int aux = mask >> i;
      aux = aux & 1;
      if (aux == 0)
        ret = min(ret, dp(mask | (1<<i), i) + dpb(i, 1 << m, m) + arr[i][m].distance(switches[b]));
    }
  }
  return ret = memodp[mask][b] = ret;
}


void clean(){
  for(int i = 0; i < N; i++)
    for(int j = 0; j < (1<<arr[i].size()); j++)
      for(int k = 0; k < arr[i].size(); k++)
        memodpb[i][j][k] = -1.0;
  for(int i = 0; i < (1<<N); i++)
    for(int j = 0; j < N; j++)
      memodp[i][j] = -1.0;
}

int main() {
  while(true){

    int input[4];
    for (int i = 0; i < 4; ++i) scanf("%d", &input[i]);
    if (input[0] == 0 && input[1] == 0 && input[2] == 0 && input[3] == 0)
      break;
    N = input[0];
    start = Point(input[1], input [2], input[3]);
    arr.resize(N);
    switches.resize(N);
    for(int i = 0; i < N; i++){
      int K; scanf("%d",&K);
      arr[i].resize(K);
      int a,b,c;
      scanf("%d%d%d", &a, &b, &c);
      switches[i] =  Point(a,b,c);
      for(int j = 0; j < K; j++) {
        scanf("%d%d%d", &a, &b, &c);
        arr[i][j] =  Point(a,b,c);
      }
    }
    clean();

    double ans = 1e100;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < arr[i].size(); j++)
        ans = min(ans, dp(1<<i, i) + dpb(i, 1 << j, j));

    printf("%.2lf\n", ans);
  }
  return 0;
}
