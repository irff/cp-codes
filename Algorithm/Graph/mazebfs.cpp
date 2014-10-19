#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define PII pair<int,int>
#define f first
#define s second
char a[1003][1003];
int com,bar,kol,MAX;
queue<PII> q;
void bfs(int i,int j){
    if(i>=0 and i<bar and j>=0 and j<kol and a[i][j]!='#'){
        a[i][j]='#';
        q.push(PII(i,j));
    }
}

int main(){
    scanf("%d%d", &bar,&kol);
    R(i,0,bar) scanf("%s", &a[i]);
    R(x,0,bar) R(y,0,kol) if(a[x][y]!='#') { 
      int i=x,j=y;
      q.push(PII(i,j));
      a[i][j]='#';
      while(!q.empty()){
        com++;
        PII t=q.front(); q.pop();
        bfs(t.f-1,t.s);
        bfs(t.f,t.s+1);
        bfs(t.f+1,t.s);
        bfs(t.f,t.s-1);
      }
    }
    printf("%d\n", MAX);
    scanf("\n");
    return 0;
}
