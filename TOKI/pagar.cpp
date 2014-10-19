#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define PII pair<int,int>
#define PIII pair<int,PII>
#define x first
#define y second
vector<PII> p;
queue<PIII> q;
int w,h,teskes,jarak;

char m[500][500],me[500][500];
int da[500][500],db[500][500],bar,kol;
void tw(int a,int b,int c){
    if(b>=0 and b<bar and c>=0 and c<kol and m[b][c]==' '){
        m[b][c]='X';
        da[b][c]=a;
        q.push( PIII(a,PII(b,c)) );
    }
}
void bfsa(int a,int b){
    q.push(PIII(0,PII(a,b)));
    m[a][b]='X';
    while(!q.empty()){
        PIII t=q.front(); q.pop();
        tw( t.x+1,t.y.x-1,t.y.y );
        tw( t.x+1,t.y.x,t.y.y+1 );
        tw( t.x+1,t.y.x+1,t.y.y );
        tw( t.x+1,t.y.x,t.y.y-1 );
    }
}
void tw2(int a,int b,int c){
    if(b>=0 and b<bar and c>=0 and c<kol and me[b][c]==' '){
        me[b][c]='X';
        db[b][c]=a;
        q.push( PIII(a,PII(b,c)) );
    }
}
void bfsb(int a,int b){
    q.push(PIII(0,PII(a,b)));
    me[a][b]='X';
    while(!q.empty()){
        PIII t=q.front(); q.pop();
        tw2( t.x+1,t.y.x-1,t.y.y );
        tw2( t.x+1,t.y.x,t.y.y+1 );
        tw2( t.x+1,t.y.x+1,t.y.y );
        tw2( t.x+1,t.y.x,t.y.y-1 );
    }
}
int main(){
    scanf("%d", &teskes);
    while(teskes--){
         p.clear();
         jarak=-999;
         memset(da,0,sizeof da);
         memset(db,0,sizeof db);
         memset(m,'\0',sizeof m);
         memset(me,'\0',sizeof me);
         scanf("%d%d", &w, &h);
         bar=2*h+1;kol=2*w+1;
         //input
         gets(m[0]);
         R(i,0,bar){
             gets(m[i]);
         }
         R(i,0,bar) R(j,0,kol) me[i][j]=m[i][j];
         //cari jalan keluar
         R(i,0,kol) if(m[0][i]==' ') p.push_back(PII(0,i));
         R(i,0,kol) if(m[bar-1][i]==' ') p.push_back(PII(bar-1,i));
         R(i,0,bar) if(m[i][0]==' ') p.push_back(PII(i,0));
         R(i,0,bar) if(m[i][kol-1]==' ') p.push_back(PII(i,kol-1));
         //proses
         bfsa(p[0].x,p[0].y);
         bfsb(p[1].x,p[1].y);
         /*R(i,0,bar) {
             R(j,0,kol) printf("%d ", da[i][j]);
             puts("");
         }
         R(i,0,bar) {
             R(j,0,kol) printf("%d ", db[i][j]);
             puts("");
         }*/
         
         // cari terjauh
         R(i,0,bar) R(j,0,kol) jarak=max(jarak,min(da[i][j],db[i][j]));
         printf("%d\n", (jarak+1)/2);
    }
    return 0;
}
