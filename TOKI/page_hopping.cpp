#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 10222;

int a, b, kasus = 0;
int adj[102][102], V;
int main() {
    while(scanf("%d%d", &a, &b),a,b) {
        V = 0;
        R(i,1,101) R(j,1,101) adj[i][j] = INF;
        adj[a][b] = 1;
        V = max(V, max(a,b));
        while(scanf("%d%d", &a, &b),a,b) {
            V = max(V, max(a,b));
            adj[a][b] = 1;
        }
        
        /*
        R(i,1,V+1) {
            R(j,1,V+1) printf("%d ", adj[i][j]);
            printf("\n");
        }*/
        R(k,1,V+1) {
            R(i,1,V+1) {
                R(j,1,V+1) {
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        /*
        R(i,1,V+1) {
            R(j,1,V+1) printf("%d ", adj[i][j]);
            printf("\n");
        }*/
        int sum = 0, ctr = 0;
        R(i,1,V+1) {
          R(j,1,V+1) {
              if(i!=j and adj[i][j]<INF) {
                  ctr++, sum+=adj[i][j];
              }
          }
        }
        //printf("%d %d\n", sum, ctr);
        printf("Case %d: average length between pages = %.3lf clicks\n", ++kasus, (double)sum/ctr);
    }
    return 0;
}
