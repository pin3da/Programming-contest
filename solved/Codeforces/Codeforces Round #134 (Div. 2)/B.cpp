// http://codeforces.com/contest/218/problem/B

using namespace std;
#include<iostream>
#include<queue>

int main() {
  int a,b;
  cin>>a>>b;
  priority_queue<int> q;
  priority_queue<int, vector<int>, greater<int> > p;
  int t;
  for (int i = 0; i < b; ++i) {
    cin>>t;
    q.push(t);
    p.push(t);
  }


  int mmax = 0, mmin = 0;
  for (int i = 0; i < a; ++i) {
    int act = q.top();q.pop();
    mmax += act;
    if (act - 1 > 0)
      q.push(act-1);
    act = p.top(); p.pop();
    mmin += act;
    if (act - 1 > 0)
      p.push(act-1);
  }

  cout<<mmax<<" "<<mmin<<endl;

  return 0;
}