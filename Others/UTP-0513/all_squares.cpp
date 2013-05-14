using namespace std;
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

typedef unsigned long long ll;


int solve(int x, int y,  int px, int py, int depth) {
        int len = depth * 2 + 1;
        int ans = 0;
        if (abs(px - x) <= len / 2 && abs(py - y) <= len / 2)
            ans++;
        if (depth == 1)
            return ans;
        return ans + solve(x + len / 2, y + len / 2,px , py ,depth/2) + solve(x + len / 2, y - len / 2,px , py ,depth/2)
                + solve(x - len / 2, y + len / 2,px , py ,depth/2) + solve(x - len / 2, y - len / 2,px , py ,depth/2);
    }

int main(){
    int a,b,c;
    while(cin>>c>>a>>b and a+b+c != 0){
        //cout<<solve(1024,1204,a,b,c)<<endl;
        printf("%3d\n",solve(1024, 1024,a,b,c));
    }
    return 0;
}
