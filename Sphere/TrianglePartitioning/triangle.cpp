using namespace std;
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#define D(x) cout<< #x " = "<<(x)<<endl

vector<vector<double> > t;
const double eps = 1e-13;

bool cmp(double a, double b){
    return fabs(a-b) < eps;
}

bool similar(const vector<double> &t1, const vector<double> &t2){
  return (cmp (t1[0]/t2[0], t1[1]/t2[1]) && cmp(t1[1]/t2[1], t1[2]/t2[2]) && cmp(t1[2]/t2[2], t1[0]/t2[0] ));
}

void solve(vector<double> v){
    sort(v.begin(), v.end());

    double h = sqrt(2*v[1]*v[1] - v[2]*v[2] + 2*v[0]*v[0])/2.0; // Apollonius' theorem

    vector<vector<double> > h1(2,vector<double>(3));
    h1[0][0] = h1[1][0] = h;
    h1[0][1] = h1[1][1] = v[2]/2;
    h1[0][2] = v[0];
    h1[1][2] = v[1];
    sort(h1[0].begin(), h1[0].end());
    sort(h1[1].begin(), h1[1].end());

    for(int j = 0; j< 2; ++j){
        bool counted = false;
        for (int i = 0; i < t.size(); ++i)
            counted |= similar(h1[j], t[i]);
        
        if (!counted){
            t.push_back(h1[j]);
            solve(h1[j]);
        }
   }
}

int main(){
    int n;
    cin>>n;
    while(n--){
        t.clear();
        vector<double> triangle(3);
        for(int i = 0; i< 3; ++i)
            cin >> triangle[i];
        solve(triangle);
        cout<<t.size()<<endl;
    }
    return 0;
}
