/*
ID: manuel.5
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdio>


using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}

