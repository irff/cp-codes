#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
char s[100111];
int memo[1100][1100];

int rek(int a, int b) {
    if(a>b) return 0;
    if(a==b) return 1;
    if(memo[a][b]) return memo[a][b];
    int maks = 0;
    if(s[a]==s[b]) maks = max(maks, rek(a+1,b-1)+2);
    maks = max(maks, max(rek(a+1,b),rek(a,b-1)));
    return memo[a][b] = maks;
}

int main() {
    scanf("%d", &teskes);
    gets(s);
    while(teskes--) {
        memset(memo, 0, sizeof memo);
        gets(s);
        int len = strlen(s);
        R(i,0,len) if(s[i]>='A' and s[i] <='Z') s[i]=s[i]-'A'+'a';
        int ans = rek(0,len-1);
        printf("%d\n", ans);
    }
    return 0;
}
