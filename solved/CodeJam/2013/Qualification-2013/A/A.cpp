using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

char mat[4][4];

int win_p(char p){
  char m2[4][4];
  For(i,4)
    For(j,4)
      if(mat[i][j]=='T')
        m2[i][j] = p;
      else
        m2[i][j] = mat[i][j];
        
   int win = 0;
   int d1 = 1;
   int d2 = 1;
   For(i,4){
      int row = 1;
      int col = 1;
      For(j,4){
         row &= m2[i][j]==p;
         col &= m2[j][i]==p;
      }
      d1 &= m2[i][i]==p;
      d2 &= m2[3 - i][i]==p;
      win = win or row or col;
   }
   
   return win or d1 or d2;
    

}

int finish(){
  int t = 1;
  For(i,4)
    For(j,4)
      t &= mat[i][j]!='.';
  
  return t;
}

int main(){
    int tc;cin>>tc;
    
    For(id,tc){
      For(i,4)
        For(j,4)
          cin>>mat[i][j];
          
      int c1 = win_p('O');
      int c2 = win_p('X');
      cout<<"Case #"<<(id+1)<<": ";

      if(c1 and c2)
        cout<<"Draw"<<endl;
      else if(c1)
        cout<<"O won"<<endl;
      else if(c2)
        cout<<"X won"<<endl;
      else if(finish())
        cout<<"Draw"<<endl;
      else
        cout<<"Game has not completed"<<endl;
      
    }    
    return 0;
}   
