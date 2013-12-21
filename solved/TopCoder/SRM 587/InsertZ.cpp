using namespace std;
#include<bits/stdc++.h>


class InsertZ {
	public:
	string canTransform(string init, string goal) {
	    string tmp;
	    for(int i = 0; i< goal.size(); ++i)
	        if(goal[i] != 'z') tmp += goal[i];
	        
	    if (tmp == init) return "Yes";
	    return "No";
	}
};
