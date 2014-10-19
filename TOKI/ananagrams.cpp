#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<string,int> PSI;
typedef map<string,PSI> MSI;
MSI m;
string s;
vector<string> out;
int main() {
    while(cin >> s) {
        if(s == "#") break;
        int len = s.length();
        string ori = s;
        R(i,0,len) {
            if(s[i] >= 'A' and s[i] <= 'Z') s[i] = s[i]-'A'+'a';
        }
        sort(s.begin(), s.end());
        m[s].first = ori;
        m[s].second++;
    }
    for(MSI::iterator it = m.begin(); it!=m.end(); it++) {
        if(it->second.second == 1) out.push_back(it->second.first);
    }
    int len = out.size();
    sort(out.begin(), out.end());
    R(i,0,len) cout << out[i] << endl;
    return 0;
}
