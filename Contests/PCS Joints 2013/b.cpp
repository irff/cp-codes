#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

char s[120000];
LLD ctr = 0, ans = 0;
int len = 0;
int main() {
    scanf("%s", &s);
    len = strlen(s);
    R(i,0,len) {
        if(s[i]=='4') ctr++;
        else ans += ctr;
    }
    printf("%lld\n", ans);
    return 0;
}
