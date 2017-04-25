// http://codeforces.com/contest/231/problem/D

using namespace std;
#include<iostream>

int main(){
    int x,y,z;
    int xx,yy,zz;
    int ans=0;
    cin>>x>>y>>z>>xx>>yy>>zz;
    int planes[6];
    for(int i=0;i<6;i++)
        cin>>planes[i];
    ans +=(x<0)?planes[4]:0;
    ans +=(y<0)?planes[0]:0;
    ans +=(z<0)?planes[2]:0;
    ans +=(x>xx)?planes[5]:0;
    ans +=(y>yy)?planes[1]:0;
    ans +=(z>zz)?planes[3]:0;
    cout<<ans<<endl;
}
