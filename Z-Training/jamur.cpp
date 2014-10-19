#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define PII pair<int,int>
#define f first
#define s second
char a[200][200];
int bar,kol,npulau;
int mus[10000];
queue<PII> q;
void dfs(int i,int j){
    if(i>=0 and i<bar and j>=0 and j<kol and a[i][j]!='#'){
        if(a[i][j]=='G') mus[npulau]++;
        a[i][j]='#';
        q.push(PII(i,j));
    }
}
void sam(int i,int j){
    q.push(PII(i,j));
    if(a[i][j]=='G') mus[npulau]++;
    a[i][j]=0;
    while(!q.empty()){
        PII t=q.front(); q.pop();
        dfs(t.f-1,t.s);
        dfs(t.f,t.s+1);
        dfs(t.f+1,t.s);
        dfs(t.f,t.s-1);      
    }
}
int main(){
    int maks=0;
    scanf("%d%d", &bar,&kol);
    R(i,0,bar) scanf("%s", &a[i]);
    R(x,0,bar) R(y,0,kol) if(a[x][y]!='#') { npulau++; sam(x,y); }
    for(int i=0; i<=npulau; i++) maks=max(mus[i],maks);
    printf("%d\n%d\n", maks,npulau);
    scanf("\n");
    return 0;
}
