#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
char m[1002][1002];
int MAX,bar,kol,com;
void dfs(int a, int b){
    if(a>=0 and a<bar and b>=0 and b<kol and m[a][b]!='#'){
        com++;
        m[a][b]='#';
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
    }
}
int main(){
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) scanf("%s", &m[i]);
    R(i,0,bar) R(j,0,kol){
        com=0;
        dfs(i,j);
        MAX=max(com,MAX);
    }
    printf("%d\n", MAX);

    return 0;
}
