#include <cstdio>
#include <cstring>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char m[120][120];
int bar,kol;
int main() {
    scanf("%d%d", &bar,&kol);
    R(i,0,bar) scanf("%s", m[i]);
    R(i,0,bar) {
        R(j,0,kol) {
            if(m[i][j]!='*') {
                m[i][j]='0';
                if(m[i-1][j]=='*') m[i][j]++;
                if(m[i-1][j+1]=='*') m[i][j]++;
                if(m[i][j+1]=='*') m[i][j]++;
                if(m[i+1][j+1]=='*') m[i][j]++;
                if(m[i+1][j]=='*') m[i][j]++;
                if(m[i+1][j-1]=='*') m[i][j]++;
                if(m[i][j-1]=='*') m[i][j]++;
                if(m[i-1][j-1]=='*') m[i][j]++;
            }
        }
    }
    R(i,0,bar) printf("%s\n", m[i]);
}
