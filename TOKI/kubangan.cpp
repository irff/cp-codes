#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define PII pair<int,int>
#define PIII pair<int,PII>
#define x first
#define y second

int minx,miny,maxx,maxy,pa,pb,n,aa,bb,teskes,d[1001][1001];
char m[1001][1001];
queue<PIII> q;

void tw(int a,int b,int c){
    if(b>=minx and b<=maxx and c>=miny and c<=maxy and ( m[b][c]=='S' or m[b][c]=='.') ){
        d[b][c]=a;
        m[b][c]='X';
        q.push(PIII(a,PII(b,c)));
    }
}
void bfs(int a,int b){
     q.push(PIII(0,PII(a,b))); d[a][b]=0; m[a][b]='X';
     while(!q.empty()){
         PIII t=q.front(); q.pop();
         tw(t.x+1,t.y.x-1,t.y.y);
         tw(t.x+1,t.y.x,t.y.y+1);
         tw(t.x+1,t.y.x+1,t.y.y);
         tw(t.x+1,t.y.x,t.y.y-1);
     }
}

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        memset(m, '.', sizeof m);
        memset(d, 0, sizeof d);
        scanf("%d%d%d", &pa,&pb,&n);
        pa+=500;pb+=500;
        // set range
        minx=pa; maxx=pa;
        miny=pb; maxy=pb;
        // just 4 debug
        m[500][500]='*';
        m[pa][pb]='S';
        //input
        R(i,0,n){
            scanf("%d%d", &aa,&bb);
            minx=min(minx,aa+500); maxx=max(maxx,aa+500);
            miny=min(miny,bb+500); maxy=max(maxy,bb+500);
            m[aa+500][bb+500]='M';
        }
        // expanding range
        minx--; miny--; maxx++; maxy++;       
        /*R(i,minx,maxx+1){
           R(j,miny,maxy+1) printf("%c", m[i][j]);
           puts("");
        }*/
        // process
        bfs(500,500);
        /*R(i,minx,maxx+1){
           R(j,miny,maxy+1) printf("%d ", d[i][j]);
           puts("");
        }
        R(i,minx,maxx+1){
           R(j,miny,maxy+1) printf("%c", m[i][j]);
           puts("");
        }*/
        
        printf("%d\n", d[pa][pb]);
    }
    return 0;
}
