#include <cstdio>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char m[100][100];
int teskes, bar, kol;
bool banjir,aman;
void dfs(int a, int b) {
    if(a < 0 or a >= bar or b < 0 or b >= kol) banjir=1;
    if(a >=0 and a < bar and b >= 0 and b < kol and m[a][b]!='#') {
        m[a][b]='#';
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
    }
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        aman=0;
        scanf("%d%d\n", &bar, &kol);
        R(i,0,bar) gets(m[i]);
        R(i,0,bar) R(j,0,kol) {
            if(m[i][j]!='#'){
                banjir=0;
                dfs(i,j);
                if(!banjir) aman=1;
            }
        }
        printf("%s\n", (aman)?"YA":"TIDAK");
    }
    return 0;
}
