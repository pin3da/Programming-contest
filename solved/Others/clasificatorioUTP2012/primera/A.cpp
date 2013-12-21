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
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(0)
#define MAXNODES 1000
#define MP 35

const double pi=acos(-1);

struct point{
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
};

bool isvoc(char c){
    if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return 1;
    return 0;
}

char array[MP][MP];

int main(){
    string c1,c2;
    cin>>c1>>c2;
    int s1 = c1.size();
    int s2 = c2.size();
    int m,p;
    int pin=1;
    For(i,s1){
        For(j,s2){
            if(c1[i]==c2[j]){
                if(pin){
                    m=i;
                    p=j;
                    pin=0;
                }
            }
        }
    }
    For(i,MP)
        For(j,MP)
            array[i][j]='.';

    For(i,s1)
        array[p][i]=c1[i];

    For(i,s2)
        array[i][m]=c2[i];

    For(i,s2){
        For(j,s1)
            cout<<array[i][j];
        cout<<endl;
    }
    return 0;
}
