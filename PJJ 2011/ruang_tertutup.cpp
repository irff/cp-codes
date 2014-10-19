#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar, kol;
char ori[300][300], m[1200][1200];

void dfs(int a, int b) {
    if(a>=0 and a<bar and b>=0 and b<kol and m[a][b]=='.') {
        m[a][b]='#';
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
    }
}
int main() {
    scanf("%d%d", &bar, &kol);
    memset(m, '.', sizeof m);
    R(i,0,bar) scanf("%s", &ori[i]);
    R(i,0,bar) {
        R(j,0,kol) {
            if(ori[i][j]=='/') {
                m[3*i][3*j+2]='#';
                m[3*i+1][3*j+1]='#';
                m[3*i+2][3*j]='#';
            } else if(ori[i][j]=='\\') {
                m[3*i][3*j]='#';
                m[3*i+1][3*j+1]='#';
                m[3*i+2][3*j+2]='#';
            }
        }
    }
    bar=bar*3; kol=kol*3;
    R(i,0,bar) {
        if(m[i][0]=='.') dfs(i,0);
        if(m[i][kol-1]=='.') dfs(i,kol-1);
    }
    R(j,0,kol) {
        if(m[0][j]=='.') dfs(0,j);
        if(m[bar-1][j]=='.') dfs(bar-1,j);
    }
    int hasil = 0;
    R(i,0,bar) R(j,0,kol) if(m[i][j]=='.') dfs(i,j),hasil++;
    printf("%d\n", hasil);
    return 0;
}
