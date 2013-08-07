using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " <<(x)<<endl

struct player{
     string name;
     int round;
     player(){}
     player(string n,int r): name(n), round(r){}
     
     bool operator < (const player &o) const {
          if(round == o.round) return name < o.name;
          return round > o.round;
     }
};

int alive(int R, int p){
     if(p - 2*R < 0)
          return p/2;
     return ((p- 2*R)/3)  + R;
}

int main(){ ___
     int tc;cin>>tc;
     while(tc--){
          int m;cin>>m;
          string name;
          vector<string> cod(1<<m);
          vector<int> points(1<<m);
          int t = 1<<m;
          for(int i = 0; i< t; ++i){
               cin>>name>>points[i];
               cod[i] = name;
          }
          
          vector<int> ans(t);
          
          for(int R = 0; R <= m; ++R){
               int mio = 1;
               vector<int> posible(m+1,0);
               for(int p = 0; p < t; ++p){
                    int mm = alive(R,points[p]);
                    if(mm < 0 or mm > m){ mio = 0; break;}
                    posible[alive(R,points[p])]++;
                    ans[p] = alive(R,points[p]);
               }
               if(!mio) continue;
               
               reverse(posible.begin(), posible.end());
               int ok = (posible[0] == 1 and posible[1]== 1);
               for(int i = 2; i< m+1; ++i)
                    ok &= ((posible[i-1]*2) == posible[i]);
               
               if(ok)break;
          }
          
          vector<player> todos(t);
          for(int i = 0; i< t; ++i)
               todos[i] = player(cod[i],ans[i]);
          
          
          sort(todos.begin(),todos.end());
          
          for(int i = 0; i< t; ++i)
               cout<<todos[i].name<<endl;
          
     }
     
     return 0;
}
