// search algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main () {
  vector<int> myvector;
  vector<int>::iterator it;

  for (int i=1; i<10; i++) myvector.push_back(i*10);

  int match1[] = {40,50,60,70};
  it = search (myvector.begin(), myvector.end(), match1, match1+4);

  if (it!=myvector.end())
    cout << "match1 found at position " << int(it-myvector.begin()) << endl;
  else
    cout << "match1 not found" << endl;

  int match2[] = {20,30,50};
  it = search (myvector.begin(), myvector.end(), match2, match2+3);

  if (it!=myvector.end())
    cout << "match2 found at position " << int(it-myvector.begin()) << endl;
  else
    cout << "match2 not found" << endl;
  
  return 0;
}
