#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
int N, p[16000], w[16000], Q;
int main() {
    scanf("%d", &teskes);
    R(t,0,teskes) {
        scanf("%d", &N);
        R(i,0,N+1) p[i] = i;
        R(i,1,N+1) scanf("%d", &w[i]);
        R(i,0,N-1) {
            int na, ni;
            scanf("%d%d", &na, &ni);
            p[ni] = na;
        }
        scanf("%d", &Q);
        printf("Case #%d:\n", t+1);
        R(i,0,Q) {
            int start, maks, mins;
            scanf("%d%d%d", &start, &mins, &maks);
            int now = start, s = 0;
            bool bisa = 0;
            while(p[now] != now) {
                int parent = p[now];
                if(w[ parent ] >= mins and s+1 <= maks) {
                    now = parent; s++;
                } else {
                    break;
                }
            }
            if(now==start) {
                printf("-1 -1 -1\n");
            } else {
                printf("%d %d %d\n", now, w[now], s);
            }
        }
    }

    return 0;
}
