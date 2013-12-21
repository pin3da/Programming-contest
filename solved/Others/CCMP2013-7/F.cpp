using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cassert>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>

#define For(i,n) for(int  i= 0 ; i<n;++i)
#define foreach(it,x) for(typeof x.begin() it =  x.begin(); it!= x.end(); ++it)
#define D(x) cout<< #x " = " <<(x)<<endl
#define MAXNODES 1010

map<string, int> code;

set<int> misma_u[MAXNODES];
vector<int> revisa[MAXNODES];
int num_rev[MAXNODES];
int problem_found[MAXNODES];
int universidad[MAXNODES];


int main(){
    int k, manes;
    while(cin>>k>>manes and k+manes){
        memset(num_rev,0,sizeof num_rev);
        memset(problem_found,0,sizeof problem_found);
        memset(universidad,0,sizeof universidad);
        
        For(i, MAXNODES){
             revisa[i].clear();
             misma_u[i].clear();
        }
        
        int index = 0;
        code.clear();
        For(i,manes){
            string name;
            cin>>name;
            if(code.count(name)==0) code[name] = index++;
            universidad[i] = code[name];
            int tmp;
            For(j,k){
                cin>>tmp;
                tmp--;
                For(mio,revisa[i].size())
                    if(tmp==revisa[i][mio])problem_found[tmp] = 1;
                
                num_rev[tmp]++;
                revisa[i].push_back(tmp);
            }
            misma_u[universidad[i]].insert(i);
        }
        For(i,manes)
            if(num_rev[i] != k)
                problem_found[i]=1;
            
        
        For(i,manes)
            For(j,k)
                if(misma_u[universidad[i]].count(revisa[i][j])>0) problem_found[revisa[i][j]] = 1;
            
        
        
        int ans = 0;
        For(i,manes){
            if(problem_found[i])ans++;
        }
        
        if(ans == 1){
            cout<<"1 PROBLEM FOUND"<<endl;
        }else if(ans > 1){
            cout<<ans<<" PROBLEMS FOUND"<<endl;
        }else{
            cout<<"NO PROBLEMS FOUND"<<endl;
        }
        
        
    }
        
    return 0;
}

