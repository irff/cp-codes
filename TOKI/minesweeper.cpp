#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar, kol, kasus = 1; 
char s[120][120];
int main() {
    while(scanf("%d%d", &bar, &kol), bar and kol) {
        memset(s, 0, sizeof s);
        if(kasus > 1) printf("\n");
        R(i,0,bar) {scanf("%s", &s[i]); R(j,0,kol) if(s[i][j]=='.') s[i][j] = '0';}
        R(i,0,bar) R(j,0,kol) {
            if(s[i][j]=='0') {
              if(s[i-1][j-1]=='*') s[i][j]++;
              if(s[i-1][j]=='*') s[i][j]++;
              if(s[i-1][j+1]=='*') s[i][j]++;
              if(s[i][j+1]=='*') s[i][j]++;
            
              if(s[i+1][j+1]=='*') s[i][j]++;
              if(s[i+1][j]=='*') s[i][j]++;
              if(s[i+1][j-1]=='*') s[i][j]++;
              if(s[i][j-1]=='*') s[i][j]++;
            }
        }
        printf("Field #%d:\n", kasus);
        R(i,0,bar) printf("%s\n", s[i]);
        kasus++;
    }
    return 0;
}
