#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int m[200][200],dist[200][200];
int x,y,hasil,bar,kol;

typedef pair<int,int> PII;
typedef pair<PII, int> PIII;

queue<PIII> q;

void trywalk(int a, int b, int c) {
    if(a>=0 and a<bar and b>=0 and b<kol and m[a][b]!=-1) {
        m[a][b]=-1;
        dist[a][b]=c;
        q.push(PIII(PII(a,b),c));
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) R(j,0,kol) scanf("%d", &m[i][j]);
    scanf("%d%d", &x, &y);
    q.push(PIII(PII(x-1,y-1),0));
    R(i,0,bar) R(j,0,kol) dist[i][j]=2000111222;
    
    while(!q.empty()) {
        printf("y");
        PIII TOP = q.front();
        q.pop();
        trywalk(TOP.first.first-1,TOP.first.second,TOP.second+1);
        trywalk(TOP.first.first,TOP.first.second+1,TOP.second+1);
        trywalk(TOP.first.first+1,TOP.first.second,TOP.second+1);
        trywalk(TOP.first.first,TOP.first.second-1,TOP.second+1);
    }
    
    int mins=2000111222;
    R(i,0,bar) if(dist[i][0] < mins) mins=dist[i][0];
    R(i,0,kol) if(dist[0][i] < mins) mins=dist[0][i];
    R(i,0,bar) if(dist[i][kol-1] < mins) mins=dist[i][kol-1];
    R(i,0,kol) if(dist[bar-1][i] < mins) mins=dist[bar-1][i];
    printf("%d\n", mins+1);
    return 0;
}
