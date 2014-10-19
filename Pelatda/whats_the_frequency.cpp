#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[100111];
int m[300];
int main() {
    while( gets(s) > 0 ) {
        int len = strlen(s);
        memset(m, 0, sizeof m);
        R(i,0,len) {
            if(isalpha(s[i])) {
                m[s[i]]++;
            }
        }
        int maks = -1;
        R(i,0,300) if(m[i] >= maks) maks = m[i];
        R(i,0,300)if(m[i] == maks)  printf("%c", i);
        printf(" %d\n", maks);
    }
    return 0;
}
