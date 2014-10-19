#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 32000;
const int MOD = 1000000007;
typedef long long LLD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIE;

char m[1009][1009], sampah[100];
int memo[1009][1009], n, nbatu;
int dist[1009][1009];
queue<PIE> q;
/*
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

int trace(int a, int b) {
    if(memo[a][b]==-1) {
      if(a==n-1 and b==n-1) return memo[a][b] = 1;
      int now = dist[a][b];
      int result = 0;
      if(a>0 and dist[a-1][b] == now+1) result = (result+trace(a-1,b))%MOD;
      if(b<n-1 and dist[a][b+1] == now+1) result = (result+trace(a,b+1))%MOD;
      if(a<n-1 and dist[a+1][b] == now+1) result = (result+trace(a+1,b))%MOD;
      if(b>0 and dist[a][b-1] == now+1) result += (result+trace(a,b-1))%MOD;
      
      return memo[a][b] = result%MOD;
    }
    return memo[a][b];
}
*/
int main() {
    gets(sampah);
    scanf("%d%d", &n, &nbatu);
    R(i,0,nbatu) {
        int xa, xi;
        scanf("%d%d", &xa, &xi);
        m[xa-1][xi-1] = '#';
    }
    /*
    if(m[0][0]=='#') printf("0\n");
    else {
      R(i,0,n) R(j,0,n) dist[i][j] = INF;
      bfs();
      memset(memo, -1, sizeof memo);
      //R(i,0,n) R(j,0,n) printf("%d%c", dist[i][j], (j==n-1)?'\n':' ');
      int hasil = trace(0,0);
      printf("%d\n", hasil);
    }
    */
    return 0;
}
