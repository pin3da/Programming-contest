using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include <cassert>
#include<queue>
#include<cmath>
#define MAXC 500000

typedef pair<int,int> pii;
typedef pair<double,pii> city;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cities, box,tmp;
    city tmp1;
    while(cin>>cities>>box){
        if(cities==-1 && box==-1)break;
        priority_queue<city> quq;
        for(int i=0;i<cities;i++){
            cin>>tmp;
            tmp1.first=tmp;
            tmp1.second.first=tmp;
            tmp1.second.second=1;
            quq.push(tmp1);
            box--;
        }
        while(box--){
            city tmp = quq.top();
            quq.pop();
            tmp.first = ((double)tmp.second.first)/(++tmp.second.second);
            quq.push(tmp);
        }
        cout<<ceil(quq.top().first)<<endl;
        
    }
    return 0;
}
