#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, pos;
string s;

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        cin >> pos >> n >> s;
        R(i,0,n) {
            s = s.substr(pos).append(s);
        }
        cout << s << endl;
    }
    return 0;
}
