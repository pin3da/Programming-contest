using namespace std;
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>

const int MD = 20;

double dfs(double x,double y,double s, int depth=0){
    if(depth == MD) return 0.0;
    double s3 = s/3.0;
    if(x >= s3 and x <= (s -s3) and y >= s3 and y <= (s -s3))
        return min(min(x-s3 , s-s3-x),min(y-s3 , s-s3-y));
    if(x > s3) x -= s3;
    if(x > s3) x -= s3;
    if(y > s3) y -= s3;
    if(y > s3) y -= s3;
    return dfs(x,y,s3,depth+1);
}


int main(){
    int s;
    double x,y;
    cout<< fixed << setprecision(6);
    while(cin>>s and s){
        cin>>x>>y;
        cout<<dfs(x,y,s)<<endl;
    }
    return 0;
}

