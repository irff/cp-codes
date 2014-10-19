#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define fs first
#define sc second

typedef pair<int,int> PII;
typedef pair<PII, int> PIII;

int a=150,b=150,dist[300][300];
char s[200], m[300][300];
queue< PIII > q;

void tw(int a, int b, int c) {
    if(m[a][b]=='.') {
        dist[a][b]=c;
        q.push(PIII(PII(a,b),c));
    }
}

int main() {
    int maksa=-1,maksi=-1,mina=1000,mini=1000;
    memset(m, '#', sizeof m);
    scanf("%s", &s);
    int len = strlen(s);
    m[a][b]='.';
    for(int i=0; i<len; i++) {
        if(s[i]=='U') a--;
        if(s[i]=='R') b++;
        if(s[i]=='D') a++;
        if(s[i]=='L') b--;
        maksa = max(a,maksa);
        maksi = max(b,maksi);
        mina = min(a,mina);
        mini = min(b,mini);
        m[a][b]='.';
    }
    /*for(int i=mina-1; i<=maksa+1; i++) {
        for(int j=mini-1; j<=maksi+1; j++) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }*/
    q.push(PIII(PII(150,150),0));
    while(!q.empty()) {
        PIII t = q.front(); q.pop();
        m[t.fs.fs][t.fs.sc]='~';
        tw(t.fs.fs-1, t.fs.sc, t.sc+1);
        tw(t.fs.fs, t.fs.sc+1, t.sc+1);
        tw(t.fs.fs+1, t.fs.sc, t.sc+1);
        tw(t.fs.fs, t.fs.sc-1, t.sc+1);
    }
    int shortest = dist[a][b];
    if(dist[a][b]==len) printf("OK\n");
    else printf("BUG\n");
    return 0;
}
