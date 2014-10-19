#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define PII pair<int,int>
#define PIII pair<int,PII>
#define x first
#define y second

int teskes,bar,kol,npulau;
char m[300][300];
queue<PII> q;
PII tmp;

void tw(int a,int b){
    if(a>=0 and a<bar and b>=0 and b<kol and m[a][b]=='#'){
        m[a][b]='.';
        q.push(PII(a,b));
    }
}

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        npulau=0;
        scanf("%d%d", &bar, &kol);
        for(int i=0; i<bar; i++) scanf("%s", &m[i]);
        for(int i=0; i<bar; i++)
         for(int j=0; j<kol; j++){
             if(m[i][j]=='#'){
                 npulau++;
                 q.push(PII(i,j));
                 m[i][j]='.';
                 while(!q.empty()){
                     PII t=q.front(); q.pop();
                     tw(t.x-1,t.y);
                     tw(t.x-1,t.y+1);
                     tw(t.x,t.y+1);
                     tw(t.x+1,t.y+1);
                     tw(t.x+1,t.y);
                     tw(t.x+1,t.y-1);
                     tw(t.x,t.y-1);
                     tw(t.x-1,t.y-1);
                 }
             }
         }
        printf("%d\n", npulau);
    }
    return 0;
}
