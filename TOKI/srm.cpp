#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


const int INF = 2000111222;

string s;
int n;

int to_int(string s_in) {
    int num;
    istringstream(s_in) >> num;
    return num;
}


string to_string(int i_in) {
    ostringstream str;
    str << i_in;
    return str.str();
}

int main() {
    cin >> n;
    s = to_string(n);
    cout << s << endl;
    s = "912321";
    n = to_int(s);
    cout << n << endl;
    return 0;

}
