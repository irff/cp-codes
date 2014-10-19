#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n,nkondisi,maks,luastmp;
char kond;
char m[60][60];

void dfs(int a, int b) {
    if( a>=0 and a<n and b>=0 and b<n and m[a][b]!='#') {
        luastmp++;
        m[a][b]='#';
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
    }
}

int main() {
    scanf("%d %c%d", &n,&kond,&nkondisi);
    maks=-1;
    if(kond=='s') R(i,0,n) R(j,0,n) m[i][j]='#';
    else R(i,0,n) R(j,0,n) m[i][j]='.';
    R(i,0,nkondisi) {
        int a,b; scanf("%d%d", &a, &b);
        if(kond=='s') m[a-1][b-1]='.';
        else m[a-1][b-1]='#';
    }
    R(i,0,n) R(j,0,n) {
        luastmp=0;
        dfs(i,j);
        maks=max(maks,luastmp);
    }
    printf("%d\n", maks);
    return 0;
}
