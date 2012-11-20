using namespace std;
#include<cmath>
#include<vector>
#include<iostream>

struct pol{
    int grad;
    vector<int> coef;
    pol(int g):grad(g){
        coef.clear();
    }
    
    double eval(double x){
        double ans=0;
        for(int i=0;i<=grad;++i)
            ans+=power(x,i)*coef[i];
        return ans;
    }
};

int main(){
    

}
