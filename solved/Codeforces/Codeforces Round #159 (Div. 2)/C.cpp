// http://codeforces.com/contest/257/problem/C

using namespace std;
#include<bits/stdc++.h>

const double pi = acos(-1);

double my_atan2(int y, int x){
    double ans = atan2(y,x);
    if(ans < 0) ans += 2*pi;
    return ans;
}

double solve(){
    int n;
    cin>>n;
    vector<double> angles(n);
    for(int i = 0; i< n; ++i){
        int x,y;cin>>x>>y;
        angles[i] = my_atan2(y,x);
    }
    sort(angles.begin(),angles.end());
    double ans = angles[n-1] - angles[0];
    
    for(int i = 0; i< n-1; ++i)
        ans =  min(ans, 2*pi - (angles[i+1]-angles[i]));
    
    return ans*180/pi; 
}

int main (){
    printf("%.8lf\n",solve());
    return 0;
}