#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int MOD = 1000000007;
const int INF = 2000111222;
typedef pair<int,int> PII;
typedef pair<PII,int> PIE;

int dist[1009][1009], memo[1009][1009], hasil = 0;

char m[1009][1009];
string sampah;
int n, ladang;
//queue<PIE> q;

/*
int trace(int a, int b) {
    if(memo[a][b]==-1) {
      if(a==n-1 and b==n-1) return memo[a][b] = 1;
      int now = dist[a][b];
      int result = 0;
      if(a>0 and dist[a-1][b] == now+1) result = (result+trace(a-1,b))%MOD;
      if(b<n-1 and dist[a][b+1] == now+1) result = (result+trace(a,b+1))%MOD;
      if(a<n-1 and dist[a+1][b] == now+1) result = (result+trace(a+1,b))%MOD;
      if(b>0 and dist[a][b-1] == now+1) result = (result+trace(a,b-1))%MOD;
      
      return memo[a][b] = result%MOD;
    }
    return memo[a][b];
}

void tw(int a, int b, int c) {
    if( a>=0 and a < n and b>=0 and b < n and m[a][b]!='#') {
        q.push(PIE(PII(a,b),c));
        m[a][b] = '#';
        dist[a][b] = c;
    }
}
*/
int main() {
    getline(cin, sampah);
    //memset(m, '.', sizeof m);
    scanf("%d%d", &n, &ladang);
    R(i,0,ladang) {
        int xa, xi;
        scanf("%d%d", &xa, &xi);
        m[xa-1][xi-1] = '#';
    }
      //R(i,0,n+1) R(j,0,n+1) dist[i][j] = INF;
      
      //R(i,0,n+1) R(j,0,n+1) memo[i][j] = -1;
      
      //bfs
      //q.push(PIE(PII(0,0),0));
      //dist[0][0] = 0;
      //m[0][0] = '#';
      /*
      while(!q.empty()) {
          PIE t = q.front(); q.pop();
          tw(t.first.first-1, t.first.second, t.second+1);
          tw(t.first.first, t.first.second+1, t.second+1);
          tw(t.first.first+1, t.first.second, t.second+1);
          tw(t.first.first, t.first.second-1, t.second+1);
      }
      */
      //R(i,0,n) R(j,0,n) printf("%d%c", dist[i][j], (j==n-1)?'\n':' ');
      // = trace(0,0);
      
      //R(i,0,n) R(j,0,n) printf("%d%c", memo[i][j], (j==n-1)?'\n':' ');
      //printf("%d\n", hasil);
    
    return 0;
}
