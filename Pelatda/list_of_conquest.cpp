#include <cstdio>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef map<string, int> MSI;

int n;
string a, b, c;
MSI m;
int main() {
    scanf("%d", &n);
    getline(cin, b);
    while(n--) {
        getline(cin, b);
        int len = b.length();
        a = "";
        R(i,0,len) {
            if(b[i]==' ') break;
            a.push_back(b[i]);
        }
        m[a]++;
    }
    for(MSI::iterator it = m.begin(); it!=m.end(); it++) {
        cout << it->first << " " << it-> second << endl;
    }
    return 0;
}

