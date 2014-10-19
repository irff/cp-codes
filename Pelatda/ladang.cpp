#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;
const int MOD = 1000000007;
typedef long long LLD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIE;

char m[1009][1009], sampah[100];
int dist[1009][1009], memo[1009][1009], n, nbatu;

queue<PIE> q;

void trywalk(int a, int b, int c) {
    if( a>=0 and a<n and b>=0 and b<n and m[a][b]!='#') {
        m[a][b] = '#';
        dist[a][b] = c;
        q.push(PIE(PII(a,b),c));
    }
}

void bfs() {
    q.push(PIE(PII(0,0),0));
    dist[0][0] = 0;
    m[0][0] = '#';
    while(!q.empty()) {
        PIE t = q.front(); q.pop();
        trywalk(t.first.first-1, t.first.second, t.second+1);
        trywalk(t.first.first, t.first.second+1, t.second+1);
        trywalk(t.first.first+1, t.first.second, t.second+1);
        trywalk(t.first.first, t.first.second-1, t.second+1);
    }
}

LLD trace(int a, int b) {
    if(memo[a][b]==0) {
      if(a==n-1 and b==n-1) return memo[a][b] = 1;
      int now = dist[a][b];
      LLD result = 0;
      if(a>0 and dist[a-1][b] == now+1) result += trace(a-1,b);
      if(b<n-1 and dist[a][b+1] == now+1) result += trace(a,b+1);
      if(a<n-1 and dist[a+1][b] == now+1) result += trace(a+1,b);
      if(b>0 and dist[a][b-1] == now+1) result += trace(a,b-1);
      
      return memo[a][b] = result%MOD;
    }
    return memo[a][b];
}

int main() {
    gets(sampah);
    memset(m, '.', sizeof m);
    scanf("%d%d", &n, &nbatu);
    R(i,0,nbatu) {
        int pa, pi;
        scanf("%d%d", &pa, &pi);
        m[pa-1][pi-1] = '#';
    }
    R(i,0,n) R(j,0,n) dist[i][j] = INF;
    bfs();
    //R(i,0,n) R(j,0,n) printf("%d%c", dist[i][j], (j==n-1)?'\n':' ');
    LLD hasil = trace(0,0);
    printf("%lld\n", hasil);
    return  0;
}
