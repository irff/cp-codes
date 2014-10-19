#include <cstdio>
#include <cstring>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar, kol, deputy=0;
char m[200][200], dumm, pres;
bool udah[100];
void dfs(int a, int b) {
    if( a>=0 and a<bar and b>=0 and b<kol) {
        if(m[a][b]==pres) {
            m[a][b]='.';
            dfs(a-1,b);
            dfs(a,b+1);
            dfs(a+1,b);
            dfs(a,b-1);
        } else if(m[a][b] >='A' and m[a][b] <='Z') {
            udah[ m[a][b]-'A' ]=1;
            m[a][b]='.';
        }
    }
}

int main() {
    scanf("%d%d%c%c", &bar, &kol, &dumm, &pres);
    R(i,0,bar) {
        scanf("%s", &m[i]);
    }
    R(i,0,bar) R(j,0,kol)
        if(m[i][j]==pres) {
            dfs(i,j);
        }
    R(i,0,26) if( udah[i] ) deputy++;
    printf("%d\n", deputy);
    return 0;    
}
