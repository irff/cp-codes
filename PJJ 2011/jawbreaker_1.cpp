#include <algorithm>
#include <cstdio>
using namespace std;

int bar, kol, nilai=0, now = 0;
int m[100][100];

void dfs(int a, int b) {
    if(a >= 0 and a<bar and b>=0 and b<kol and m[a][b] == now) {
        nilai++;
        m[a][b]=-1;
        dfs(a-1, b);
        dfs(a, b+1);
        dfs(a+1, b);
        dfs(a, b-1);
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    for(int i=0;i<bar;i++) for(int j=0;j<kol;j++) scanf("%d", &m[i][j]);
    int px,py;
    scanf("%d%d", &px, &py);
    now = m[px][py];
    dfs(px,py);
    printf("%d\n", nilai*(nilai-1));
    return 0;
}
