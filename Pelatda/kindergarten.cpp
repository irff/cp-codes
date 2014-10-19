#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[100111];
int main() {
    while(gets(s) > 0) {
        int len = strlen(s);
        int state = 0, ans = 0;
        R(i,0,len) {
            if(state == 0 and isalpha(s[i])) {
                ans++;
                state = 1;
            } else {
                if(!isalpha(s[i])) {
                    state = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
