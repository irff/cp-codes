#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define PII pair<int,int>
#define f first
#define s second
char a[1003][1003];

int wedhus=0,garangan=0;
int k,l;
int com,bar,kol,MAX;
queue<PII> q;
int main(){
    scanf("%d%d", &bar,&kol);
    R(i,0,bar) scanf("%s", &a[i]);
    int wt=0,gt=0;
    R(x,0,bar) R(y,0,kol) if(a[x][y]!='#') { 
      int i=x,j=y;
      wedhus=0,garangan=0;
      q.push(PII(i,j));
      if(a[i][j]=='o') wedhus++;
      else if(a[i][j]=='v') garangan++;
      a[i][j]='#';
      while(!q.empty()){
          com++;
          PII t=q.front(); q.pop();
          k=t.f-1,l=t.s;
          if(k>=0 and k<bar and l>=0 and l<kol and a[k][l]!='#'){
            if(a[k][l]=='o') wedhus++;
            else if(a[k][l]=='v') garangan++;
            a[k][l]='#';
            q.push(PII(k,l));
          }
          k=t.f,l=t.s+1;
          if(k>=0 and k<bar and l>=0 and l<kol and a[k][l]!='#'){
            if(a[k][l]=='o') wedhus++;
            else if(a[k][l]=='v') garangan++;
            a[k][l]='#';
            q.push(PII(k,l));
          }
          k=t.f+1,l=t.s;
          if(k>=0 and k<bar and l>=0 and l<kol and a[k][l]!='#'){
            if(a[k][l]=='o') wedhus++;
            else if(a[k][l]=='v') garangan++;
            a[k][l]='#';
            q.push(PII(k,l));
          }
          k=t.f,l=t.s-1;
          if(k>=0 and k<bar and l>=0 and l<kol and a[k][l]!='#'){
            if(a[k][l]=='o') wedhus++;
            else if(a[k][l]=='v') garangan++;
            a[k][l]='#';
            q.push(PII(k,l));
          }
      }
      if(wedhus>garangan) wt+=wedhus;
      else gt+=garangan;
    }
    printf("%d %d\n", wt,gt);
    scanf("\n");
    return 0;
}
