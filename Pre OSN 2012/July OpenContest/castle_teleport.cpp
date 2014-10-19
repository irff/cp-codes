#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int n, k;
int a[100200][11];
bool udah[100200];
int dist[100200];
//           vertex, second
typedef pair<int,int> PII;
queue<PII> q;
int main() {
    for(int i=0; i<=100002; i++) dist[i]=2000111222;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }
    q.push(PII(0,0));
    udah[0]=1;
    dist[0]=0;
    while(!q.empty()) {
        PII t = q.front(); q.pop();
        for(int i=0; i<k; i++) {
            int next = a[t.first][ (t.second+i)%k];
            if(dist[ next ] > t.second+i+1) {
                dist[ next ] = t.second+i+1;
                q.push(PII(next,t.second+i+1));
            }
        }
    }
    printf("%d\n", dist[n-1]);
    return 0;
}
