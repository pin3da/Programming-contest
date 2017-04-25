// http://codeforces.com/contest/382/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 505


int main(){ ___

  string line;
  cin>>line;
  int pos;
  For(i, line.size()) if(line[i] == '|') pos = i;
  string line2;
  cin>>line2;
  int left = pos;
  int right = line.size() - pos -1;

  For(i,line2.size()){
    if(right > left) {
      line = (line2[i]) + line;
      left++;
    }else{
      line += line2[i];
      right++;
    }
  }
  if(right == left){
    cout<<line<<endl;
  }else{
    cout<<"Impossible"<<endl;
  }
  return 0;
}