#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char m[100][100];
int teskes, bar, kol;
bool ada;
void dfs(int a, int b) {
     if( (a<0 or a>=bar or b < 0 or b>=bar) or m[a][b] == '#') return ;
     m[a][b] = '#';
     dfs(a-1,b);
     dfs(a,b+1);
     dfs(a+1,b);
     dfs(a,b-1);
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        ada = 0;
        scanf("%d%d", &bar, &kol);
        gets(m[0]);
        R(i,0,bar) gets(m[i]);
        R(i,0,bar) {
           if(m[i][0]==' ') dfs(i,0);
           if(m[i][kol-1]==' ') dfs(i,kol-1);
        }
        R(j,0,kol) {
            if(m[0][j]==' ') dfs(0,j);
            if(m[bar-1][j]==' ') dfs(bar-1, j);
        }
        R(i,0,bar) R(j,0,kol) if(m[i][j]==' ') ada=1;
        printf("%s\n", ada?"YA":"TIDAK");
    }

    return 0;
}
