#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
typedef map<string,int> MSI;
MSI m;
string s[10000];
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        cin >> s[i];
        string x = s[i];
        sort(x.begin(), x.end());
        m[x]++;
    }

    int maks = 0;
    for(MSI::iterator it = m.begin(); it!=m.end(); it++) {
        if( it->second > maks) {
            maks = it-> second;
        }
    }
    if(maks == 1) printf("TIDAK ADA\n");
    else {
         printf("%d\n", maks);
         sort(s, s+n);
         bool udah = 0;
         string x = "";    
         R(i,0,n) {
             string tmp = s[i];
             sort(tmp.begin(), tmp.end());
        
             if( !udah) {    
                if(m[ tmp ] == maks) {
                      x = tmp;
                      udah = 1;
                }
            }
         
            if(udah) {
                if(tmp == x) {
                    printf("%s\n", s[i].c_str());
                }
            }
        }
    }

    return 0;
}
