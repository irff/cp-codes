#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 20222;

int adj[21][21], kasus = 0;
int main() {
    int n, a, b, Q = 0;
    while(scanf("%d", &n) == 1) {
        R(i,1,21) {
            R(j,1,21) adj[i][j] = INF;
            adj[i][i] = 0;
        }
        R(i,0,n) {
            scanf("%d", &a);
            adj[1][a] = 1;
            adj[a][1] = 1;
        }
        R(i,2,20) {
            scanf("%d", &n);
            R(j,0,n) {
                scanf("%d", &a);
                adj[i][a] = 1;
                adj[a][i] = 1;
            }
        }
        R(k,1,21) {
            R(i,1,21) {
                R(j,1,21) {
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        scanf("%d", &Q);
        printf("Test Set #%d\n", ++kasus);
        R(i,0,Q) {
            scanf("%d%d", &a, &b);
            printf("%2.d to %2.d:%2.d\n", a, b, adj[a][b]);
        }
        printf("\n");
    }
    return 0;
}
