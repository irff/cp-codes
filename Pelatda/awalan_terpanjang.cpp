#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;
typedef map<string, VI> MVI;

MVI m;
int n;
string s[10111];

int main() {
    scanf("%d", &n);
    R(i,0,n) cin >> s[i];
    sort(s, s+n);
    R(i,0,n) {
        int len = s[i].length();
        string str = "";
        R(j,0,len) {
            str+=s[i][j];
            if(m[str].size() < 2) m[str].push_back(i);
        }
    }
    int ansa = 0, ansi = 0, maks = 0;
    for(MVI::iterator it = m.begin(); it!=m.end(); it++) {
        
        if(maks < it->first.length() and it->second.size() > 1) {
            ansa = it->second[0];
            ansi = it->second[1];
            maks = it->first.length();
        }
    }
    cout << s[ansa] << endl << s[ansi] << endl;

    return 0;
}
